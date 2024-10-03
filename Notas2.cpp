#include <iostream>
#include <conio.h>
#include <stdlib.h> // libreria para new y delete

using namespace std;
void pedirnotas();
void promedio();

int numcalif; // el numero de califaciones y el puntero a calificaciones
int *suma;
int *calif;

int main()
{
    pedirnotas();

    return 0;
}

void pedirnotas()
{
    cout << " numero de calificaciones" << endl;
    cin >> numcalif;
    calif = new int[numcalif];
    suma = new int;
    *suma = 0;

    for (int i = 0; i < numcalif; i++)
    {
        cout << "ingrese la calificacion de la nota " << i + 1 << endl;
        cin >> calif[i];
    }
    promedio();
}

void promedio()
{

    for (int i = 0; i < numcalif; i++)
    {
        *suma += calif[i];
    }

    double promedio = static_cast<double>(*suma) / numcalif;
    cout << " El promedio de notas es: " << promedio << endl;
    cout << " Porcentajes de cada calificacion " << endl;
    for (int i = 0; i < numcalif; i++)
    {
        double porcentaje = (static_cast<double>(calif[i]) / *suma) * 100;
        cout << " calificacion " << i + 1 << " = " << calif[i] << "\n porcentaje= " << porcentaje << endl;
    }
}
