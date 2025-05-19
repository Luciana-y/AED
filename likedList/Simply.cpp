
#include <iostream>

using namespace std;

template <typename T>
struct node {
    T data;
    node* next;
};

template <typename T>
class forwardList {
private:
    node<T>* head;
public:
    forwardList() {
        head = nullptr;
    }

    T front() {
        if (head) {
            return head -> data;;
        }
        return T();
    }

    T back() {
        node<T>* temp = head;
        if (head !=nullptr) {
            node<T>* temp = head;
            while (temp -> next !=nullptr) {
                temp = temp -> next;
            }
            return temp -> data;
        }

        return T();
    }

    void push_front(T data) {
        auto* temp = new node<T>;
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    void push_back(T data){
        node<T>* newNode = new node<T>();
        newNode->data = data;
        newNode->next = nullptr;
        if(!head){
            head = newNode;
        }else{
            node<T>* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    T pop_front(){
        if(head){
            node<T>* temp = head;
            head = head->next;
            T data = head->data;
            delete temp;
            return data;
        }
        return T();
    }

    T pop_back(){
        if(head){
            node<T>* temp = head;
            node<T>* prev = nullptr;
            while(temp->next != nullptr){
                prev = temp;
                temp = temp->next;
            }
            if(prev){
                prev->next = nullptr;
            }else{
                head = nullptr;
            }
            T data = temp->data;
            delete temp;
            return data;
        }
        return T();
    }

    T operator[](const int index) {
        if (index < 0) return T();

        node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            if (temp == nullptr) return T();
            temp = temp->next;
        }

        if (temp == nullptr) return T();
        return temp->data;
    }



    bool empty() {
        return head == nullptr;
    }

    int size() {
        node<T>* temp = head;
        int sz=0;
        while (temp!=nullptr) {
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    void clear() {
        while (head!=nullptr) {
            node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void sort() {
        head = mergeSort(head);
    }

    node<T> *mergeSort(node<T> *head) {
        if (head==nullptr || head->next==nullptr) {
            return head;
        }
        node<T>* second = split(head);
        head = mergeSort(head);
        second = mergeSort(second);

        return merge(head,second);
    }

    node<T> *merge(node<T> *half1, node<T> *half2) {
        if (half1 == nullptr){return half2;}
        if (half2 == nullptr){return half1;}

        if ((half1->data) < (half2->data)) {
            half1->next = merge(half1->next, half2);
            return half1;
        }else {
            half2->next = merge(half1, half2->next);
            return half2;
        }
    }

    node<T>* split(node<T>* head) {
        if(!head || !head->next) return nullptr;
        node<T>* slow = head;
        node<T>* fast = head->next;
        while (fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        node<T>* temp = slow->next;
        slow->next = nullptr;
        return temp; // dos punteros comienzan a recorrer la lista 2 en 2 y el otro 1 en en 1
        // cuando el primero termina el segundo se queda en la mitad
        //se parte el slow o el segundo haciendo que ya no apunte a nada
        //previamente haciendo que un head temporal sea el siguiente de slow
        //head queda como quedo solo que ahora la mitad ya no apunta a nada
        //y se retorna temp que es la cabeza de lo que era fast, la segund mitad
    }



    void reverse() {
        forwardList temp;
        node<T>* tempNode = head;
        while (head!=nullptr) {
            temp.push_front(head->data);
            head = head->next;
            delete tempNode;
            tempNode = head;
        }
        head = temp.head;
    }

    void insert(int index, T data){
        if(index == 0){
            push_front(data);
        }else{
            node<T>* temp = head;
            for(int i = 0; i < index - 1; i++){
                if(temp->next == nullptr){
                    return;
                }
                temp = temp->next;
            }
            node<T>* newNode = new node<T>();
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void remove(int index){
        if(head != nullptr){
            if(index == 0){
                pop_front();
            }else{
                node<T>* temp = head;
                for(int i = 0; i < index - 1; i++){
                    if(temp->next == nullptr){
                        return;
                    }
                    temp = temp->next;
                }
                if(temp->next != nullptr){
                    node<T>* toDelete = temp->next;
                    temp->next = toDelete->next;
                    delete toDelete;
                }
            }
        }
    }
    template <typename U>
    friend ostream& operator<<(ostream& os, const forwardList<U>& list);
};

template <typename U>
ostream& operator<<(ostream& os, const forwardList<U>& list) {
    node<U>* temp = list.head;
    while (temp != nullptr) {
        os << temp->data;
        if (temp->next != nullptr) os << " -> ";
        temp = temp->next;
    }
    return os;
}


int main() {
    cout << "TESTS LISTAS VACIAS:" << endl;
    forwardList<double> list1;
    cout << list1.front() << endl;
    cout << list1.back() << endl;
    cout << list1.pop_front() << endl;
    cout << list1.pop_back() << endl;
    cout << list1[2] << endl;
    cout << list1.size() << endl;



    cout << "\n";
    cout << "TEST PUSH:" << endl;
    forwardList<string> list2;
    list2.push_front("front1");
    list2.push_front("front2");
    list2.push_back("back1");
    list2.push_back("back2");
    cout << list2.front() << endl;
    cout << list2.back() << endl;



    cout << "\n";
    cout << "TEST []:" << endl;
    cout << "Imprimiendo " <<list2.size() << " elementos:"<< endl;
    for (int i = 0; i < list2.size(); i++){
        cout <<"- "<< list2[i] << endl;
    }



    cout << "\n";
    cout << "TEST POP:" << endl;
    cout << list2.pop_front() << endl;
    cout << list2.pop_back() << endl;
    cout << list2.front() << endl;


    cout << "\n";
    cout << "TEST CLEAR:" << endl;
    cout << "Lista inicial: "<<list2<< endl;
    list2.clear();
    cout << "Lista final: "<<list2.size() << endl;


    cout << "\n";
    cout << "TEST RESERVE, INSERT, REMOVE, SORT:" << endl;
    forwardList<int> list3;
    list3.push_front(3);
    list3.push_front(5);
    list3.push_front(2);
    list3.push_front(9);
    list3.insert(88,5);
    list3.remove(9);
    list3.push_front(2);
    list3.insert(5,2);
    list3.push_front(10);
    list3.push_front(5);
    list3.insert(4, 5);

    cout << "\n";
    cout << "Original: ";
    cout << list3 << endl;

    cout << "\n";
    list3.sort();
    cout << "Sorted: ";
    cout << list3 << endl;

    cout << "\n";
    list3.reverse();
    cout << "Reversed: ";
    cout << list3 << endl;
}
