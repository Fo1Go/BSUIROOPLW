//
// Created by prost on 2/16/2024.
//
#include <bitset>

#ifndef LR3_CRYPTOGRAPHY_H
#define LR3_CRYPTOGRAPHY_H

class Crypto {
protected:
    constexpr static std::bitset<32> mask = std::bitset<32>(0b01010101010101010101010101010101);
public:
    static unsigned long long convert(unsigned long number) {
        std::bitset<32> encryptedInformation = std::bitset<32>(~number) ^ mask;
        return encryptedInformation.to_ullong();
    }
};

#endif //LR3_CRYPTOGRAPHY_H
