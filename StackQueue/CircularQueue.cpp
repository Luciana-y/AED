#include <iostream>
#define MAX 100  // Tamaño máximo de la cola

using namespace std;

template <class T>
class CircularQueue {
private:
    T arr[MAX];
    int front;
    int rear;
    int count;  // Número actual de elementos en la cola

public:
    // Constructor
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Verifica si la cola está vacía
    bool isEmpty() const {
        return count == 0;
    }

    // Verifica si la cola está llena
    bool isFull() const {
        return count == MAX;
    }

    // Inserta un elemento en la cola
    void enqueue(const T& value) {
        if (isFull()) {
            cout << "Cola llena. No se puede insertar " << value << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        count++;
    }

    // Elimina y retorna el elemento del frente
    T dequeue() {
        if (isEmpty()) {
            cerr << "Cola vacía. No se puede eliminar." << endl;
            return T();  // Valor por defecto
        }
        T temp = arr[front];
        front = (front + 1) % MAX;
        count--;
        return temp;
    }

    // Retorna el elemento en el frente sin eliminarlo
    T peek() const {
        if (isEmpty()) {
            cerr << "Cola vacía." << endl;
            return T();
        }
        return arr[front];
    }

    // Muestra los elementos de la cola
    void display() const {
        if (isEmpty()) {
            cout << "Cola vacía." << endl;
            return;
        }
        cout << "Contenido de la cola: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % MAX] << " ";
        }
        cout << endl;
    }
};

// Ejemplo de uso
int main() {
    CircularQueue<int> cola;

    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);
    cola.display();

    std::cout << "Frente: " << cola.peek() << std::endl;

    cola.dequeue();
    cola.display();

    cola.enqueue(40);
    cola.enqueue(50);
    cola.display();

    return 0;
}
