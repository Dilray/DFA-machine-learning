#include "DFA.h"

int main() {
    DFA dfa;
    std::string input;
    char should_accept;

    while (true) {
        std::cout << "Введите строку (или 'exit' для выхода): ";
        std::getline(std::cin, input);
        if (input == "exit") break;

        std::cout << "Должна ли эта строка приниматься? (y/n): ";
        std::cin >> should_accept;
        std::cin.ignore(); // Игнорируем оставшийся символ новой строки

        if (should_accept == 'y') {
            dfa.add_string(input);
        }

        std::cout << "Текущий автомат:" << std::endl;
        dfa.print();
    }

    return 0;
}
