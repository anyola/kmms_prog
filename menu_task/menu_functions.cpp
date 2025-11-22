#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const saa::MenuItem* saa::show_menu(const MenuItem* current) {
    std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
    for (int i = 0; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << "Обучайка > ";
    
    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;

    if (user_input >= 0 && user_input < current->children_count) {
        return current->children[user_input];
    } else {
        std::cout << "Неверный выбор!" << std::endl;
        return current;
    }
}

const saa::MenuItem* saa::exit(const MenuItem* current) {
    std::exit(0);
}

const saa::MenuItem* saa::study_sum(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const saa::MenuItem* saa::study_substract(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const saa::MenuItem* saa::study_multiply(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const saa::MenuItem* saa::study_divide(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const saa::MenuItem* saa::study_go_back(const MenuItem* current) {
    return current->parent->parent;
}