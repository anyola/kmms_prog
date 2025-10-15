#include <cmath>
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    double angle;
    std::cout << "Введите угол" << std::endl;
    std::cin >> angle;
    
    if (cos(2 * angle) != 1){
        double result1 = 
            (1 + std::sin(2 * angle)) 
            / 
            (1 - std::cos(2 * angle));
        std::cout << "Результат для 1 угла =" << result1 << std::endl;
    } else if (std::cos(2*angle) == 1){
        std::cout << "неверный ввод для 1 угла  "<< std::endl;
    }

    if  (std::tan(angle) != 1){
        double result2 = 
            (1 + std::tan(angle) * std::tan(angle))
            /
            (1 - std::tan(angle) * std::tan(angle));
        std::cout << "Результат для 2 угла =" << result2 << std::endl;
    } else if (std::tan(angle) == 1){
        std::cout << "неверный ввод для 2 угла " << std::endl;
        system ("pause");
    }

    return 0;
}

