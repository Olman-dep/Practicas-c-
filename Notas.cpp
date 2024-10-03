/*Hacer un pograma que pida el numero de calificaciones que ingrese cada una de las calificaciones que busque el promedio
por estudiante y que diga cual es el estudiante con mejor promedio usar clasess*/
#include <iostream>
#include <conio.h>
#include <stdlib.h> // libreria para new y delete
#include <string>
#include <vector>
using namespace std;
class Notas
{
private:
    int numcalif; // el numero de califaciones
    vector<float> calif;
    float promedio_calif; // promedio de las calificaciones

public:
    void pedirnotas() // pide notas
    {
        do
        {
            cout << " numero de calificaciones " << " = " << endl;
            cin >> numcalif;
            calif.resize(numcalif);
            if (numcalif <= 0)
            {
                cout << " El número de calificaciones debe ser mayor que 0. " << endl;
            }

        } while (numcalif <= 0);

        for (int i = 0; i < numcalif; i++)
        {
            do
            {
                cout << "ingrese la calificacion de la nota # " << i + 1 << " " << endl;
                cin >> calif[i];
                if (calif[i] < 0 || calif[i] > 5)
                {
                    cout << "La nota debe ser entre o y 5" << " "<< endl;
                }

            } while (calif[i] < 0 || calif[i] > 5);
        }
        promedio();
    }

    void promedio()
    {
        float suma = 0;
        for (int i = 0; i < numcalif; i++)
        {
            suma += calif[i];
        }
        promedio_calif = static_cast<float>(suma) / numcalif;
        cout << "su promedio es" << promedio_calif << endl;
    }
};

int main()
{
    Notas notas;
    cout << "ingresar el Numero de alumnos";
    int NumAlum;
    cin >> NumAlum;
    vector<string> Nombre(NumAlum);

    for (int i = 0; i < NumAlum; i++)
    {
        cout << "Ingrese el nombre del estudiante" << "#" << i + 1 << endl;
        cin >> Nombre[i];
        notas.pedirnotas();
    }

    return 0;
}
