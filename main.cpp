#include "DFA.h"

int main() {
    setlocale(LC_ALL, "rus");
    DFA dfa;
    std::string input;
    char should_accept;

    // ��� �������� �������� ����� ��������
    // ������:  
    //   Transition: a -> 000001AF9C9542E0
    // State: 000001AF9C9542E0, is_final : 0

    // "Transition": a - ��� ������� �� ��������� "a", ��� "a" - ���� �� �������� �������� ������
    // "State: 000001AF9C9542E0" - ��� ����� ���������� ���������, � ������� ���������� �������. ����� ������ ������ ������
    // "is_final : 0" (��� ����� ���� "is_final : 1") - ��������� �� ��, �������� �� ��������� �����������

    while (true) {
        std::cout << "������� ������ (��� 'exit' ��� ������): ";
        std::getline(std::cin, input);
        if (input == "exit") break;

        std::cout << "������ �� ��� ������ �����������? (y/n): ";
        std::cin >> should_accept;
        std::cin.ignore(); // ���������� ���������� ������ ����� ������

        if (should_accept == 'y')
            dfa.add_string(input);
        
        std::cout << "������� �������:" << std::endl;
        dfa.print();
    }

    return 0;
}