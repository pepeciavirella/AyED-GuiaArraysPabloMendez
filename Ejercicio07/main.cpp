#include <iostream>
#include <conio.h>          //Para la funcion getch()
#define TAM1 6              //Constantes para los tamaños; no necesarias, pero si convenientes
#define TAM2 8
#define TAMRES 14

///---------Ej.7---------
/// Confeccionar un subprograma que, dados dos vectores de números enteros liste el
/// contenido de ambos pero en forma ordenada. Utilice el algoritmo de apareo.
/// Autor: Giuseppe Ciavirella

using namespace std;

//Subprograma para inicializar un vector de cierto tamaño
void inicializarVector(int vec[], int tamanio)
{
    int i;
    for(i = 0; i < tamanio; i++)
    {
        cout << "Elemento " << i << ": ";
        cin >> vec[i];
    }
}

//Subprograma para mostrar los elementos de un array, uno al lado del otro, separados por barras
void mostrarVector(int vec[], int tamanio)
{
    int i;
    for(i = 0; i <= tamanio - 2; i++)           //Muestro hasta el anteultimo con barra
    {
        cout << vec[i] << "|";
    }
    cout << vec[tamanio-1];                     //Ahora si, muestro el ultimo, sin barra despues
}

//Para ordenar un vector de menor a mayor
void burbujaNormal(int v[], int tamanio)
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
    return;             //No necesario
}

//Sacada del ejercicio 6, para ordenar de mayor a menor un vector
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

//Realiza el apareo tradicional, ordenando de menor a mayor los elementos
void apareoAscendente(int v1[], int tamanio1, int v2[], int tamanio2, int vResultado[])
{
    burbujaNormal(v1, tamanio1);            //Antes de hacer el apareo, debo ordenarlos
    burbujaNormal(v2, tamanio2);
    int i = 0;
    int j = 0;
    int k = 0;
    while((i < tamanio1) && (j < tamanio2))
    {
        if(v1[i] < v2[j])                   //Copio el mas chico primero, y avanzo en el vector que lo poseia
        {
            vResultado[k] = v1[i];
            i++;
        }
        else
        {
            vResultado[k] = v2[j];
            j++;
        }
        k++;                                //Siempre avanzo en el resultante, ya que ahi voy copiando
    }
    int cont;
    if(i < tamanio1)
    {
        for(cont = i; cont < tamanio1; cont++)
        {
            vResultado[k] = v1[cont];
            k++;
        }
    }
    else
    {
        for(cont = j; cont < tamanio2; cont++)
        {
            vResultado[k] = v2[cont];
            k++;
        }
    }
                                 //Contador extra, usado para rellenar si me falto poner elementos de algun array
  /*  for(cont = i; cont < tamanio1; cont++)  //Solo voy a entrar a este for si me faltaron elementos de v1
    {
        vResultado[k] = v1[cont];
        k++;
    }
    for(cont = j; cont < tamanio2; cont++)  //Y a este solo si me faltaron elementos de v2
    {
        vResultado[k] = v2[cont];
        k++;
    }*/
}

//Apareo alternativo, copia los elementos ordenados de mayor a menor; casi igual que el comun
void apareoDescendente(int v1[], int tamanio1, int v2[], int tamanio2, int vResultado[])
{
    burbujaInvertida(v1, tamanio1);         //Antes de hacer el apareo, debo ordenarlos
    burbujaInvertida(v2, tamanio2);
    int i = 0;
    int j = 0;
    int k = 0;
    while((i < tamanio1) && (j < tamanio2))
    {
        if(v1[i] > v2[j])                   //Copio el mas grande primero, y avanzo en el vector que lo poseia
        {
            vResultado[k] = v1[i];
            i++;
        }
        else
        {
            vResultado[k] = v2[j];
            j++;
        }
        k++;                                //Siempre avanzo en el resultante, ya que ahi voy copiando
    }
    int cont;                               //Contador extra, usado para rellenar si me falto poner elementos de algun array
    for(cont = i; cont < tamanio1; cont++)  //Solo voy a entrar a este for si me faltaron elementos de v1
    {
        vResultado[k] = v1[cont];
        k++;
    }
    for(cont = j; cont < tamanio2; cont++)  //Y a este solo si me faltaron elementos de v2
    {
        vResultado[k] = v2[cont];
        k++;
    }
}

int main()
{
    int vector1[TAM1];
    int vector2[TAM2];
    int vAscendente[TAMRES];
    int vDescendente[TAMRES];
    cout << "Ingrese los valores del primer vector" << endl;
    inicializarVector(vector1, TAM1);
    cout << endl;
    cout << "Ingrese los valores del segundo vector" << endl;
    inicializarVector(vector2, TAM2);
    cout << endl << "Presione una tecla para ejecutar los apareos" << endl;
    getch();
    apareoAscendente(vector1, TAM1, vector2, TAM2, vAscendente);
    apareoDescendente(vector1, TAM1, vector2, TAM2, vDescendente);
    cout << "Apareos realizados; presione una tecla para mostrar ambos arrays" << endl;
    getch();
    cout << endl << "Vector ordenado ascendentemente:" << endl;
    mostrarVector(vAscendente, TAMRES);
    cout << endl << endl << "Vector ordenando descendentemente:" << endl;
    mostrarVector(vDescendente, TAMRES);
    cout << endl;                                               //Por temas esteticos :P
    return 0;
}
