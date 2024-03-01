#include <iostream>
#include "File.h"

// Работа со строками. Чтение исходной строки осуществлять из текстового файла,
// для результирующей строки применить стандартный алгоритм шифрования и записать в файл.
// При выполнении следующих заданий для вывода результатов создавать новую директорию и файл средствами класса File.
// 21. В заданном тексте найти сумму всех встречающихся цифр.

using std::cout, std::cin, std::endl;

int main() {

    File file = File("text.txt");
    int sumAllDigits = file.findSumAllDigits();

    cout << "Result: " << sumAllDigits << endl;

    // Write encrypted information
    File outPutFile = File("output.txt");
    outPutFile.encryptToFile(sumAllDigits);

//    Read encrypted information
//    unsigned long long inforimation = outPutFile.decryptFile();
//    cout << inforimation << endl;

    return 0;
}
