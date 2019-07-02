#include <iostream>
#include <conio.h>                      //Para usar el getch()
#define N 3
#define M 3
#define P 3
#define TAMVECTOR 27                    //Debera ser el resultado de N*M*P

///---------Ej.11---------
/// Dada una matriz tridimensional de N x M x P se pide ordenarla de menor a mayor
/// Autor: Giuseppe Ciavirella

// HIPOTESIS: Se desea ordenar los elementos a lo largo de toda la matriz,
// no solo ordenar la profundidad de cada celda (interseccion fila-columna)

using namespace std;

//Subprograma para ordenar un vector de menor a mayor
void ordenamientoBurbuja(int v[], int tamanio)
{
    int aux;
    int i, j;       //Contadores
    for(i = 0; i < tamanio - 1; i++)
    {
        for(j = 0; j < tamanio - 1 - i; j++)
        {
            if(v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

//Subprograma para inicializar los valores de la matriz, de a uno
void inicializarMatriz(int matriz[N][M][P])
{
    int fila;
    int columna;
    int profundidad;
    for(fila = 0; fila < N; fila++)
    {
        for(columna = 0; columna < M; columna++)
        {
            for(profundidad = 0; profundidad < P; profundidad++)
            {
                {
                    cout << "Fila " << fila + 1 << ", columna " << columna + 1 << ", posicion " << profundidad + 1 << ": ";
                    cin >> matriz[fila][columna][profundidad];
                }
            }
        }
    }
}

//Subprograma para aplanar todos los elementos de la matriz en un vector, y ordenar el mismo de forma ascendente
void transformarMatrizEnVectorOrdenado(int matriz[N][M][P], int auxiliar[])
{
    int i = 0;              //Con este indice voy a recorrer el vector
    int fila;
    int columna;
    int profundidad;
    //Voy a recorrer cada posicion, yendo por cada celda de la matriz NxM, y copiarlo al array
    for(fila = 0; fila < N; fila++)
    {
        for(columna = 0; columna < M; columna++)
        {
            for(profundidad = 0; profundidad < P; profundidad++)
            {
                auxiliar[i] = matriz[fila][columna][profundidad];
                i++;
            }
        }
    }
    ordenamientoBurbuja(auxiliar, TAMVECTOR);
}

//Copio los contenidos de un vector, ya ordenado, en una matriz tridimensional, por fila, columna y posicion
void copiarVectorEnMatriz(int matriz[N][M][P], int auxiliar[])
{
    int i = 0;              //Con este indice voy a recorrer el vector
    int fila;
    int columna;
    int profundidad;
    //Al ir avanzando por el vector, voy copiando sus elementos a la posicion correspondiente de la matriz
    for(fila = 0; fila < N; fila++)
    {
        for(columna = 0; columna < M; columna++)
        {
            for(profundidad = 0; profundidad < P; profundidad++)
            {
                matriz[fila][columna][profundidad] = auxiliar[i];
                i++;
            }
        }
    }
}

//Subprograma para mostrar los elementos de la matriz, recorriendo cada la profundidad de cada celda de cada fila
void mostrarMatriz(int matriz[N][M][P])
{
    int fila;
    int columna;
    int profundidad;
    for(fila = 0; fila < N; fila++)
    {
        cout << "--------FILA " << fila + 1 << ":--------" << endl;
        for(columna = 0; columna < M; columna++)
        {
            cout << "----COLUMNA " << columna + 1 << ":----" << endl;
            for(profundidad = 0; profundidad <= P - 2; profundidad++)           //Muestro hasta el anteultimo con barra
            {
                cout << matriz[fila][columna][profundidad] << "|";
            }
            cout << matriz[fila][columna][P-1]<< endl;                          //Ahora si, muestro el ultimo, sin barra despues
        }
        cout << endl;
    }
}

int main()
{
    int matriz[N][M][P];   //Declaro la matriz tridimensional (de N filas, M columnas, y profundidad P)
    int auxiliar[TAMVECTOR];       //Declaro el vector auxiliar que voy a usar para guardar y ordenar los elementos
    cout << "Primero, cargue los valores en la matriz:" << endl << endl;
    inicializarMatriz(matriz);
    cout << endl << "Presione una tecla para transformarla en un vector y ordenarla" << endl;
    getch();
    transformarMatrizEnVectorOrdenado(matriz, auxiliar);
    copiarVectorEnMatriz(matriz, auxiliar);
    cout << "Transformacion realizada. Presione una tecla para mostrar" << endl;
    getch();
    cout << endl;
    mostrarMatriz(matriz);
    cout << endl;
    return 0;
}
