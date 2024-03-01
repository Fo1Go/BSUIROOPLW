#include <iostream>
#include "File.h"

// Работа со строками. Чтение исходной строки осуществлять из текстового файла,
// для результирующей строки применить стандартный алгоритм шифрования и записать в файл.
// При выполнении следующих заданий для вывода результатов создавать новую директорию и файл средствами класса File.
// 21. В заданном тексте найти сумму всех встречающихся цифр.

using std::cout, std::cin, std::endl, std::string;

int main() {
    bool isRunning = true;
    int chooseCommand = -1;
    while (isRunning) {
        cout << "what you wanna do: \n"
             << "1. Sum all digit from file and encrypt to file\n"
             << "2. Read from file encrypted information\n"
             << "0. Exit\n";
        cin >> chooseCommand;
        if (chooseCommand == 0) {
            isRunning = false;
        } else if (chooseCommand == 1) {
            string fileNameToRead;
            cout << "Enter filename to read(/ for default): " << endl;
            cin >> fileNameToRead;
            if (fileNameToRead == "/") {
                fileNameToRead = "text.txt";
            }
            string fileNameToWrite;
            cout << "Enter filename to write(/ for default): " << endl;
            cin >> fileNameToWrite;
            if (fileNameToWrite == "/") {
                fileNameToWrite = "output.txt";
            }
            try {
                File fileToRead = File(fileNameToRead);
                int sumAllDigit = fileToRead.findSumAllDigits();
                cout << "Sum is equal: " << sumAllDigit << endl;
                File fileToWrite = File(fileNameToWrite);
                fileToWrite.encryptToFile(sumAllDigit);
            } catch (const char* error_message) {
                std::cout << error_message << std::endl;
            }
        } else if (chooseCommand == 2) {
            string fileNameToRead;
            cout << "Enter filename to read(/ for default): " << endl;
            cin >> fileNameToRead;
            if (fileNameToRead == "/") {
                fileNameToRead = "output.txt";
            }
            try {
                File fileToRead = File(fileNameToRead);
                unsigned long long sumAllDigit = fileToRead.decryptFile();
                cout << "Sum is equal: " << sumAllDigit << endl;
            } catch (const char* error_message) {
                std::cout << error_message << std::endl;
            }
        } else {
            cout << "Unknown command" << endl;
        }
    }
    return 0;
}
