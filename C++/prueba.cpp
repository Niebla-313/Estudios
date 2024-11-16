#include <iostream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>

using namespace std;
using Matrix = int**;
void random_matrix (Matrix &A, int n) {     //OJO esto se supone que es para inicializar una matriz con numeros random, PERO, no se porque. hago dos llamadas para para las matrices A y B en el main
    srand(time(NULL));                      // y me llena ambas matrices con los mismo numeros, si quieres lo revisas.
    struct timeval tv;
    // Obtener microsegundos
    gettimeofday(&tv, NULL);
    long int timeInMicroseconds = tv.tv_sec * 1000000 + tv.tv_usec;
    printf("%d\n",timeInMicroseconds);
    srand(timeInMicroseconds);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            //printf("%d",A[i][j]);
        }
    }
}
Matrix create_matrix(int n) {   //Para no tener que estar repitiendo esto tanto en el main, lo hice aparte para que se vea mas bonito
    Matrix new_matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        new_matrix[i] = new int[n];
    }
    return new_matrix;
}
void print_matrix (Matrix A, int n) {   //imprime la matriz
    for (int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int n = 4;
    Matrix A = create_matrix(n);
    Matrix B = create_matrix(n);
    random_matrix(A, n);
    random_matrix(B, n);
    print_matrix(A, n);
    print_matrix(B, n);
}
