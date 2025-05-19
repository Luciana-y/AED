#include <iostream>
#define MAX 100  // Tamaño máximo de la pila
using namespace std;


template <class T>
class Stack {
private:
    T arr[MAX];  // Arreglo de tipo genérico
    int top;     // Índice del tope de la pila

public:
    Stack() {
        top = -1;  // Inicialmente la pila está vacía
    }

    // Verifica si la pila está vacía
    bool isEmpty() const {
        return top == -1;
    }

    // Verifica si la pila está llena
    bool isFull() const {
        return top == MAX - 1;
    }

    // Agrega un elemento a la pila
    void push(const T& value) {
        if (isFull()) {
            cout << "Stack overflow: no se puede insertar " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    // Elimina y retorna el elemento del tope
    T pop() {
        if (isEmpty()) {
            cout << "La pila está vacía" << endl;
            return T();  // Retorna un valor por defecto
        }
        return arr[top--];
    }

    // Retorna el elemento del tope sin eliminarlo
    T peek() const {
        if (isEmpty()) {
            cout << "La pila está vacía" << endl;
            return T();
        }
        return arr[top];
    }

    // Muestra los elementos de la pila
    void display() const {
        if (isEmpty()) {
            cout << "La pila está vacía" << endl;
            return;
        }
        std::cout << "Contenido de la pila: ";
        for (int i = top; i >= 0; i--) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

// Ejemplo de uso
int main() {
    Stack<int> pilaEnteros;
    pilaEnteros.push(10);
    pilaEnteros.push(20);
    pilaEnteros.push(30);
    pilaEnteros.display();

    cout << "Elemento en el tope: " << pilaEnteros.peek() << endl;
    pilaEnteros.pop();
    pilaEnteros.display();

    Stack<string> pilaCadenas;
    pilaCadenas.push("Hola");
    pilaCadenas.push("Mundo");
    pilaCadenas.display();

    return 0;
}
