#ifndef FLIP_H
#define FLIP_H

#include <cstring>

void flipArray(char* str)
{
    int len = strlen(str);
    int left = 0;
    int right = len - 1;

    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        ++left;
        --right;
    }
}

#endif