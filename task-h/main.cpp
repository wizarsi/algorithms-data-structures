#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

bool compare(int l, int r) {
    return l > r;
}

int main() {
    int n, k;
    vector<int> prices;
    cin >> n >> k;
    prices.resize(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        prices[i] = number;
        sum += number;
    }

    sort(prices.begin(), prices.end(), compare);


    int result = 0;
    for (int j = n - 1; j >= 0; j--) {
        if (((j + 1) % k) == 0) result += prices[j];
    }

    cout << sum - result;

}
