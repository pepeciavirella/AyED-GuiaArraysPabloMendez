#include <iostream>
#include <cmath>                                                    //Para usar abs()

///---------Ej.2---------
/// Dado un vector 15 valores, hacer un programa que pueda obtener, y sacar por pantalla:
/// − el mayor de los valores
/// − el menor de los valores
/// − el más próximo al promedio
/// Autor: Giuseppe Ciavirella

using namespace std;

//Funcion para cargar los datos en un vector, a mano
void inicializarVector(float vec[], int tamanio)
{
    int i;
    for(i = 0; i < tamanio; i++)
    {
        cout << "Ingrese el elemento " << i+1 << " del vector: ";
        cin >> vec[i];
    }
}

int main()
{
    float enteros[15];
    int i;                                       //Es local al main, puede llamarse asi sin joder al de inicializarVector
    float suma, promedio, maximo, minimo, masCercanoAlPromedio;
    inicializarVector(enteros, 15);
    maximo = enteros[0];                         //Inicializo a todos asi para que la primera iteracion (que sera en el segundo
    minimo = enteros[0];                         //elemento), ya tenga variables que comparar o modificar
    suma = enteros[0];
    masCercanoAlPromedio = enteros[0];
    for(i = 1; i < 15; i++)
    {
        suma += enteros[i];
        if(enteros[i] > maximo)
        {
            maximo = enteros[i];
        }
        if(enteros[i] < minimo)
        {
            minimo = enteros[i];
        }
    }
    promedio = suma / 15;
    for(i = 1; i < 15; i++)                       //Vuelvo a arrancar en el elemento dos, solo me falta encontrar el mas cercano
    {
        if(abs(enteros[i] - promedio) < abs(masCercanoAlPromedio - promedio))
        {
            masCercanoAlPromedio = enteros[i];
        }
    }
    cout << endl << "--FIN DEL INGRESO--" << endl << endl;
    cout << "El maximo valor del vector fue " << maximo << endl;
    cout << "El minimo valor del vector fue " << minimo << endl;
    cout << "El valor mas cercano al promedio fue " << masCercanoAlPromedio << endl;
    return 0;
}
