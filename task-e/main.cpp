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
    //�������� ����� �� ������
    int left = 0;
    int right = coordinates[n - 1] - coordinates[0] + 1;//������������ ���������� ����� ��������
    int middle = 0;

    while (!(right - left <= 1)) { //������ ����� ���� �������� �� 2 �� �������� ������� �� ��������
        middle = (left + right) / 2;

        int lastCoordinate = coordinates[0];
        int cowsCounter = 1; //���� ������ ��� � ������
        int i = 1;
        bool isApproach = false;
        while (i < n) { //���������� ��������� �� ���������� ����� � ����� ����������� �����������
            int distance = coordinates[i] - lastCoordinate;
            if (distance >= middle) {
                cowsCounter++;
                lastCoordinate = coordinates[i];
                if(cowsCounter == k){
                    left = middle; // ����������� �����(��������� middle) �� �������� ����
                    isApproach = true;
                    break;
                }
            }
            i++;
        }
        if(!isApproach){
            right = middle; // ��������� �����(��������� middle) �� �������� ����
        }
    }
    cout << left;

    return 0;
}
