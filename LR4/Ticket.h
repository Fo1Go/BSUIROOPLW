#include <utility>

#include "Client.h"
#include "Flight.h"

//
// Created by prost on 13.02.2024.
//

#ifndef LR4_TICKET_H
#define LR4_TICKET_H

class Ticket {
private:
    int reservationTime = 10*60;
    Flight flight;
    Client person;
    bool is_paid = false;
public:
    Ticket() = default;
    Ticket(Flight flight, Client person) {
        this->flight = std::move(flight);
        this->person = std::move(person);
    }

    bool isPaid() {
        return this->is_paid;
    }

    void pay_the_bill(){
        this->is_paid = true;
    }

    bool isReservationOut() {
        if (this->is_paid) return false;
        return this->reservationTime <= 0;
    }

    void reservesionTimeDecrease(int time) {
        if (!this->is_paid) this->reservationTime -= time;
    }

    int getReservationTime() {
        return this->reservationTime;
    }

    void setReservationTime(int reservation) {
        this->reservationTime = reservation;
    }

    std::string toString() {
        return "(" + std::to_string(reservationTime) + ", "
               + flight.getFromPlace()+ ", "
               + flight.getToPlace() + ")" ;
    }
};

#endif //LR4_TICKET_H
