#include <iostream>

///---------Ej.1---------
/// Leer una lista de 10 valores enteros listarlos por pantalla en sentido inverso al que ingresaron
/// Autor: Giuseppe Ciavirella

using namespace std;

int main()
{
    int i;                                              //Para recorrer el array
    int enteros[10];
    for(i = 0; i <= 9; i++)
    {
        cout << "Ingrese el entero numero " << i+1 << ": ";
        cin >> enteros[i];
    }
    cout << endl << "--FIN DEL INGRESO--" << endl << endl;
    cout << "El orden inverso en el cual se ingresaron fue:" << endl;
    for(i = 9; i >= 0; i--)                             //Reutilizo el mismo contador, le puedo asignar 9 al arrancar el for
    {
        cout << enteros[i] << endl;
    }
    return 0;
}
