#include <iostream>
using namespace std;

int main() {
    int a, a_up, a_down, r1, r2, n;
    r1 = 2;
    int array_up[4], array_down[4];
    cout << "Введите 4-значное число.. ";
    cin >> a;
    if (a < 1e3 || a > 1e4)
        cout << "Число неверное";
    else {
        while (r1 != r2) {
            r2 = r1;
            //заполнение массива
            for (int i = 0; i < 4; i++) {
                array_up[i] = a % 10;
                array_down[i] = a % 10;
                a /= 10;
                cout << array_up[i] << " ";
            }
            cout << endl;
            //сортировка по возростанию
            for (int i = 0; i < 4; i++)
                for (int j = i + 1; j < 4; j++)
                    if (array_up[i] > array_up[j])
                        swap(array_up[i], array_up[j]);
            //сортировка по убыванию
            for (int i = 0; i < 4; i++)
                for (int j = i + 1; j < 4; j++)
                    if (array_down[i] < array_down[j])
                        swap(array_down[i], array_down[j]);
            //преобразование массива в число
            for (int i = 0; i < 4; i++) {
                a_up = a_up * 10 + array_up[i];
                a_down = a_down * 10 + array_down[i];
            }
            cout << a_up << endl << a_down << endl;
            r1 = a_down - a_up;
            a_up = 0;
            a_down = 0;
            a = r1;
            n++;
        }
        cout << "Циклов прошло: " << n;
    }
    return 0;
}