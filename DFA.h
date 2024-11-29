#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>

class DFA {
private:

    // структура данных для состояния
    struct State {
        // хэш таблица для хранения переходов из состояния
        std::unordered_map<char, State*> transitions;
        // по дефолту состояние не допускающее
        bool is_final = false;
    };

    // начальное состояние
    State* start_state;
    // все состояния (хранятся в сете)
    std::set<State*> all_states;

public:

    DFA() {
        start_state = new State();
        all_states.insert(start_state);
    }

    void add_string(const std::string& str) {
        State* current_state = start_state;

        for (const char& ch : str) {
            if (current_state->transitions.find(ch) == current_state->transitions.end()) {
                // создаем новое состояние, если перехода нет
                State* new_state = new State();
                current_state->transitions[ch] = new_state;
                all_states.insert(new_state);
            }
            current_state = current_state->transitions[ch];
        }
        current_state->is_final = true; // устанавливаем текущее состояние как финальное
    }

    bool accepts(const std::string& str) const {
        State* current_state = start_state;

        for (char ch : str) {
            if (current_state->transitions.find(ch) == current_state->transitions.end()) {
                return false; // перехода нет, строка не принимается
            }
            current_state = current_state->transitions.at(ch);
        }
        return current_state->is_final; // проверяем, является ли текущее состояние финальным
    }

    // функция вывода автомата
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
            delete state; // освобождаем память
        }
    }
};