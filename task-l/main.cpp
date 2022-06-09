#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> numbers;
    numbers.resize(n);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        numbers[i] = temp;
    }

    int minIndexRow = -2;
    int min = numbers[0];
    for (int indexStart = 0; indexStart < n - k + 1; indexStart++) {
        if (minIndexRow < indexStart) {
            int localMin = numbers[indexStart];
            for (int j = indexStart; j < indexStart + k; j++) {
                if (numbers[j] <= localMin) {
                    localMin = numbers[j];
                    min = numbers[j];
                    minIndexRow = j;
                }
            }
        } else {
            if (numbers[minIndexRow] >= numbers[indexStart + k - 1]) {
                min = numbers[indexStart + k - 1];
                minIndexRow = indexStart + k - 1;
            }
        }
        cout << min << " ";

    }

    return 0;
}
