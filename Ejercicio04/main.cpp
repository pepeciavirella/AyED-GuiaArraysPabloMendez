#include <iostream>
#include <conio.h>                   //Para poder usar el getch()
#define TAMVECTOR 6                  //Debe estar definido, puedo cambiarlo desde aca a mi gusto

///---------Ej.4---------
/// Diseñar un algoritmo recursivo, que permita invertir el contenido de un vector. Como indica el ejemplo:
/// Vector original: 28 35 12 43 56 77
/// Vector invertido: 77 56 43 12 35 28
/// El algoritmo no podrá usar un vector auxiliar.
/// Autor: Pablo Mendez (version adaptada por Giuseppe Ciavirella)

using namespace std;

void invertirVector(int v[], int posicionInicial, int tamanio)
{
    int auxiliar;
    if (posicionInicial < tamanio/2)      //Voy a ordenar desde los extremos hacia el medio; solo voy a
    {                                     //recorrer, en definitiva,medio array
        auxiliar = v[posicionInicial];    //Guardo el valor en esa posicion en un valor auxiliar
        v[posicionInicial] = v[tamanio-1-posicionInicial]; //En dicha posicion, ahora pongo el valor de su opuesto (el ultimo en el primero, p. ej.)
        v[tamanio-1-posicionInicial] = auxiliar; //Y, ahora, pongo en ese opuesto el valor que habia guardaro (el 1ro en el ultimo)
        invertirVector(v, posicionInicial+1, tamanio);    //Sigo recorriendo el vector y hago lo mismo en las demas posiciones
    }                                     //Solo lo va a hacer hasta llegar al elemento de la mitad y hacerlo con su siguiente
    return;
}

int main()
{
    int vec[TAMVECTOR];
    int i;
    cout << "Ingrese los elementos de su vector" << endl;
    cout << "NOTA: El mismo consta de " << TAMVECTOR << " elementos" << endl << endl;
    for(i = 0; i < TAMVECTOR; i++)
    {
        cout << "Elemento " << i+1 << ": ";
        cin >> vec[i];
    }
    invertirVector(vec, 0, TAMVECTOR);
    cout << "Vector invertido. Presione una tecla para mostrarlo" << endl;
    getch();
    for(i = 0; i < TAMVECTOR; i++)
    {
        cout << "Elemento " << i+1 << ": " << vec[i] << endl;
    }
    return 0;
}
