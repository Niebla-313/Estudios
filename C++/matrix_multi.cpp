#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

void matrix_multi (int** a, int** b, int** c, int n) {
    if (n == 1) {
        c[0][0] += a[0][0] * b[0][0];
        return;
    }
    int mid = 0;
    mid = n / 2;
    int** a11 = new int*[n];
    int** a12 = new int*[n];
    int** a21 = new int*[n];
    int** a22 = new int*[n];
    int** b11 = new int*[n];
    int** b12 = new int*[n];
    int** b21 = new int*[n];
    int** b22 = new int*[n];
    int** c11 = new int*[n];
    int** c12 = new int*[n];
    int** c21 = new int*[n];
    int** c22 = new int*[n];

    for (int i = 0; i < n; i++) {
        a11[i] = new int[n];
        a12[i] = new int[n];
        a21[i] = new int[n];
        a22[i] = new int[n];
        b11[i] = new int[n];
        b12[i] = new int[n];
        b21[i] = new int[n];
        b22[i] = new int[n];
        c11[i] = new int[n];
        c12[i] = new int[n];
        c21[i] = new int[n];
        c22[i] = new int[n];
    }

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            a11[i][j] = a[i][j];
            a12[i][j + mid] = a[i][j + mid];
            a21[i + mid][j] = a[i + mid][j];
            a22[i + mid][j + mid] = a[i + mid][j + mid];
            b11[i][j] = b[i][j];
            b12[i][j + mid] = b[i][j + mid];
            b21[i + mid][j] = b[i + mid][j];
            b22[i + mid][j + mid] = b[i + mid][j + mid];
            c11[i][j] = c[i][j];
            c12[i][j + mid] = c[i][j + mid];
            c21[i + mid][j] = c[i + mid][j];
            c22[i + mid][j + mid] = c[i + mid][j + mid];    
        }
    }
    matrix_multi (a11, b11, c11, mid);
    matrix_multi (a11, b12, c12, mid);
    matrix_multi (a21, b11, c21, mid);
    matrix_multi (a21, b12, c22, mid);
    matrix_multi (a12, b21, c11, mid);
    matrix_multi (a12, b22, c12, mid);
    matrix_multi (a22, b21, c21, mid);
    matrix_multi (a22, b22, c22, mid);
    for (int i = 0; i < n; i++) {
        delete a11[i];
        delete a12[i];
        delete a21[i];
        delete a22[i];
        delete b11[i];
        delete b12[i];
        delete b21[i];
        delete b22[i];
        delete c11[i];
        delete c12[i];
        delete c21[i];
        delete c22[i];
    }
    delete[] a11;
    delete[] a12;
    delete[] a21;
    delete[] a22;
    delete[] b11;
    delete[] b12;
    delete[] b21;
    delete[] b22;
    delete[] c11;
    delete[] c12;
    delete[] c21;
    delete[] c22;


}




int main () {
    srand(time(NULL));
    int** a = new int*[2];
    int** b = new int*[2];
    int** c = new int*[2];

    for (int i = 0; i < 2; i++) {
        a[i] = new int[2];
        b[i] = new int[2];
        c[i] = new int[2];
    }


    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
            c[i][j] = 0;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << b[i][j] << " ";

        }
        cout << endl;
    }

    cout << endl;

    matrix_multi (a, b, c, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete a[i];
        delete b[i];
        delete c[i];
    }
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}