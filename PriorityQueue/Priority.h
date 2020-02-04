//
//  Priority.h
//  PriorityQueue
//
//  Created by Nadia Garcia on 02/02/20.
//  Copyright © 2020 Nadia Garcia. All rights reserved.
//
#include<iostream>
#include<algorithm> //Realizar operaciones de heap
#include <vector>

using namespace std;

#ifndef Priority_h
#define Priority_h

class Priority {
private:
    int tamano;
    //Heap para enteros, utilizando un vector para almacenar
    vector <int> priorityq;
    bool priority = true;

public:
    Priority(); //Constructor default
    Priority(bool prioridad); //Constructor con prioridad especificada
    void push(int elemento); //Mete un entero a la fila
    void pop(); //Saca un entero de la lista
    int top(); //Observa el entero con la más alta prioridad
    int size(); //Regresa el tamaño de la fila
    bool empty(); //Regresa verdadero si la fila esta vacía o falso en caso contrario
    //No perteneciente a PRO09: Priority Queue with a Heap
    //void print();
};


Priority :: Priority() {
    //Fila vacia con prioridad de mayor valor
    make_heap( priorityq.begin(), priorityq.end() ); //Creacion de max heap con base al vector
    tamano = 0;
}


Priority :: Priority( bool prioridad ) {
    if ( prioridad == true )  { //true, la prioridad es mayor valor
        make_heap( priorityq.begin(), priorityq.end() ); //Creacion de max heap con base al vector
        priority = true;
    } else if (prioridad == false) {  //false, la prioridad es menor valor
        make_heap( priorityq.begin(), priorityq.end(), greater<>{}); //Creacion de min heap con base al vector
        priority = false;
    }
    tamano = 0;
}


void Priority :: push( int elemento ) {
    priorityq.push_back( elemento ); //Agregar elemento a vector
    if (priority == true ) { //Max heap
        push_heap( priorityq.begin(), priorityq.end() ); //Reordenar elementos en el max heap
    } else { //Min heap
        push_heap( priorityq.begin(), priorityq.end(), greater<> {} ); //Reordenar elementos en el min heap
    }
    tamano++; //Incremento de tamaño de nuestra fila
}


void Priority :: pop() {
    if ( tamano > 0 ) { //Solo eliminará si existen elementos en la fila
        if( priority == true ) { //Max heap
            pop_heap( priorityq.begin(), priorityq.end() ); //Eliminar elemento con la maxima prioridad en un max heap
        } else  { //Min heap
            pop_heap( priorityq.begin(), priorityq.end(), greater<> {} ); //Eliminar elemento con la maxima prioridad en un min heap
        }
        priorityq.pop_back(); //Eliminar ultimo elemento del vector
        tamano--; //Decremento de tamaño de nuestra fila
    }
}


int Priority :: top() {
    return priorityq.front(); //Regresa elemento con mayor prioridad, ya sea max heap o min heap
}


int Priority :: size() {
    return tamano; //Regresa tamaño de la fila
}


bool Priority :: empty() {
    if( tamano == 0 ) {
        return true;
    } else {
        return false;
    }
}

/*
void Priority :: print() {
    for (int &x : priorityq) {
       cout << x << " ";
    }
}*/

#endif /* Priority_h */


