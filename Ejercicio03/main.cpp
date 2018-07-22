#include <iostream>
#include <cstring>              //Para usar strlen
#define TAMMAX 50               //Maximo tamaño posible de una palabra

///---------Ej.3---------
/// Se leen las letras de una palabra carácter a carácter. El último carácter que ingresa
/// es la barra de dividir(/), que indica que la palabra ha finalizado. Escribir un programa
/// que imprima la palabra en el orden que se ingresó y en sentido inverso (por ejemplo:
/// pera = arep, la palabra podrá tener hasta 20 caracteres).
/// Autor: Giuseppe Ciavirella

using namespace std;

//NOTA: No verifique si la palabra ingresada fue nula o no, para hacer el codigo mas simple; seria cosa de poner un if mas

int main()
{
    int i = 0;                                  //Para recorrer las posiciones del vector palabra
    int longitud;
    char letra;
    char palabra[TAMMAX];                       //Si o si debo definir el tamaño del array yo, por eso la constante
    cout << "Ingrese los caracteres de una palabra, uno por uno; termine con una '/' " << endl;
    do
    {
        cin >> letra;
        palabra[i] = letra;
        i++;
    }while(letra != '/');                       //Use una variable aparte para la letra para poder compararla mas facilmente
    i--;
    palabra[i] = '\0';                          //Vuelvo adonde puse la /, y lo reemplazo por el caracter nulo
    longitud = strlen(palabra);                 //Recordar: strlen me devuelve la longitud de la palabra sin el \0
    cout << "La palabra ingresada fue: ";
    for(i = 0; i < longitud; i++)
    {
        cout << palabra[i];
    }
    cout << endl << "Y la misma palabra, escrita al reves, es: ";
    int j;                                      //Para recorrerla al reves; podria reutilizar i tambien
    for(j = (longitud - 1); j >= 0; j--)        //Arranco en longitud - 1, seria la posicion de la ultima letra
    {
        cout << palabra[j];
    }
    return 0;
}
