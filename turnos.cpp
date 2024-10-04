
#include <iostream>
#include <string>

using namespace std;

class Jugador{
    
    public:
        string nombre;
        int puntos;
        bool activo;
        Jugador(){
            
            cout << "ingrese nombre: ";
            getline(cin, nombre);
            puntos = 0;
            activo = false;
            
        }
        
};

struct nodo {
    Jugador* data;       // Datos del nodo
    nodo* next;     // Puntero al siguiente nodo
    nodo(Jugador* value) : data(value), next(nullptr) {}
};




class Turnos{
    
    private:
        nodo* head;
    
    public:
        Turnos(int n);
        void Mostrar(int n);
    
};

Turnos::Turnos(int n){
    
    if (n <= 0) {
        head = nullptr;
        return;
    }
    
    head = new nodo(new Jugador()); // Crear el primer nodo
    nodo* temp = head;

    for (int i = 1; i < n; i++) {
        nodo* newNode = new nodo(new Jugador());
        temp->next = newNode; // Conectar el nodo anterior con el nuevo
        temp = newNode;       // Avanzar al nuevo nodo
    }

    temp->next = head;
    
}

void Turnos::Mostrar(int n){
    
    nodo* temp = head;
    
    for(int i = 0; i < n; i++){
        
        cout << temp->data->nombre << " -> "; 
        temp = temp->next;
        
    }
    
}

int main(){
    
    Turnos T(4);
    
    T.Mostrar(15);

    return 0;
}