#include <iostream>
#include <windows.h>
#include "colors.h"
#include "menu.h"

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    while (true) {
        printMainMenu();
        int input = 0;
        std::cin >> input;

        switch (input) {
            case 1: {
                printAddColorMenu();
                int index = 0;
                std::cin >> index;
                addColor(index);
                break;
            }
            case 2: {
                printRemoveColorMenu();
                int index = 0;
                std::cin >> index;
                removeColor(index);
                break;
            }
            case 3:
                printFavorites();
                break;
            case 4:
                return 0;
            default:
                std::cout << "некоректний ввід спробуйте ще раз\n";
                break;
        }
    }
    return 0;
}