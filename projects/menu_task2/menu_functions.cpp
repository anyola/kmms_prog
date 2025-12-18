#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const saa::MenuItem* saa::show_menu(const MenuItem* current) {
    if (current->title && std::string(current->title) == "1 - СПБГУ") {
        std::cout << "Вас приветствует ректор СПБГУ!" << std::endl;
    }

    std::cout << "Выберите пункт меню:" << std::endl;
    for (int i = 0; i < current->children_count; i++) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << "> ";
    
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
    return nullptr;
}

const saa::MenuItem* saa::show_spbu(const MenuItem* current) {
    std::cout << "Вы выбрали СПБГУ" << std::endl;
    return current;
}

const saa::MenuItem* saa::show_itmo(const MenuItem* current) {
    std::cout << "Вы выбрали ИТМО" << std::endl;
    return current->parent;
}

const saa::MenuItem* saa::show_polytech(const MenuItem* current) {
    std::cout << "Вы выбрали Политех" << std::endl;
    return current->parent;
}

const saa::MenuItem* saa::show_leti(const MenuItem* current) {
    std::cout << "Вы выбрали ЛЭТИ" << std::endl;
    return current->parent;
}

const saa::MenuItem* saa::back_to_main(const MenuItem* current) {
    return current->parent->parent;
}

const saa::MenuItem* saa::show_pm_pu(const MenuItem* current) {
    std::cout << "Вы выбрали ПМ-ПУ" << std::endl;
    return current->parent;
}

const saa::MenuItem* saa::show_matmech(const MenuItem* current) {
    std::cout << "Вы выбрали МатМех" << std::endl;
    return current->parent;
}

const saa::MenuItem* saa::show_linguistics(const MenuItem* current) {
    std::cout << "Вы выбрали Лингвистический факультет" << std::endl;
    return current->parent;
}

const saa::MenuItem* saa::back_to_universities(const MenuItem* current) {
    return current->parent->parent;
}