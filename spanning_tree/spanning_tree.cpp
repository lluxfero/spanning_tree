#include <iostream>
#include <Windows.h>
#include <clocale>
using namespace std;

int err_n() {
    int m, ival = 1;
    cin >> m;
    while (ival == 1) {
        if (cin.fail() || m < 1) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте еще раз: ";
            cin >> m;
        }
        else
            ival = 0;
    }
    return m;
}

int err_d() {
    int m, ival = 1;
    cin >> m;
    while (ival == 1) {
        if (cin.fail() || m < 0 || m > 1) {

            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Ошибка! Попробуйте еще раз: ";
            cin >> m;
        }
        else
            ival = 0;
    }
    return m;
}

void show_desk(int** d, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void spanning_tree(int** d, int n) {
    int** st = new int* [n];
    for (int i = 0; i < n; i++)
        st[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            st[i][j] = 0;

    int* st_help = new int[n];
    for (int i = 0; i < n; i++)
        st_help[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (st_help[j] == 0) {
                if (d[i][j] == 1 && st[i][j] == 0) {
                    st[i][j] = 1;
                    st[j][i] = 1;
                    if (st_help[i] == 0) st_help[i] = 1;
                    if (st_help[j] == 0) st_help[j] = 1;
                }
            }
        }

    show_desk(st, n);
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введите количество вершин дерева: ";
    n = err_n();

    int** desk = new int* [n];
    for (int i = 0; i < n; i++)
        desk[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            desk[i][j] = 0;

    cout << "Введите матрицу смежности: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            desk[i][j] = err_d();
    cout << endl;

    spanning_tree(desk, n);
}