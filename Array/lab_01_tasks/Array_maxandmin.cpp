#include <iostream>
using namespace std;

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    int maximum = numbers[0];
    int minimum = numbers[0];

    int i = 1;
    while(i < length) {
        if(numbers[i] > maximum) {
            maximum = numbers[i];
        }
        if(numbers[i] < minimum) {
            minimum = numbers[i];
        }
        i++;
    }

    cout << "Max Value: " << maximum << endl;
    cout << "Min Value: " << minimum << endl;

    return 0;
}
