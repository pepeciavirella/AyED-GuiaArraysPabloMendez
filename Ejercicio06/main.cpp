#include <iostream>
#include <conio.h>              //Para usar el getch()
#define TAMVECTOR 10             //Debe estar definido o ser conocido; puedo cambiarlo desde aca

///---------Ej.6---------
/// Realice un subprograma que muestre el contenido de un vector en forma ordenada
/// descendentemente. El tamaño del array es informado por parámetro
/// Autor: Giuseppe Ciavirella

using namespace std;

//NOTA: Hecho para arrays de enteros, pero podria hacerse con floats, doubles, o cualquier dato con valor numerico

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

int main()
{
    int vec[TAMVECTOR];
    int cont;
    cout << "Ingrese los " << TAMVECTOR << " elementos del vector" << endl;
    for(cont = 0; cont < TAMVECTOR; cont++)
    {
        cout << "Elemento " << cont << ": ";
        cin >> vec[cont];
    }
    cout << endl << "Presione una tecla para ordenar descendentemente y mostrarlo" << endl << endl;
    getch();
    burbujaInvertida(vec, TAMVECTOR);
    for(cont = 0; cont < TAMVECTOR; cont++)                     //Reutilizo cont
    {
        cout << "Elemento " << cont << ": " << vec[cont] << endl;
    }
    return 0;
}
