#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const saa::MenuItem saa::STUDY_SUM = {
    "1 - Хочу научиться складывать!", saa::study_sum, &saa::STUDY
};

const saa::MenuItem saa::STUDY_SUBSTRACT = {
    "2 - Хочу научиться вычитать!", saa::study_substract, &saa::STUDY
};

const saa::MenuItem saa::STUDY_MULTIPLY = {
    "3 - Хочу научиться умножать!", saa::study_multiply, &saa::STUDY
};

const saa::MenuItem saa::STUDY_DIVIDE = {
    "4 - Хочу научиться делить!", saa::study_divide, &saa::STUDY
};

const saa::MenuItem saa::STUDY_GO_BACK = {
    "0 - Выйти в главное меню", saa::study_go_back, &saa::STUDY
};

namespace {
    const saa::MenuItem* const study_children[] = {
        &saa::STUDY_GO_BACK,
        &saa::STUDY_SUM,
        &saa::STUDY_SUBSTRACT,
        &saa::STUDY_MULTIPLY,
        &saa::STUDY_DIVIDE
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const saa::MenuItem saa::STUDY = {
    "1 - Хочу учиться математике!", saa::show_menu, &saa::MAIN, study_children, study_size
};

const saa::MenuItem saa::EXIT = {
    "0 - Я лучше пойду полежу...", saa::exit, &saa::MAIN
};

namespace {
    const saa::MenuItem* const main_children[] = {
        &saa::EXIT,
        &saa::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const saa::MenuItem saa::MAIN = {
    nullptr, saa::show_menu, nullptr, main_children, main_size
};
