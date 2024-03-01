#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include "Ticket.h"
#include "Client.h"
#include "Flight.h"

using std::cout, std::cin, std::endl, std::string, std::vector, std::thread;

// Разработать многопоточное приложение.
// Все сущности, желающие получить доступ к ресурсу, должны быть потоками.
//
// 21. Сервис покупки билетов. Имеется перечень рейсов на определенное направление.
// Пользователи совершают бронирование. Бронирование можно корректировать в сторону увеличения
// и уменьшения количества билетов. Бронирование действует 10 минут.
// Если не поступает оплата в течение этого времени, другой пользователь может забронировать эти же билеты.


void checkReservation(vector<Ticket> &tickets, int duration) {
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(duration));
        if (tickets.empty()) {
            return;
        }
        for (int index = 0; index < tickets.size(); index++) {
            tickets[index].reservesionTimeDecrease(duration);
            // cout << tickets[index].toString() << endl;
            if (tickets[index].isReservationOut()) {
                cout << "This ticket is out of reservation: " << tickets[index].toString() << endl;
                tickets.erase(tickets.begin() + index);
            }
        }
    }
}

thread create_new_thread(vector<Ticket> &allTickets, int &duration) {
    thread t([&]() { checkReservation(allTickets, duration); });
    return t;
}


int main() {
    vector<Client> allClients{Client("Usevalad", 18, 8 * 60),
                              Client("NN", 25, 12 * 60)
    };
    vector<Flight> allFlight{Flight("Boing 777889", "Minsk", "Astana", 122),
                             Flight("Boing 777889", "Minsk", "Astana", 122),
                             Flight("Boing 777889", "Kiev", "Moscow", 122),
                             Flight("Boing 777889", "Berlin", "Minsk", 122),
                             Flight("Boing 777889", "Copenhagen", "Minsk", 122),
                             Flight("Boing 777889", "Moscow", "Minsk", 122)
    };
    vector<Ticket> allTickets{
            Ticket(allFlight[0], allClients[0])
    };
    cout << "All tickets:" << endl;
    std::for_each(allTickets.begin(), allTickets.end(),
                  [](Ticket n) {
        cout << n.toString() << '\n';
    });
    int duration = 1;
    string userInput;
    thread t = create_new_thread(allTickets, duration);
    cout << "HELLO MY DEAR FRIEND!!!" << endl;
    while (true) {
        std::cin >> userInput;
        if (userInput == "/q") {
            break;
        }
    }
    t.detach();
    return 0;
}
