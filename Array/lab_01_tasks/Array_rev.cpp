#include <iostream>
using namespace std;

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Reversed Array: ";
    int index = size - 1;
    while(index >= 0) {
        cout << numbers[index] << " ";
        index--;
    }
    cout << "\n";

    return 0;
}
