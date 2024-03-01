#include <iostream>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <chrono>

class FlightService {
private:
    std::mutex mtx;
    std::unordered_map<std::string, int> flights;

public:
    FlightService() {}
    void reserveTicket(const std::string& flightNumber, int numTickets, int timeout) {
        std::lock_guard<std::mutex> lock(mtx);

        if (flights.find(flightNumber) == flights.end()) {
            std::cout << "Flight " << flightNumber << " does not exist." << std::endl;
            return;
        }

        if (flights[flightNumber] < numTickets) {
            std::cout << "Not enough free places to reserve." << std::endl;
            return;
        }

        flights[flightNumber] -= numTickets;
        std::cout << "Tickets " << flightNumber << " is reserved." << std::endl;

        std::thread timer([=]() {
            std::this_thread::sleep_for(std::chrono::seconds(timeout));
            std::lock_guard<std::mutex> lock(mtx);
            flights[flightNumber] += numTickets;
            std::cout << "Reservation " << flightNumber << " is out." << std::endl;
        });
        timer.detach();
    }

    void addFlight(const std::string& flightNumber, int numSeats) {
        std::lock_guard<std::mutex> lock(mtx);
        flights[flightNumber] = numSeats;
        std::cout << "Flight " << flightNumber << " added." << std::endl;
    }
};

int main() {
    FlightService service;

    service.addFlight("ABC123", 50);
    service.addFlight("DEF456", 30);
    int i = 0;
    while( i < 10) {
        std::thread user1([&]() { service.reserveTicket("ABC123", 3, 10); });
        std::thread user2([&]() { service.reserveTicket("ABC123", 2, 10); });
        std::thread user3([&]() { service.reserveTicket("DEF456", 5, 10); });
        user1.join();
        user2.join();
        user3.join();
        i++;
    }

    return 0;
}
