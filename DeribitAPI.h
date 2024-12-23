#include "Orderbook.h"
#include "DeribitAPI.h"

// Example: Call PlaceOrder when an order is added
void Orderbook::AddOrder(const std::string& instrument, double quantity, double price, const std::string& order_type) {
    PlaceOrder(instrument, quantity, price, order_type);
    // Add additional logic if needed
}

// Example: Call GetOrderbook to fetch data
void Orderbook::FetchOrderbookData(const std::string& instrument) {
    std::string orderbook = GetOrderbook(instrument);
    std::cout << "Orderbook data: " << orderbook << std::endl;
}
