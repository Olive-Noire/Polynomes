#include <iostream>

#include "../Headers/Polynomial.hpp"

int main() {

    Polynomial p1{"3x^2+x+7"};
    Polynomial p2{"4x^3-3x^2+x+1"};

    if (ToString(p1+p2) != "4x^3+2x+8") std::cout << "Addition non implemente correctement\n";
    if (ToString(p1-p2) != "-4x^3+6x^2+6") std::cout << "Soustraction non implemente correctement\n";
    if (ToString(p1*p2) != "12x^5-5x^4+28x^3-17x^2+8x+7") std::cout << "Multiplication non implemente correctement\n";

    p1 = Polynomial{"16x^4+8x^3-4x^2+6"};
    p2 = Polynomial{"2x-5"};

    if (ToString(p1/p2) != "8x^3+24x^2+58x+145") std::cout << "Division non implemente correctement\n";
    if (ToString(p1%p2) != "731") std::cout << "Modulo non implemente correctement\n";

    std::cout << "Si aucun message ne s'affiche alors l'implementation est correcte !";
    std::cin.get();

    return 0;

}

// Command : g++ -m32 "./Code/sources/*.cpp" -o "./bin/Polynômes" -std=c++17 -Wall -Wextra -pedantic-errors -O3