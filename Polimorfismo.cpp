#include <iostream>

using namespace std; // hola cambios

class vehiculo
{
public:
    virtual void acelerar() = 0;
    virtual void frenar() = 0;
};

class coche : public vehiculo
{
public:
    void acelerar() override
    {
        cout << " el coche esta acelerando " << endl;
    }
    void frenar() override
    {
        cout << " el coche freno " << endl;
    }
};

class moto : public vehiculo
{
public:
    void acelerar() override
    {
        cout << " La moto esta acelerando " << endl;
    }
    void frenar() override
    {
        cout << " la moto esta frenando " << endl;
    }
};

class bicicleta : public vehiculo
{
public:
    void acelerar() override
    {
        cout << "se esta pedaleando mas rapido" << endl;
    }
    void frenar() override
    {
        cout << " la bicicleta esta frenando " << endl;
    }
};
int main()
{
    vehiculo* mivehiculo = new coche();
    vehiculo* mivehiculo2 = new moto();
    mivehiculo-> frenar();
    
    return 0;
    }