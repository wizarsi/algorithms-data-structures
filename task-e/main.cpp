#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int i = 0;
    int coordinates[n];
    while (i < n) {
        cin >> coordinates[i];
        i++;
    }
    //бинарный поиск по ответу
    int left = 0;
    int right = coordinates[n - 1] - coordinates[0] + 1;//максимальная расстояние между стойлами
    int middle = 0;

    while (!(right - left <= 1)) { //делаем поиск пока делением на 2 не уменьшим отрезок до минимума
        middle = (left + right) / 2;

        int lastCoordinate = coordinates[0];
        int cowsCounter = 1; //одна корова уже в стойле
        int i = 1;
        bool isApproach = false;
        while (i < n) { //определяем получится ли разместить коров с таким минимальным расстоянием
            int distance = coordinates[i] - lastCoordinate;
            if (distance >= middle) {
                cowsCounter++;
                lastCoordinate = coordinates[i];
                if(cowsCounter == k){
                    left = middle; // увеличиваем ответ(следующий middle) от которого ищем
                    isApproach = true;
                    break;
                }
            }
            i++;
        }
        if(!isApproach){
            right = middle; // уменьшаем ответ(следующий middle) от которого ищем
        }
    }
    cout << left;

    return 0;
}
