#include "menu.h"
#include "colors.h"
#include <iostream>

void printMainMenu() {
    std::cout << "\n1. add favorite colour\n2. remove favorite\n3. show favorites\n4. exit\n-: ";
}

void printColorList() {
    std::cout << "\n";
    for (int i = 0; i < 13; ++i) {
        std::cout << i << ". " << colorNames[i] << "\n";
    }
}

void printAddColorMenu() {
    printColorList();
    std::cout << "-: ";
}

void printRemoveColorMenu() {
    printColorList();
    std::cout << "-: ";
}