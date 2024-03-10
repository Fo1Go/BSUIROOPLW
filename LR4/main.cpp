#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <random>
#include <mutex>
#include "Ticket.h"
#include "Client.h"
#include "Flight.h"

using std::cout, std::cin, std::endl, std::string, std::vector, std::thread, std::mutex;

mutex gMUTEX;
// Разработать многопоточное приложение.
// Все сущности, желающие получить доступ к ресурсу, должны быть потоками.
//
// 21. Сервис покупки билетов. Имеется перечень рейсов на определенное направление.
// Пользователи совершают бронирование. Бронирование можно корректировать в сторону увеличения
// и уменьшения количества билетов. Бронирование действует 10 минут.
// Если не поступает оплата в течение этого времени, другой пользователь может забронировать эти же билеты.

void checkPayment(vector<Ticket*> &tickets, int &duration) {
    std::random_device rd;
    std::mt19937 mt(rd());
    int timeToCheck = duration;
    Ticket *ticket;
    Client *client;
    Flight *flight;
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(timeToCheck));
        try {
//            gMUTEX.lock();
            std::uniform_int_distribution<int> isPaid(0, 1);
            if (tickets.empty()) {
                continue;
            }
            for (int index = 0; index < tickets.size(); index++) {
                ticket = tickets[index];
                client = ticket->getClient();
                flight = ticket->getFlight();
                if ((client->getBalance() - ticket->getCountTickets() * flight->getCostOneTicket()) > 0 &&
                    !ticket->getPaidStatus()) {
                    if (isPaid(mt)) {
                        cout << "Client - " << client->getName() << " is paid his ticket " << ticket->toString() << endl;
                        ticket->setPaidStatus(true);
                        client->setBalance(client->getBalance() - ticket->getCountTickets() * flight->getCostOneTicket());
                    }
                }
            }
//            gMUTEX.unlock();
        } catch (...) {
            cout << "ERROR!" << endl;
        }
    }

}

void checkReservation(vector<Ticket*> &tickets, int &duration) {
    Ticket *ticket;
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(duration));
        try {
//            gMUTEX.lock();
            if (tickets.empty()) {
                continue;
            }
            for (int index = 0; index < tickets.size(); index++) {
                ticket = tickets[index];
//                cout << ticket->toString() << endl;
                ticket->reservesionTimeDecrease(duration);
                if (ticket->isReservationOut()) {
                    cout << "This ticket is out of reservation: " << ticket->toString() << endl;
                    tickets.erase(tickets.begin() + index);
                }
            }
//            gMUTEX.lock();
        } catch (...) {
            cout << "ERROR!" << endl;
        }
    }
}

void checkInToReservation(int &time_in_reservation, vector<Ticket*> &tickets, vector<Client*> &clients,
                          vector<Flight*> &flights) {
    std::this_thread::sleep_for(std::chrono::seconds(time_in_reservation));

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> age(19, 55);
    std::uniform_real_distribution<double> money(5000, 50000);
    std::uniform_int_distribution<int> countTickets(1, 4);
    std::uniform_int_distribution<int> randomFlight(0, (int) (flights.size() - 1));
    double mn = money(mt);
    Client *client = new Client(std::to_string(mn), age(mt), mn);
    Ticket *ticket = new Ticket(flights[randomFlight(mt)], client, countTickets(mt));
    clients.emplace_back(client);
    tickets.emplace_back(ticket);
}

thread createThreadCheckPayment(vector<Ticket*> &tickets, int &duration) {
    thread t([&]() { checkPayment(tickets, duration); });
    return t;
}

thread createThreadCheckReservation(vector<Ticket*> &tickets, int &duration) {
    thread t([&]() { checkReservation(tickets, duration); });
    return t;
}

thread createThreadNewClient(int &timeToReservation, vector<Ticket*> &tickets, vector<Client*> &clients,
                             vector<Flight*> &flights) {
    thread t([&]() { checkInToReservation(timeToReservation, tickets, clients, flights); });
    return t;
}

void watchAllTickets(vector<Ticket*> &tickets) {
    cout << "All tickets:" << endl;
    std::for_each(tickets.begin(), tickets.end(),
                  [](Ticket* n) { cout << n->toString() << " Is paid?: " << n->getPaidStatus() << '\n'; });
}

void watchAllClients(vector<Client*> &clients) {
    cout << "All tickets:" << endl;
    std::for_each(clients.begin(), clients.end(),
                  [](Client* n) { cout << n->toString() << '\n'; });
}

int main() {
    vector<Client*> clients;
    vector<Flight*> flights{
        new Flight("Boing 777889", "Minsk", "Astana", 122, 1000),
        new Flight("Boing 777889", "Minsk", "Astana", 122, 1000),
        new Flight("Boing 777889", "Kiev", "Moscow", 122, 1000),
        new Flight("Boing 777889", "Berlin", "Minsk", 122, 1000),
        new Flight("Boing 777889", "Copenhagen", "Minsk", 122, 1000),
        new Flight("Boing 777889", "Moscow", "Minsk", 122, 1000)
    };
    vector<Ticket*> tickets;

    for (int i = 0; i < 10; i++) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(5, 60);
        int time = dist(mt);
        thread TUSER = createThreadNewClient(time, tickets, clients, flights);
        TUSER.detach();
    }

    int durationCheckReservation = 1;
    int durationCheckPayment = durationCheckReservation * 10;

    string userInput;
    thread t1 = createThreadCheckReservation(tickets, durationCheckReservation);
    thread t2 = createThreadCheckPayment(tickets, durationCheckPayment);

    cout << "Enter 1 to watch all tickets: " << endl;
    while (true) {
        std::cin >> userInput;
        if (userInput == "/q") {
            break;
        } else if (userInput[0] == '1') {
            watchAllTickets(tickets);
        } else if (userInput[0] == '2') {
            watchAllClients(clients);
        } else {
            cout << "Unknown command!" << endl;
        }
    }
    t1.detach();
    t2.detach();

        return 0;
    }
