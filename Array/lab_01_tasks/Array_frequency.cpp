#include <iostream>
using namespace std;

int main() {
    int arr[7] = {10, 20, 10, 30, 20, 10, 40};
    int n = 7;
    bool counted[7] = {false};

    cout << "Frequency of Elements:" << endl;

    for(int i = 0; i < n; i++) {
        if(counted[i]) continue;
        int freq = 1;
        for(int j = i+1; j < n; j++) {
            if(arr[i] == arr[j]) {
                freq++;
                counted[j] = true;
            }
        }
        cout << arr[i] << " occurs " << freq << " times" << endl;
    }

    return 0;
}
