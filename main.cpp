#include <iostream>

class vector {
private:
    unsigned int size = 0;
    int* dinamycArray = nullptr;

public:
    vector(int sizeOffArray) {
        size = sizeOffArray;
        dinamycArray = new int[size]{0};
    }

    ~vector() {
        delete[] dinamycArray;
    }

    void resize(int newSize) {
        if (newSize < 0) return;

        int* newArray = new int[newSize]{0};
        int elementsToCopy = (newSize < size) ? newSize : size;

        for (int i = 0; i < elementsToCopy; ++i) {
            newArray[i] = dinamycArray[i];
        }

        delete[] dinamycArray;
        dinamycArray = newArray;
        size = newSize;
    }

    void set(int index, int newValue) {
        if (index >= 0 && index < static_cast<int>(size)) {
            dinamycArray[index] = newValue;
        }
    }

    int get(int index) const {
        if (index >= 0 && index < static_cast<int>(size)) {
            return dinamycArray[index];
        }
        return 0;
    }

    unsigned int getSize() const {
        return size;
    }
};

int main() {
    vector myVector(5);

    for (int i = 0; i < 5; ++i) {
        myVector.set(i, (i + 1) * 10);
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << myVector.get(i) << " ";
    }
    std::cout << "\n";

    myVector.resize(8);
    myVector.set(5, 60);
    myVector.set(6, 70);
    myVector.set(7, 80);

    for (int i = 0; i < 8; ++i) {
        std::cout << myVector.get(i) << " ";
    }
    std::cout << "\n";

    myVector.resize(3);
    for (int i = 0; i < 3; ++i) {
        std::cout << myVector.get(i) << " ";
    }
    std::cout << "\n";

    return 0;
}