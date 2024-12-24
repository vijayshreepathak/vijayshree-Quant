#include "Authentication.h"
#include <curl/curl.h> // For HTTP requests
#include <iostream>
#include <mutex>

// Constructor
AuthManager::AuthManager(const std::string& clientId, const std::string& clientSecret)
    : clientId(clientId), clientSecret(clientSecret) {}

// Method to get the access token
std::string AuthManager::getAccessToken() {
    std::lock_guard<std::mutex> lock(tokenMutex);
    return accessToken;
}

// Method to make an authentication request
bool AuthManager::makeAuthRequest(const std::string& grantType, const std::string& token) {
    Json::Value requestBody;
    requestBody["jsonrpc"] = "2.0";
    requestBody["id"] = 0;
    requestBody["method"] = "public/auth";
    requestBody["params"]["grant_type"] = grantType;
    requestBody["params"]["client_id"] = clientId;
    requestBody["params"]["client_secret"] = clientSecret;

    if (grantType == "refresh_token") {
        requestBody["params"]["refresh_token"] = token;
    }

    // Serialize the JSON request body to a string
    Json::StreamWriterBuilder writer;
    std::string requestString = Json::writeString(writer, requestBody);

    // Perform the HTTP POST request using libcurl
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.deribit.com/api/v2/public/auth");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestString.c_str());

        // Response handling
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void* contents, size_t size, size_t nmemb, std::string* userp) -> size_t {
            userp->append((char*)contents, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Execute the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "CURL error: " << curl_easy_strerror(res) << std::endl;
            curl_easy_cleanup(curl);
            return false;
        }

        curl_easy_cleanup(curl);
    }

    // Parse the response and extract the access token
    try {
        Json::CharReaderBuilder reader;
        Json::Value jsonResponse;
        std::string errs;

        std::istringstream stream(response);
        if (!Json::parseFromStream(reader, stream, &jsonResponse, &errs)) {
            throw std::runtime_error("Error parsing JSON response");
        }

        if (jsonResponse["result"].isMember("access_token")) {
            std::lock_guard<std::mutex> lock(tokenMutex);
            accessToken = jsonResponse["result"]["access_token"].asString();
            return true;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error processing response: " << e.what() << std::endl;
    }

    return false;
}
