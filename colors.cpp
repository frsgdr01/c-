#include "colors.h"
#include <iostream>

int favoriteColorsMask = 0;

const std::string colorNames[] = {
    "червоний", "синій", "зелений", "жовтий", "фіолетовий", 
    "блакитний", "білий", "чорний", "помаранчевий", "бежевий", 
    "рожевий", "салатовий", "сірий"
};

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

void printFavorites() {
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