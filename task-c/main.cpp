#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    string inputData;
    vector<map<string, int[2]>> blocks;
    map<string, int[2]> currentBlock;
    map<string, int> allValues;


    while (getline(cin, inputData)) {

        if (inputData == "{") {
            blocks.push_back(currentBlock);
            currentBlock.clear();
        } else if (inputData != "}") {
            int realValue;
            int separator = inputData.find('=');
            string key = inputData.substr(0, separator);
            string value = inputData.substr(separator + 1, inputData.length());

            if (currentBlock.count(key) == 0) {
                currentBlock[key][0] = allValues[key];
            }
            if (isdigit(value[0]) || isdigit(value[1])) {
                realValue = stoi(value);
            } else {
                realValue = allValues[value];
                cout << realValue << endl;
            }
            currentBlock[key][1] = realValue;
            allValues[key] = realValue;
        } else if (inputData == "}") {
            for (auto &it: currentBlock) {
                allValues[it.first] = it.second[0];
            }
            currentBlock = blocks.back();
            blocks.pop_back();
        }

    }
    return 0;
}
