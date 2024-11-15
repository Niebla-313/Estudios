//Intento a hacer dos codigos fuentes separados para ver que tengo que hacer para este codigo en el main. 
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;
using Matrix = int**;

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

Matrix matrix_add (Matrix A, Matrix B, int n) { // sumita de matrices
    Matrix C = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

Matrix matrix_substraction (Matrix A, Matrix B, int n) {    //restica de matrices
    Matrix C = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

void random_matrix (Matrix &A, int n) {     //OJO esto se supone que es para inicializar una matriz con numeros random, PERO, no se porque. hago dos llamadas para para las matrices A y B en el main
    srand(time(NULL));                      // y me llena ambas matrices con los mismo numeros, si quieres lo revisas.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
        }
    }
}

Matrix linear_matrix_multi (Matrix A, Matrix B, int n) {    //Esta es la multiplicacion de matrices de forma iterativa.
    Matrix C = create_matrix(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j]; 
            }
            C[i][j] = sum;
            sum = 0;
        }
    }
    return C;
}
