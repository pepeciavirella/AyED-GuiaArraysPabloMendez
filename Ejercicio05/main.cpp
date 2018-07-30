#include <iostream>
#define TAMVECTOR 10            //Debe estar definido; lo modifico facil desde aca; sirve para la suma

///---------Ej.5---------
/// Hacer un programa que permita realizar la suma y el producto de dos vectores. El
/// usuario deberá poder elegir el tamaño del vector (entre 2 y 10 valores)
/// Autor: Giuseppe Ciavirella

using namespace std;

void sumarVectores(int vector1[], int vector2[], int vectorsuma[], int tamanio)
{
    int i;
    for(i = 0; i < tamanio; i++)
    {
        vectorsuma[i] = vector1[i] + vector2[i];
    }
}

int productoEscalar(int vector1[], int vector2[], int cantidadValores)
{
    int suma = 0;         //Aca voy a ir guardando la suma de los productos entre elementos del mismo indice
    int i;
    for(i = 0; i < cantidadValores; i++)
    {
        suma += (vector1[i] * vector2[i]);
    }
    return suma;
}

int main()
{
    int v1[TAMVECTOR];
    int v2[TAMVECTOR];
    int vSuma[TAMVECTOR];
    int producto;
    int cantidadDeValores, cont1, cont2, contSuma;
    //Primero, inicializo los dos vectores
    cout << "Ingrese los " << TAMVECTOR << " valores del primer vector:" << endl;
    for(cont1 = 0; cont1 < TAMVECTOR; cont1++)
    {
        cout << "Elemento " << cont1 << ": ";
        cin >> v1[cont1];
    }
    cout << "Ingrese los " << TAMVECTOR << " valores del segundo vector:" << endl;
    for(cont2 = 0; cont2 < TAMVECTOR; cont2++)
    {
        cout << "Elemento " << cont2 << ": ";
        cin >> v2[cont2];
    }
    //Los sumo y muestro el vector suma, elemento a elemento
    sumarVectores(v1, v2, vSuma, TAMVECTOR);
    cout << endl << "Los valores del vector suma son:" << endl;
    for(contSuma = 0; contSuma < TAMVECTOR; contSuma++)
    {
        cout << "Elemento " << contSuma << ": " << vSuma[contSuma] << endl;
    }
    //Calculo el producto escalar y lo sumo
    do
    {
        cout << "Cuantos componentes quiere multiplicar para el producto escalar?" << endl;
        cout << "NOTA: Deben ser entre 2 y 10" << endl;
        cin >> cantidadDeValores;
    }while((cantidadDeValores < 2) || (cantidadDeValores > 10));
    producto = productoEscalar(v1, v2, cantidadDeValores);
    cout << endl << "El producto escalar entre ambos vectores es " << producto << endl;
    return 0;
}
