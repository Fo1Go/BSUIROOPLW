#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using std::string, std::vector, std::cin, std::cout, std::endl, std::getline;

/*
    В приведенных ниже заданиях необходимо вывести внизу фамилию разработчика,
    дату получения задания, а также дату сдачи задания.
    Для работы с динамическим массивом вводить его с клавиатуры и необходимо использовать класс Vector
    и его стандартные методы. В заданиях на числа объект можно создавать в виде массива символов.
    Ввести n чисел с консоли (1-15 вариант добавлять новый элемент в начало списка, 16-30 – в конец списка).
    21. Вывести числа от 1 до k в виде матрицы N x N слева направо и сверху вниз.
*/

int main() {
    bool is_running = true;
    string user_input_s;
    cout << "Enter numbers through enter: " << endl;
    vector<string> user_input;
    while (is_running) {
        getline(cin, user_input_s);
        if (user_input_s.empty()) {
            is_running = false;
        } else {
            user_input.push_back(user_input_s);
        }
    }
    int matrix_size = std::ceil(std::sqrt(user_input.size()));
    cout << "Matrix size is " << matrix_size << endl;
    string symbol;
    for (int row = 0; row < matrix_size; row++) {
        for (int col = 0; col < matrix_size; col++) {
            if (user_input.size() > matrix_size * row + col) {
                symbol = user_input[matrix_size * row + col] + " ";
            } else {
                symbol = "- ";
            }
            cout << symbol;
        }
        cout << endl;
    }
    cout << "DEV: Usevalad Prastsiakou.\nTask received: 10.02.2024 12:35\nTask passed: 10.02.2024"
         << endl;
    return 0;
}
