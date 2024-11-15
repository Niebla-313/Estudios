//Librerias
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;
// Funtions
void matrix(int **matrix_a, int **matrix_b, int **matrix_c, int size)
{
 //Caso de parada.
 if (size == 1)// cuando la matriz es de un solo valor
 {
    matrix_c[size-1][size-1]=matrix_a[size-1][size-1]*matrix_b[size-1][size-1];
 }
 else
 {

 }
 
}
void print(int **matrix,int size)
{
     for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j == 1)
            {
                printf("el valor de la posicion %d %d es %d \n",i,j,matrix[i][j]);
            }
            else
            {
                
                printf("el valor de la posicion %d %d es %d ",i,j,matrix[i][j]);
            }
             
        }
        
    } 
}
// Main
int main()
{
    int size =2; // tamaño de la matriz
    int **matrix_a; //declaracion de puntero para la matriz 1
    matrix_a = new int*[size];// creacion de la primera fila
    int **matrix_b; //declaracion de puntero para la matriz 2
    matrix_b = new int*[size];// creacion de la primera fila
    int **matrix_c; //declaracion de puntero para la matriz 2
    matrix_c = new int*[size];// creacion de la primera fila
    //creacion de las columnas
    for (int i = 0; i < size; i++)
    {
        matrix_a[i]= new int[size];
        matrix_b[i]= new int[size];
        matrix_c[i]= new int[size];

    }
    //llenado de la matriz

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix_a[i][j] = rand() % 100;
            matrix_b[i][j] = rand() % 100;
            matrix_c[i][j] = rand() % 100;
        }
        
    }
    printf("\nimpresion de la matriz a");
    print(matrix_a,size);
    printf("\nimpresion de la matriz b");
    print(matrix_b,size);
    printf("\nimpresion de la matriz c");
    print(matrix_c,size);
    matrix(matrix_a, matrix_b, matrix_c,size);
    printf("\nimpresion de la matriz final c");
    print(matrix_c,size);
    /*
      for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j == 1)
            {
                printf("el valor de la posicion %d %d es %d \n",i,j,matrix[i][j]);
            }
            else
            {
                
                printf("el valor de la posicion %d %d es %d ",i,j,matrix[i][j]);
            }
             
        }
        
    }
    
    */ // Impresion
    

}
