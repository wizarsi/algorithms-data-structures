#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int startCount = a;
    int i = 0;
    while (i < k) {
        a = a * b - c;
        if (a == startCount) break;
        if (a <= 0) {
            a = 0;
            break;
        } else if (a >= d) {
            a = d;
            break;
        }
        i++;
    }
    cout << a;
    return 0;
}
