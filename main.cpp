#include "Orderbook.h"
#include "DeribitAPI.h"
#include "WebSocketServer.h"

int main() {
    // Authenticate API
    AuthenticateAPI("client_id" YAMz418e , "client_secret" __JoLKYF145tkTCW0hz9FQd26OSwnbaHwiBaOx9Y9nE);

    // Start WebSocket Server
    StartWebSocketServer();

    // Test Orderbook Functions
    Orderbook orderbook;
    orderbook.AddOrder(/*params*/);
    return 0;
}
