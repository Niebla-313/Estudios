//OJO algoritmo sin terminar, son como las 5 de la manana pero logre que esta madre funcione :D, estaba modificando el codigo que hiciste. pero me quede pegado xd. me fui al libro otra vez
// investigue mas como manejar matrices, y descubri que un tipo hacia el truco de usar el using matrix. y pues asi se enclarecio la mente xd. empece un archivo desde cero y henos aqui.
//Como dije el algoritmo funciona. pero nada mas con matrices cuardradas que sean potencias de dos.
// Aun no he logrado averiguar como hacer cuando las matrices no cumplen esa condicion. ASi que si quiere echale un ojo. debe ser algo con el calculo de mid en la linea 17, creo...
// PD no he corrido esto en mi pc si no en un compilador online, porque esto se puso popis, no se porque, y no me quiere compilar xd
#include <iostream>
#include <algorithm>
#include <ctime>
#include "matrix_operation.cpp"

using namespace std;
using Matrix = int**; // investigando descubri que puedo hacer esto para en vez de int** solo poner Matriz en el tipo de dato, y se reemplaza. lo cual hace todo mas legible asi que nais.

Matrix strassen (Matrix A, Matrix B, int n) {
    if (n == 1) {
        return linear_matrix_multi(A, B, n);    //Para hacer el caso base, cree esta funcion, y me funciono. mas que nada porque como habia puesto que la funcion strassen devolviera una matriz.
    }                                           //con esta funcion puedo retornar una matriz sin ningun problema.
    int mid = n / 2;
    Matrix C = create_matrix(n);                //esta la matriz que retorbara al final con la union de C11 C12 C21 y C22

    Matrix A11 = create_matrix(mid);            //Como dije en el otro codigo esta funcion inicializa las matrices y se ve gonito.
    Matrix A12 = create_matrix(mid);
    Matrix A21 = create_matrix(mid);
    Matrix A22 = create_matrix(mid);
    Matrix B11 = create_matrix(mid);
    Matrix B12 = create_matrix(mid);
    Matrix B21 = create_matrix(mid);
    Matrix B22 = create_matrix(mid);

    for (int i = 0; i < mid; i++) {             //aqui es donde copio las submatrices
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    Matrix S1 = matrix_substraction(B12, B22, mid); //ok esto debo explicarlo, me puse a revisar el libro. y vi que el tenia ordenadas las sumas y las restas que aparecen en el pseudocodigo
    Matrix S2 = matrix_add(A11, A12, mid);          // y las separe asi para que sea mas legible
    Matrix S3 = matrix_add(A21, A22, mid);          // No puedo pegar una foto aqui. asi que te mando la captura por whatsapp
    Matrix S4 = matrix_substraction(B21, B11, mid); 
    Matrix S5 = matrix_add(A11, A22, mid);
    Matrix S6 = matrix_add(B11, B22, mid);
    Matrix S7 = matrix_substraction(A12, A22, mid);
    Matrix S8 = matrix_add(B21, B22, mid);
    Matrix S9 = matrix_substraction(A11, A21, mid);
    Matrix S10 = matrix_add(B11, B12, mid);

    Matrix P1 = strassen(A11, S1, mid);             //estas las 7 famosas multiplicacion, como separe las sumas arriba, esta mas corto.
    Matrix P2 = strassen(S2, B22, mid);
    Matrix P3 = strassen(S3, B11, mid);
    Matrix P4 = strassen(A22, S4, mid);
    Matrix P5 = strassen(S5, S6, mid);
    Matrix P6 = strassen(S7, S8, mid);
    Matrix P7 = strassen(S9, S10, mid);

    Matrix C11 = matrix_add(matrix_substraction(matrix_add(P5, P4, mid),P2, mid), P6, mid);                 //Y este lio es basicamente las sumas del final del pseudocodigo.
    Matrix C12 = matrix_add(P1, P2, mid);
    Matrix C21 = matrix_add(P3, P4, mid);
    Matrix C22 = matrix_substraction(matrix_substraction(matrix_add(P1, P5, mid),P3, mid), P7, mid);

     for (int i = 0; i < mid; i++) {            //Aqui lleno C, y abajo retorno. y listo
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
    return C;
}

int main () {
    int n = 4;
    Matrix A = create_matrix(n);
    Matrix B = create_matrix(n);
    random_matrix(A, n);
    random_matrix(B, n);
    print_matrix(A, n);
    print_matrix(B, n);
    Matrix C = strassen(A, B, n);
    print_matrix(C, n);
    return 0;
}