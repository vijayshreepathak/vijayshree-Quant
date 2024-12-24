
 High-Performance Order Management System for Deribit Test

This repository contains the implementation of a high-performance order execution and market data management system for the [Deribit Test Platform](https://test.deribit.com/). The system is built in **C++** and focuses on low-latency performance, efficient order management, and real-time market data streaming.
 📋 Objective
The goal is to create a robust trading system that demonstrates advanced capabilities in order execution and real-time market data processing using WebSocket technology.



 🚀 Features

   Order Management
- Place Orders: Seamlessly create new orders.
- Modify Orders: Update existing orders.
- Cancel Orders: Cancel orders in real-time.
- Fetch Order Book: Retrieve live market order book data.
- View Positions: Monitor current market positions.

 Real-Time Market Data
- WebSocket Server: Stream continuous order book updates.
- Client Subscription: Allow clients to subscribe to selected symbols.
- Efficient Data Broadcasting: Optimized for low-latency streaming.

 Market Coverage
- Instruments: Spot, Futures, and Options.
- Scope: Supports all symbols available on the Deribit Test platform.

---

 🛠️ Technical Requirements
- **Language**: Implementation in C++ for optimal performance.
- **Low-Latency Design**: Designed to minimize latency for high-frequency trading.
- **Error Handling**: Comprehensive logging and error management.
- **WebSocket Server Implementation**:
  - Connection management.
  - Subscription handling for symbols.
  - Efficient message broadcasting.

---

 📈 Performance Analysis (Bonus Section)
**Latency Benchmarking**:
- Measured order placement latency.
- Evaluated WebSocket message propagation delay.
- Analyzed end-to-end trading loop efficiency.

**Optimization Techniques**:
- Memory management.
- Thread management.
- Network communication efficiency.
- Data structure selection.
- CPU optimization.

---

## 🧩 Project Structure
```
.
├── src/
│   ├── main.cpp          # Entry point for the system
│   ├── websocket.cpp     # WebSocket server implementation
│   ├── order_manager.cpp # Order management functions
├── include/
│   ├── websocket.h       # WebSocket headers
│   ├── order_manager.h   # Order management headers
├── benchmarks/
│   ├── latency_results.txt
│   ├── optimization_report.md
├── README.md             # Project documentation
└── LICENSE               # License information
```

---

## 🎯 Deliverables
1. **Source Code**: Fully functional, well-documented code.
2. **Video Demonstration**: Highlights functionality, performance benchmarks, and code explanation.
3. **Bonus Documentation** (if applicable):
   - Performance benchmarking report.
   - Optimization techniques and results.

---

## 📝 Getting Started
### **Prerequisites**
- C++ Compiler (GCC/Clang/MSVC)
- Deribit Test API Keys (obtain from [Deribit](https://test.deribit.com/))
- Basic knowledge of WebSocket servers and C++.

### **Installation**
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/deribit-order-management.git
   cd deribit-order-management
   ```
2. Compile the code:
   ```bash
   make
   ```
3. Run the system:
   ```bash
   ./order_management
   ```

---

## 👨‍💻 Usage
1. **Set up API Keys**: Add your API credentials in the configuration file (`config.h`).
2. **Run the WebSocket server**:
   ```bash
   ./websocket_server
   ```
3. **Start managing orders** via the CLI or integrated client.

---

## 🧪 Performance Insights
- **Order Placement Latency**: Reduced to under 10ms.
- **WebSocket Message Propagation Delay**: Optimized for high throughput.
- **Trading Loop Efficiency**: Minimal bottlenecks identified and addressed.

---

## 🏆 Achievements
- Designed a scalable and low-latency order management system.
- Benchmarked and optimized key system performance metrics.
- Gained expertise in API integration, C++ programming, and WebSocket technology.

---

## 📜 License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## 📬 Contact
For any queries or suggestions, feel free to reach out:
- **Email**: vijayshree9646@gmail.com
- **LinkedIn**: https://www.linkedin.com/in/vijayshreevaibhav
