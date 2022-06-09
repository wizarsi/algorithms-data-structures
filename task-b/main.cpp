#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> tempElements;
    string inputData;
    cin >> inputData;
    stack<int> animals, traps;
    int animalCounter = 0, trapCounter = 0;
    int results[inputData.size() / 2 + 1];
    int i = 0;
    while (i < inputData.size()) {
        if (islower(inputData[i])) {
            animalCounter++;
            animals.push(animalCounter);
        } else {
            trapCounter++;
            traps.push(trapCounter);
        }
        if (!tempElements.empty() && (tolower(inputData[i]) == tolower(tempElements.top()))
            && (inputData[i] != tempElements.top())) {
            int numberTrap = traps.top();
            results[numberTrap] = animals.top();
            traps.pop();
            animals.pop();
            tempElements.pop();
        } else {
            tempElements.push(inputData[i]);
        }
        i++;
    }
    if (tempElements.empty()) {
        cout << "Possible\n";
        for (int i = 1; i < inputData.size() / 2 + 1; i++) {
            cout << results[i] << " ";
        }
    } else {
        cout << "Impossible";
    }
    return 0;
}
