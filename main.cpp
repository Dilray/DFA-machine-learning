#include "DFA.h"

int main() {
    DFA dfa;
    std::string input;
    char should_accept;

    while (true) {
        std::cout << "������� ������ (��� 'exit' ��� ������): ";
        std::getline(std::cin, input);
        if (input == "exit") break;

        std::cout << "������ �� ��� ������ �����������? (y/n): ";
        std::cin >> should_accept;
        std::cin.ignore(); // ���������� ���������� ������ ����� ������

        if (should_accept == 'y') {
            dfa.add_string(input);
        }

        std::cout << "������� �������:" << std::endl;
        dfa.print();
    }

    return 0;
}
