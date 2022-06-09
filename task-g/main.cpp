#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SymbolValuePair {
    char symbol;
    int value;
};

bool myComparator(SymbolValuePair l, SymbolValuePair r) {
    return l.value > r.value;
}

int main() {
    string inputData;
    cin >> inputData;
    char symbol = 'a';
    vector<SymbolValuePair> alphabet;
    while (symbol <= 'z') {
        SymbolValuePair pair;
        cin >> pair.value;
        pair.symbol = symbol;
        alphabet.push_back(pair);
        symbol++;
    }

    sort(alphabet.begin(), alphabet.end(), myComparator);

    vector<SymbolValuePair> symbolPairs;
    for (SymbolValuePair pair: alphabet) {
        if (count(inputData.begin(), inputData.end(), pair.symbol) >= 2) {
            symbolPairs.push_back(pair);
        }
    }

    int left = 0;
    int right = inputData.size() - 1;
    for (SymbolValuePair pair: symbolPairs) {
        int positionLeft = inputData.find(pair.symbol);
        if (inputData[left] != pair.symbol) swap(inputData[left], inputData[positionLeft]);
        int positionRight = inputData.substr(left + 1).find(pair.symbol) + left + 1;
        if (inputData[right] != pair.symbol) swap(inputData[right], inputData[positionRight]);
        left++;
        right--;
    }
    cout << inputData << endl;
    return 0;
}

