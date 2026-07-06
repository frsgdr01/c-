#include <iostream>

using namespace std;

bool findChar(const char* str, const char element)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == element)
        {
            return true;
        }
        ++i;
    }
    return false;
}

int main()
{
    const char text[] = "hello";
    char searchElement = 'l';

    if (findChar(text, searchElement))
    {
        cout << "Character '" << searchElement << "' found in string." << endl;
    }
    else
    {
        cout << "Character '" << searchElement << "' not found in string." << endl;
    }

    return 0;
}