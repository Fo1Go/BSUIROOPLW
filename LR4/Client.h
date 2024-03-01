//
// Created by prost on 13.02.2024.
//

#ifndef LR4_CLIENT_H
#define LR4_CLIENT_H

    class Client {
    private:
        std::string name;
        int age{};
        double account_balance{};
    public:
        Client(std::string name,
               int age,
               double account_balance) {
            this->name = std::move(name);
            this->age = age;
            this->account_balance = account_balance;
        }
        Client() : Client("undefined", 0, 0) {};

        void setAge(int age_in_years) {
            this->age = age_in_years;
        }

        int getAge() {
            return this->age;
        }

        void setBalance(double balance) {
            this->account_balance = balance;
        }

        double getBalance() {
            return this->account_balance;
        }
    };


#endif //LR4_CLIENT_H
