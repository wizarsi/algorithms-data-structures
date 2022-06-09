#include <stdio.h>

int main() {
    int a;
    int res1 = scanf("%d", &a);
    int b[a];

    for (int i = 0; i < a; i++) {
        int resTemp = scanf("%d", &b[i]);
    }

    int lastElement = b[0];
    int currentLast = 0;
    int currentFirst = 0;
    int last = 0;
    int first = 0;
    int counter = 1;
    for (int i = 1; i < a; i++) {
        if (b[i] == lastElement) {
            counter++;
            if (counter == 3) {
                if ((last - first) < (currentLast - currentFirst)) {
                    first = currentFirst;
                    last = currentLast;
                }
                currentFirst = i - 1;
                counter = 2;
            }
        } else {
            counter = 1;
        }
        lastElement = b[i];
        currentLast = i;

    }
    if ((last - first) < (currentLast - currentFirst)) {
        first = currentFirst;
        last = currentLast;
    }

    printf("%d", first + 1);
    printf(" %d", last + 1);
    return 0;
}
