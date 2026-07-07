#include <iostream>
#include <string>
#include <windows.h>

class ColorManager {
private:
    int favoriteColorsMask = 0;
    const std::string colorNames[13] = {
        "червоний", "синій", "зелений", "жовтий", "фіолетовий", 
        "блакитний", "білий", "чорний", "помаранчевий", "бежевий", 
        "рожевий", "салатовий", "сірий"
    };

public:
    void printColorList() {
        std::cout << "\n";
        for (int i = 0; i < 13; ++i) {
            std::cout << i << ". " << colorNames[i] << "\n";
        }
    }

    void addColor(int index) {
        if (index >= 0 && index <= 12) {
            int i = 1;
            i = i << index;
            favoriteColorsMask = favoriteColorsMask | i;
            std::cout << "додано\n";
        } else {
            std::cout << "невірний індекс\n";
        }
    }

    void removeColor(int index) {
        if (index < 0 || index > 12) {
            std::cout << "невірний індекс\n";
            return;
        }
        int i = 1;
        i = i << index;
        i = ~i;
        favoriteColorsMask = favoriteColorsMask & i;
        std::cout << "видалено\n";
    }

    void showFavorites() {
        bool hasFavorites = false;
        for (int index = 0; index < 13; ++index) {
            int i = 1;
            i = i << index;
            if ((favoriteColorsMask & i) > 0) {
                std::cout << "- " << colorNames[index] << "\n";
                hasFavorites = true;
            }
        }
        if (!hasFavorites) {
            std::cout << "порожньо\n";
        }
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    ColorManager manager;

    while (true) {
        std::cout << "\n1. add favorite colour\n2. remove favorite\n3. show favorites\n4. exit\n-: ";
        int input = 0;
        std::cin >> input;

        if (4 == input) {
            return 0;
        }

        if (1 == input) {
            manager.printColorList();
            std::cout << "-: ";
            int index = 0;
            std::cin >> index;
            manager.addColor(index);
        }
        else if (2 == input) {
            manager.printColorList();
            std::cout << "-: ";
            int index = 0;
            std::cin >> index;
            manager.removeColor(index);
        }
        else if (3 == input) {
            manager.showFavorites();
        }
        else {
            std::cout << "некоректний ввід спробуйте ще раз\n";
        }
    }
    return 0;
}