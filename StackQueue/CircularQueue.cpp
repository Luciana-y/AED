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

/*
 #include <iostream>
#define MAX 100  // Tamaño máximo de la cola

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
            std::cout << "Cola llena. No se puede insertar " << value << std::endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        count++;
    }

    // Elimina y retorna el elemento del frente
    T dequeue() {
        if (isEmpty()) {
            std::cerr << "Cola vacía. No se puede eliminar." << std::endl;
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
            std::cerr << "Cola vacía." << std::endl;
            return T();
        }
        return arr[front];
    }

    // Muestra los elementos de la cola
    void display() const {
        if (isEmpty()) {
            std::cout << "Cola vacía." << std::endl;
            return;
        }
        std::cout << "Contenido de la cola: ";
        for (int i = 0; i < count; i++) {
            std::cout << arr[(front + i) % MAX] << " ";
        }
        std::cout << std::endl;
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

 */
