#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool isPalindrome(char str[]);

int main()
{
    char str[1000] = "\0";

    cout << "Enter text: ";
    cin.getline(str, 1000);

    if (isPalindrome(str))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not palindrome";
    }

    return 0;
}

bool isPalindrome(char str[])
{
    int len = strlen(str);
    int left = 0;
    int right = len - 1;

    while (left < right)
    {
        if (str[left] == ' ')
        {
            ++left;
            continue;
        }
        if (str[right] == ' ')
        {
            --right;
            continue;
        }

        char leftChar = tolower(str[left]);
        char rightChar = tolower(str[right]);

        if (leftChar != rightChar)
        {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}