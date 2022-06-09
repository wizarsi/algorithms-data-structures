#include <iostream>

using namespace std;

int main() {
    string numberPart;
    string numbers[100]; //������������ ���-�� �����
    int size = 0;

    while (cin >> numberPart) {
        if (numberPart.empty() || numberPart == "end") break;
        numbers[size] = numberPart;
        size++;
    }

    //���������� ��������
    for (int i = 0; i < size; i++) {
        int j = i;
        string wallValue = numbers[i];
        while (j >= 0 && wallValue + numbers[j] <= numbers[j] + wallValue) { /*������������ �������� �����������
                                                                                �������� ����� � ����� �����*/
            numbers[j] = numbers[j - 1];
            j--;
        }
        numbers[j + 1] = wallValue;
    }
    while (size >= 0) {
        cout << numbers[size];
        size--;
    }
    return 0;
}