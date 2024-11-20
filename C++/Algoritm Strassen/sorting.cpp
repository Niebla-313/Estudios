//Librerias
#include <cstdio>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
//Funciones
//PD: hize cambios para en vez de trabajar con arreglos dinamicos, aplicar directamente vectores.

// funcion que imprime un arreglo

void print_array(std::vector<int> arr) {
    for (auto i : arr)
        std::cout << i << " ";
    std::cout << '\n';
}

// funcion para obtener el elemento maximo en un vector
int max_element (std::vector<int> array) {
    int max = 0;
    for (int i = 0, n = array.size(); i < n; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

// funcion para obtener elemento minimo en un vector
int min_element (std::vector<int> array) {
    int min = 0x7FFFFFFF;
    for (int i = 0, n = array.size(); i < n; i++) {
        if (array[i] < min)
            min = array[i];
    }
    return min;
}

//anadido ordenamiento counting sort
void counting_sort (std::vector<int> &original_array) {
    int max = max_element(original_array);
    int min = min_element(original_array);
    std::vector<int> output_array(original_array.size(), 0);
    std::vector<int> counting_array (max - min + 1, 0);
    for (int i = 0, n = original_array.size(); i < n; i++)
        counting_array[original_array[i] - min]++;
    for(int i = 1, n = counting_array.size(); i < n; i++)
        counting_array[i] += counting_array[i - 1];
    for (int i = original_array.size() - 1; i >= 0; i--) {
        output_array[counting_array[original_array[i] - min] - 1] = original_array[i];
        counting_array[original_array[i] - min]--;
    }
    output_array.swap(original_array);

}
// fin ordenamiento counting sort

// Actualizacion anadido ordenamiento heap sort
void max_heapify (std::vector<int> &array, int i, int size) {

  int left, right, largest;
  left = 2 * i + 1;
  right = 2 * i + 2;
  if (left <= size && array[left] > array[i]) {
    largest = left;
  } else {
    largest = i;
  }
  if (right <= size && array[right] > array[largest]) {
    largest = right;
  }
  if (largest != i) {
    std::swap(array[i], array[largest]);
    max_heapify (array, largest, size);
  }
}

void build_max_heap (std::vector<int> &array) {
  for (int i = array.size()/2; i >= 0; i--)
    max_heapify (array, i, array.size());
}

void heap_sort (std::vector<int> &array) {
  build_max_heap (array);
  int size = array.size() - 1;
  for (int i = size; i > 0; i--) {
    std::swap(array[0], array[i]);
    size--;
    max_heapify (array, 0, size);
    
  }
}
// fin heap sort
//inicio del quick sort
int partition (std::vector<int> &arr, int start, int end, int x) {
    if(x) { 
    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            std::swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    std::swap(arr[pIndex], arr[end]);
    return pIndex;
    } else {
    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++) {
        if (arr[i] >= pivot) {
            std::swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    std::swap(arr[pIndex], arr[end]);
    return pIndex;
    }
}
void quick_sort (std::vector<int> &arr, int start, int end, int x) {
    if (start >= end)
        return;
    int pivot = partition(arr, start, end, x);
    quick_sort (arr, start, pivot - 1, x);
    quick_sort (arr, pivot + 1, end, x);
}
//fin del quick sort PD pronto tengo que implementar que el pivote, sea elegido aleatoriamente para mejorar un poco el caso promedio 

// inicio del selection sort
void selection_sort (std::vector<int> &arr, int n, int x) {     // Basicamente aqui quise hacer la funcion que ordene de menor a mayor y de mayor a menor. El cambio es nada mas cambiar el signo en la linea 18
    int small = 0;                                  // y ya. hice un if para hacer las dos versiones, i si x es verdad, menor a mayor, si es falso, mayor a menor.
    if (x) {                                        // no se si hay una forma en c++ de hacer un if que solo cambie el signo para ahorrarse codigo.
        for (int i = 0; i < n; i++) {               // en las demas funciones es igual.
            for (int j = i; j < n; j++) {
                if (arr[j] < arr[small])
                    small = j;
                }
            std::swap (arr[i], arr[small]);
            small = i+1;
        }
        
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (arr[j] > arr[small])
                    small = j;
                }
            std::swap (arr[i], arr[small]);
            small = i+1;
        }

    }
}
// el fin

//Burbuja sort, muy ineficiente, pero oye is free
void bubble_sort (std::vector<int> &arr, int n, int x) {
    if (x) {
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                    if (arr[j] < arr[j - 1])
                        std::swap (arr[j], arr[j - 1]);
            }

        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                    if (arr[j] > arr[j - 1])
                        std::swap (arr[j], arr[j - 1]);
            }
        }
    }
}

// insertion sort, ideal para ordenar vectores de tamano pequeno
void insertion_sort (std::vector<int> &arr, int n, int x) {
    
    int temp, j = 0;
    if (x) {
    for (int i = 1; i < n; i++) {
        j = i - 1;
        temp = arr[i];
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    } else {
      for (int i = 1; i < n; i++) {
        j = i - 1;
        temp = arr[i];
        while (j >= 0 && arr[j] < temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }  
    }
}


// inicio del merge sort
void merge (std::vector<int> &arr, int p, int q, int r, int x) {
    int nl = q - p + 1;
    int nr = r - q;
    int L[nl];
    int R[nr];
    for (int i = 0; i < nl; i++)
        L[i] = arr[p + i];
    for (int i = 0; i < nr; i++)
        R[i] = arr[q + i + 1];
    
    int i = 0, j = 0;
    int k = p;
    if (x) {
    while (i < nl && j < nr) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    } else {
    while (i < nl && j < nr) {
        if (L[i] > R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    }
    while (i < nl){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < nr) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort (std::vector<int> &arr, int p, int r, int x) {
    if (p >= r)
        return;
    int q = (p + r) / 2;
    merge_sort (arr, p, q, x);
    merge_sort (arr, q+1, r, x);
    merge (arr, p, q, r, x);
}

// fin del merge sort
// Main
int main () {
    srand(time(NULL));// random.
    int x = rand() % 2;    
    std::vector<int> arr (20, 0);
    int n = arr.size();
    for (int i = 0; i < n; i++)
        arr[i] = rand () % 100 + 1;
    print_array (arr);
    //Modificaciones para seleccionar el tipo de arreglo.
    bool not_selection = true;
    int option = -1;
    while(not_selection)
    {
        printf("Seleccione una opcion para proceder con el ordenamiento:\n 0 = Selection Sort. \n 1 = Bubble Sort. \n 2 = Merge Sort.\n 3 = Quick sort.\n 4 = Heap sort. \n 5 = Counting sort. \n");
        scanf("%d",&option);
        if((option <= 5) && (option >= 0)) // verificacion.
        {
            not_selection=false; // salir de bucle.
            switch (option)
            {
                case 0:
                selection_sort(arr,n,x);
                break;

                case 1:
                bubble_sort(arr,n,x);
                break;

                case 2:
                merge_sort(arr,0,n-1,x);
                break;

                case 3:
                quick_sort (arr, 0, n - 1, x);
                break;

                case 4:
                heap_sort (arr);
                break;

                case 5:
                counting_sort(arr);
                break;

            }
        }
        else
        {
            printf("Ingrese un valor comprendido entre 0 y 5. \n");

        }
    }
    // Fin de modificacion.
    /*insertion_sort (arr, n, x);*/ // Si quitas la modificacion habilitas estos.
    print_array (arr);
    return 0;

}