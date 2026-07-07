#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(const char* str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    int size = 0;
    cout << "Enter max text size: ";
    cin >> size;

    cin.ignore();

    char* str = new char[size + 1];

    cout << "Enter text: ";
    cin.getline(str, size + 1);

    if (isPalindrome(str)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not palindrome" << endl;
    }

    delete[] str;

    return 0;
}