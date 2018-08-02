#include <iostream>
#include <conio.h>                      //Para usar el getch()
#define CANTFILAS 6
#define CANTCOLUMNAS 5
#define TAMVECTOR 30

///---------Ej.8---------
/// Convertir una tabla de 6 x 5 en un vector ordenado de mayor a menor
/// Autor: Giuseppe Ciavirella

using namespace std;

//Sacada del ejercicio 6, para ordenar el vector de mayor a menor una vez armado
void burbujaInvertida(int v[], int tamanio)
{
    int aux;
    int i, j;       //Contadores
    for(i = 0; i < tamanio - 1; i++)
    {
        for(j = 0; j < tamanio - 1 - i; j++)
        {
            if(v[j] < v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
    return;             //No necesario
}

//Subprograma para inicializar los valores de una tabla, de a uno
void inicializarTabla(int tabla[CANTFILAS][CANTCOLUMNAS])
{
    int fila;
    int columna;
    for(fila = 0; fila < CANTFILAS; fila++)
    {
        for(columna = 0; columna < CANTCOLUMNAS; columna++)
        {
            cout << "Fila " << fila + 1 << ", columna " << columna + 1 << ": ";
            cin >> tabla[fila][columna];
        }
    }
}

void transformarTablaAVectorOrdenado(int tabla[CANTFILAS][CANTCOLUMNAS], int vec[])
{
    int i = 0;              //Con este indice voy a recorrer el vector
    int fila;
    int columna;
    //Voy a recorrer cada celda, yendo por cada columna de cada fila, y copiarlo al array
    for(fila = 0; fila < CANTFILAS; fila++)
    {
        for(columna = 0; columna < CANTCOLUMNAS; columna++)
        {
            vec[i] = tabla[fila][columna];
            i++;
        }
    }
    burbujaInvertida(vec, TAMVECTOR);
}

//Sacado del ejercicio 7. Subprograma para mostrar los elementos de un array, uno al lado del otro, separados por barras
void mostrarVector(int vec[], int tamanio)
{
    int i;
    for(i = 0; i <= tamanio - 2; i++)           //Muestro hasta el anteultimo con barra
    {
        cout << vec[i] << "|";
    }
    cout << vec[tamanio-1];                     //Ahora si, muestro el ultimo, sin barra despues
}

int main()
{
    int tabla[CANTFILAS][CANTCOLUMNAS];   //Declaro una tabla de cierta cantidad de filas y de columnas; por defecto, es de 6x5
    int v[TAMVECTOR];
    cout << "Primero, cargue los valores en la tabla:" << endl << endl;
    inicializarTabla(tabla);
    cout << endl << "Presione una tecla para transformarla en un vector y ordenarla" << endl;
    getch();
    transformarTablaAVectorOrdenado(tabla, v);
    cout << "Transformacion realizada. Presione una tecla para mostrar" << endl;
    getch();
    cout << endl;
    mostrarVector(v, TAMVECTOR);
    cout << endl;
    return 0;
}
