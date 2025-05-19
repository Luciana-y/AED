#include <iostream>
#define MAX 100  // Una celda menos se usa como margen

using namespace std;

template <class T>
class CircularQueue {
private:
    T arr[MAX];
    int front;
    int rear;

public:
    CircularQueue() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() const {
        return front == rear;
    }

    bool isFull() const {
        return (rear + 1) % MAX == front;
    }

    void enqueue(const T& value) {
        if (isFull()) {
            cout << "Cola llena. No se puede insertar " << value << endl;
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % MAX;
    }

    T dequeue() {
        if (isEmpty()) {
            cerr << "Cola vacía. No se puede eliminar." << endl;
            return T();
        }
        T temp = arr[front];
        front = (front + 1) % MAX;
        return temp;
    }

    T peek() const {
        if (isEmpty()) {
            cerr << "Cola vacía." << endl;
            return T();
        }
        return arr[front];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Cola vacía." << endl;
            return;
        }
        cout << "Contenido de la cola: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
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

    cout << "Frente: " << cola.peek() << endl;

    cola.dequeue();
    cola.display();

    cola.enqueue(40);
    cola.enqueue(50);
    cola.display();

    return 0;
}
