#pragma once
#include <string>

extern int favoriteColorsMask;
extern const std::string colorNames[];

void addColor(int index);
void removeColor(int index);
void printFavorites();