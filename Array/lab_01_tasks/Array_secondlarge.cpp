#include <iostream>
#include <climits>
using namespace std;

// Function to get the second largest element
int getSecondLargest(int nums[], int size) {
    int maxVal = nums[0];
    int secondMax = INT_MIN;

    for(int i = 1; i < size; i++) {
        if(nums[i] > maxVal) {
            secondMax = maxVal;
            maxVal = nums[i];
        } else if(nums[i] > secondMax && nums[i] != maxVal) {
            secondMax = nums[i];
        }
    }
    return secondMax;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    int result = getSecondLargest(numbers, length);
    cout << "Second Largest Number: " << result << endl;

    return 0;
}
