//INTEGRANTES
// Herbert Chumbe Ñahui
// Jesús Gadiel Velarde Tipte
// Camila Milagros Coveñas Rojas

#include <iostream>

using namespace std;
template<typename T>
struct Nodo
{
    T data;
    Nodo* next;
};

template<typename T>
class List{
    private:
    Nodo<T>* head;
    public: 
        List():head(nullptr){}

        // Retorna el elemento al comienzo
        T front(){
                return head->data;
        }

        // Retorna el elemento al final
        T back(){
            Nodo<T>* temp=head;
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            return temp->data;
        }

        //Agrega elemento al comienzo
        void push_front(T ndata){
            Nodo<T>* nodo=new Nodo<T>;
            nodo->data=ndata;
            nodo->next=head;
            head=nodo;
        }
        //Agrega elemento al final
        void push_back(T ndata){
            Nodo<T>* nodo=new Nodo<T>;
            nodo->data=ndata;
            nodo->next = nullptr; // Asegurarse de que el nodo que estamos agregando sea el último nodo

            if (head==nullptr)
            {
                head=nodo;// Si la lista está vacía, el nuevo nodo se convierte en la cabeza
            }else
            {
                Nodo<T>* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = nodo;
            }     
        }

        // Remueve el elemento al comienzo
        T pop_front(){
            T data=head->data;
            Nodo<T>* temp=head;
            head=head->next;
            delete temp;
            return data;
        }

        // Remueve el elemento al final
        T pop_back(){
            if (head->next==NULL)
            {
                T data=head->data;
                delete head;
                head=nullptr;
                return data;
            }else
            {
                Nodo<T>* temp=head;
                while (temp->next->next!=NULL)
                {
                    temp=temp->next;
                }
                T data = temp->next->data;
                delete temp->next;
                temp->next=NULL;
                return data;
            } 
        }

        // Retorna el elemento en la posición indicada
        T operator[](int pos){
            Nodo<T>* temp=head;
            int i=0;
            T elemt;
            while (i<pos-1)
            {
                temp=temp->next;
                elemt=temp->data;
                i++;
            }
            return elemt;
        };

        // Retorna si la lista está vacía o no
        bool empty(){
            Nodo<T>* temp=head;
            if (temp==NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        // Retorna el tamaño de la lista
        int size(){
            Nodo<T>* temp=head;
            int counter=0;
            while (temp!=NULL)
            {
                temp=temp->next;
                counter++;
            }
            return counter;
        }

        // Elimina todos los elementos de la lista
        void clear(){
            while (head!=NULL)
            {
                Nodo<T>* temp=head;
                head=head->next;
                delete temp;
            } 
        }

        void sort() {
        if (head == nullptr || head->next == nullptr){
            return; // No hay necesidad de ordenar si la lista está vacía o tiene solo un elemento
        }
        Nodo<T>* current = head;
        while (current->next != nullptr) {
            Nodo<T>* minNode = current;
            Nodo<T>* temp = current->next;
            while (temp != nullptr) {
                if (temp->data < minNode->data) {
                    minNode = temp;
                }
                temp = temp->next;
            }
            T tempData = current->data;
            current->data = minNode->data;
            minNode->data = tempData;

            current = current->next;
            }
        }

        // Revierte la lista
        void reverse(){
            Nodo<T>* prev=NULL;
            Nodo<T>* nxt=NULL;
            while (head!=NULL)
            {
                nxt=head->next;  
                head->next=prev; 
                prev=head;      
                head=nxt;      
            }
            head=prev;       
        }

        void print() {
        Nodo<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout <<endl;
        }
};


int main(){
    // List lista;
    // lista.push_front(5);
    // lista.push_front(4);
    // lista.push_front(3);
    // lista.push_front(2);
    // lista.push_front(1);

    // cout<<"Lista inicial: ";
    // lista.print();

    // lista.push_back(6);

    // cout<<"Lista modificada: ";
    // lista.traverse();

    // lista.pop_front();

    // cout<<"Lista despues del pop: ";
    // lista.traverse();

    // cout<<"Primer elemento: "<<lista.front()<<endl;
    // cout<<"Ultimo elemento: "<<lista.back()<<endl;
    // lista.traverse();

    // cout<<"Size: "<<lista.size()<<endl;

    // List l;
    // cout<<"La lista esta vacia: "<<l.empty()<<endl;

    //lista.reverse();

    //lista.print();

    //cout<<"Elemento a retornar seguna la posicion: "<<lista.operator[](2);


    List<int> lista;
    // lista.push_back(5);
    // lista.push_back(2);
    // lista.push_back(9);
    // lista.push_back(1);
    // lista.push_back(7);
    // lista.push_back(10);
    cout<<"ELEMENT: "<<lista.back();

    // cout << "Lista antes de ordenar: ";
    // lista.print();

    // lista.sort();

    // cout << "Lista después de ordenar: ";
    // lista.print();

}


