//
// Created by prost on 13.02.2024.
//

#ifndef LR4_FLIGHT_H
#define LR4_FLIGHT_H

class Flight {
private:
    std::string airplane_name;
    std::string from_place;
    std::string to_place;
    int count_places_in_airplane{};
public:
    Flight(std::string airplane_name,
           std::string from_place,
           std::string to_place,
           int count_places_in_airplane) {
        this->airplane_name = std::move(airplane_name);
        this->from_place = std::move(from_place);
        this->to_place = std::move(to_place);
        this->count_places_in_airplane = count_places_in_airplane;
    }
    Flight() : Flight("undefined", "undefined", "undefined", 0) {}

    void setFromPlace(std::string place) {
        this->from_place = std::move(place);
    }

    std::string getFromPlace() {
        return this->from_place;
    }

    void setToPlace(std::string place) {
        this->from_place = std::move(place);
    }

    std::string getToPlace() {
        return this->to_place;
    }
};

#endif //LR4_FLIGHT_H
