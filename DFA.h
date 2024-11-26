#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>

class DFA {
private:
    struct State {
        std::unordered_map<char, State*> transitions;
        bool is_final = false;
    };

    State* start_state;
    std::set<State*> all_states;

public:
    DFA() {
        start_state = new State();
        all_states.insert(start_state);
    }

    void add_string(const std::string& str) {
        State* current_state = start_state;

        for (char ch : str) {
            if (current_state->transitions.find(ch) == current_state->transitions.end()) {
                // ������� ����� ���������, ���� �������� ���
                State* new_state = new State();
                current_state->transitions[ch] = new_state;
                all_states.insert(new_state);
            }
            current_state = current_state->transitions[ch];
        }
        current_state->is_final = true; // ������������� ������� ��������� ��� ���������
    }

    bool accepts(const std::string& str) const {
        State* current_state = start_state;

        for (char ch : str) {
            if (current_state->transitions.find(ch) == current_state->transitions.end()) {
                return false; // �������� ���, ������ �� �����������
            }
            current_state = current_state->transitions.at(ch);
        }
        return current_state->is_final; // ���������, �������� �� ������� ��������� ���������
    }

    void print() const {
        std::cout << "States: " << all_states.size() << std::endl;
        for (const auto& state : all_states) {
            std::cout << "State: " << state << ", is_final: " << state->is_final << std::endl;
            for (const auto& transition : state->transitions) {
                std::cout << "  Transition: " << transition.first << " -> " << transition.second << std::endl;
            }
        }
    }

    ~DFA() {
        for (auto state : all_states) {
            delete state; // ����������� ������
        }
    }
};