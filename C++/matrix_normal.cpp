//Librerias mod
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;
// Funtions
int** matrix(int **matrix_a, int **matrix_b, int size)
{
 //Caso de parada.
 if (size == 2)// cuando la matriz es de dos valores.
 {
    int MA_11=matrix_a[0][0], MA_12=matrix_a[0][1], MA_21=matrix_a[1][0], MA_22=matrix_a[1][1]; //Division de la matrix a.
    int MB_11=matrix_b[0][0], MB_12=matrix_b[0][1], MB_21=matrix_b[1][0], MB_22=matrix_b[1][1]; //Division de la matrix b.
    int P_1= MA_11*(MB_12-MB_22);
    int P_2= (MA_11+MA_12)*MB_22;
    int P_3= (MA_21+MA_22)*MB_11;
    int P_4= MA_22*(MB_21-MB_11);
    int P_5= (MA_11+MA_22)*(MB_11+MB_12);
    int P_6= (MA_12-MA_22)*(MB_21+MB_22);
    int P_7= (MA_11-MA_21)*(MB_11+MB_12);
    //Creacion de los 4 elementos de la solución.
    
    return ;
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
    matrix_c=matrix(matrix_a, matrix_b,size);
    printf("\nimpresion de la matriz final c");
    print(matrix_c,size);
    

}
