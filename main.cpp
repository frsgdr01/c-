#include <iostream>
#include "flip.h"

using namespace std;

int main()
{
    char str[] = "123456";

    cout << "Original: " << str << endl;

    flipArray(str);

    cout << "Flipped: " << str << endl;

    return 0;
}