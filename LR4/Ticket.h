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
    Flight *flight;
    Client *person;
    int countTickets;
    bool is_paid;
public:
    Ticket() = default;
    Ticket(Flight *flight, Client *person, int countTickets) {
        this->setClient(person);
        this->setFlight(flight);

        this->countTickets = countTickets;
        this->is_paid = false;
    }
    Ticket(Client *person, Flight *flight, int countTickets) {
        this->setClient(person);
        this->setFlight(flight);
        this->countTickets = countTickets;
        this->is_paid = false;
    }

    int getCountTickets() {
        return this->countTickets;
    }

    void setCountTickets(int cntTickets) {
        this->countTickets = cntTickets;
    }

    void setFlight(Flight* flt) {
        this->flight = flt;
    }

    Flight* getFlight() {
        return this->flight;
    }

    void setClient(Client* prs) {
        this->person = prs;
    }

    Client* getClient() {
        return this->person;
    }

    bool getPaidStatus() {
        return this->is_paid;
    }

    void setPaidStatus(bool status){
        this->is_paid = status;
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
               + flight->getFromPlace()+ ", "
               + flight->getToPlace() + ")" ;
    }
};

#endif //LR4_TICKET_H
