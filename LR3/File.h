//
// Created by prost on 15.02.2024.
//
#include <fstream>
#include <string>
#include "Cryptography.h"

#ifndef LR3_FILE_H
#define LR3_FILE_H
class File {
public:
    std::string FILENAME = "D:\\information\\university\\OOP\\LR3\\";
    std::fstream file;

    void close() {
        (this->file).close();
    }

    bool is_open() {
        return (this->file).is_open();
    }

    void open(std::_Ios_Openmode openType) {
        (this->file).open(this->FILENAME, openType);
    }

    File() : File("text.txt") { }

    File(std::string fn) {
        this->FILENAME += fn;
    }

    void encryptToFile(unsigned long information) {
        if (!this->is_open()) {
            this->open(std::ios::out);
        }

        unsigned long encryptedInformation = Crypto::convert(information);

        (this->file) << encryptedInformation;

        this->close();
    }

    unsigned long long decryptFile() {
        if (!this->is_open()) {
            this->open(std::ios::in);
        }
        std::string fileContent;
        char chr;
        while (this->file.get(chr)) {
            fileContent += chr;
        }

        unsigned long long encryptedInforamtion = Crypto::convert(std::stoul(fileContent));

        this->close();
        return encryptedInforamtion;
    }

    int findSumAllDigits() {
        if (!this->is_open()) {
            this->open(std::ios::in);
        }
        int sumAllDigits = 0;
        std::string line;
        char chr;
        while (this->file.get(chr)) {
            if (chr >= '0' && chr <= '9') {
                sumAllDigits += chr - '0';
            }
        }
        this->close();
        return sumAllDigits;
    }
};
#endif //LR3_FILE_H
