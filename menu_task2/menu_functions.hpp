#pragma once

#include "menu.hpp"

namespace saa {
    const MenuItem* show_menu(const MenuItem* current);
    const MenuItem* exit(const MenuItem* current);
   
    const MenuItem* show_spbu(const MenuItem* current);
    const MenuItem* show_itmo(const MenuItem* current);
    const MenuItem* show_polytech(const MenuItem* current);
    const MenuItem* show_leti(const MenuItem* current);
    const MenuItem* back_to_main(const MenuItem* current);
   
    const MenuItem* show_pm_pu(const MenuItem* current);
    const MenuItem* show_matmech(const MenuItem* current);
    const MenuItem* show_linguistics(const MenuItem* current);
    const MenuItem* back_to_universities(const MenuItem* current);
}
