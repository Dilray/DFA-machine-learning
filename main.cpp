#include "DFA.h"

int main() {
    setlocale(LC_ALL, "rus");
    DFA dfa;
    std::string input;
    char should_accept;

    // для удобства объясняю вывод автомата
    // пример:  
    //   Transition: a -> 000001AF9C9542E0
    // State: 000001AF9C9542E0, is_final : 0

    // "Transition": a - это переход из состояния "a", где "a" - один из символов поданной строки
    // "State: 000001AF9C9542E0" - это адрес следующего состояния, в которое происходит переход. вывод адреса ячейки памяти
    // "is_final : 0" (или может быть "is_final : 1") - указывает на то, является ли состояние допускающим

    while (true) {
        std::cout << "Введите строку (или 'exit' для выхода): ";
        std::getline(std::cin, input);
        if (input == "exit") break;

        std::cout << "Должна ли эта строка приниматься? (y/n): ";
        std::cin >> should_accept;
        std::cin.ignore(); // игнорируем оставшийся символ новой строки

        if (should_accept == 'y')
            dfa.add_string(input);
        
        std::cout << "Текущий автомат:" << std::endl;
        dfa.print();
    }

    return 0;
}