#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include <json/json.h> 

class AuthManager {
public:
    // Constructor to initialize client ID and client secret
    AuthManager(const std::string& clientId, const std::string& clientSecret);

    // Method to get an access token
    std::string getAccessToken();

    // Method to make an authentication request
    bool makeAuthRequest(const std::string& grantType, const std::string& token = "");

private:
    std::string clientId;
    std::string clientSecret;
    std::string accessToken;

    // Mutex for thread-safety if needed
    std::mutex tokenMutex;
};

#endif // AUTHENTICATION_H
