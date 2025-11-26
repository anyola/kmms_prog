#include "menu_items.hpp"
#include "menu_functions.hpp"

#include <cstddef>

const saa::MenuItem saa::PM_PU = {
    "1 - Факультет ПМ-ПУ",
    saa::show_pm_pu,
    &saa::SPBU
};

const saa::MenuItem saa::MATMECH = {
    "2 - Факультет МатМех",
    saa::show_matmech, 
    &saa::SPBU
};

const saa::MenuItem saa::LINGUISTICS = {
    "3 - Лингвистический факультет",
    saa::show_linguistics,
    &saa::SPBU
};

const saa::MenuItem saa::BACK_TO_UNIVERSITIES = {
    "0 - Выйти в предыдущее меню",
    saa::back_to_universities,
    &saa::SPBU
};

namespace {
    const saa::MenuItem* const spbu_children[] = {
        &saa::BACK_TO_UNIVERSITIES,
        &saa::PM_PU,
        &saa::MATMECH,
        &saa::LINGUISTICS
    };
    const int spbu_size = sizeof(spbu_children) / sizeof(spbu_children[0]);
}

const saa::MenuItem saa::SPBU = {
    "1 - СПБГУ",
    saa::show_menu,
    &saa::UNIVERSITIES,
    spbu_children,
    spbu_size
};

const saa::MenuItem saa::ITMO = {
    "2 - ИТМО",
    saa::show_itmo,
    &saa::UNIVERSITIES,
    nullptr,
    0
};

const saa::MenuItem saa::POLYTECH = {
    "3 - Политех",
    saa::show_polytech,
    &saa::UNIVERSITIES,
    nullptr,
    0
};

const saa::MenuItem saa::LETI = {
    "4 - ЛЭТИ",
    saa::show_leti,
    &saa::UNIVERSITIES,
    nullptr,
    0
};

const saa::MenuItem saa::BACK_TO_MAIN = {
    "0 - Выйти в главное меню",
    saa::back_to_main,
    &saa::UNIVERSITIES,
    nullptr,
    0
};

namespace {
    const saa::MenuItem* const universities_children[] = {
        &saa::BACK_TO_MAIN,
        &saa::SPBU,
        &saa::ITMO,
        &saa::POLYTECH,
        &saa::LETI
    };
    const int universities_size = sizeof(universities_children) / sizeof(universities_children[0]);
}

const saa::MenuItem saa::UNIVERSITIES = {
    "1 - Посмотреть университеты Санкт-Петербурга",
    saa::show_menu,
    &saa::MAIN,
    universities_children,
    universities_size
};

const saa::MenuItem saa::EXIT = {
    "0 - Я уже студент",
    saa::exit,
    &saa::MAIN,
    nullptr,
    0
};

namespace {
    const saa::MenuItem* const main_children[] = {
        &saa::EXIT,
        &saa::UNIVERSITIES
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const saa::MenuItem saa::MAIN = {
    "Главное меню",
    saa::show_menu,
    nullptr,
    main_children,
    main_size
};