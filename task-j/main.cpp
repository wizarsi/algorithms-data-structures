#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> firstHalfPart;
    deque<int> secondHalfPart;

    while (n!=0) {
        if (firstHalfPart.size()>secondHalfPart.size()){
            secondHalfPart.push_back(firstHalfPart.front());
            firstHalfPart.pop_front();
        }
        string temp;
        cin >> temp;
        if (temp == "-") {
            cout << secondHalfPart.front()<<endl;
            secondHalfPart.pop_front();
        } else{
            if (temp == "*") {
                int number;
                cin>> number;
                firstHalfPart.push_front(number);
            } else if (temp == "+") {
                int number;
                cin>> number;
                firstHalfPart.push_back(number);
            }
        }
        n--;
    }
    return 0;
}

