//
//  main.cpp
//  PriorityQueue
//
//  Created by Nadia Garcia on 02/02/20.
//  Copyright © 2020 Nadia Garcia. All rights reserved.
//

#include <iostream>
#include "Priority.h"
using namespace std;

int main() {
    Priority miq;
    Priority miQR(false);
    
    cout << "Operaciones de una lista ordenada de mayor a menor, un heap normal. " << endl;
    
    if( miq.empty() ) {
        cout << "Está vacía." << endl;
    } else {
        cout << "No está vacía. " << endl;
    }
    miq.push(3);
    if( miq.empty() ) {
        cout << "Está vacía." << endl;
    } else {
        cout << "No está vacía. " << endl;
    }
    cout << "Front: " << miq.top() << " Size: " << miq.size() << endl;
    miq.push(20);
    cout << "Front: " << miq.top() << " Size: " << miq.size() << endl;
    miq.push(19);
    cout << "Front: " << miq.top() << " Size: " << miq.size() << endl;
    //miq.pop();
    cout << miq.top() << endl;
    miq.print();
    cout << endl;
    miq.pop();
    cout << "Front: " << miq.top() << " Size: " << miq.size() << endl;
    miq.print();
    cout << endl;
    miq.push(50);
    miq.push(-9);
    cout << "Front: " << miq.top() << " Size: " << miq.size() << endl;
    miq.print();
    
    
    
    miQR.push(5);
    miQR.print();
    cout << endl;
    miQR.push(4);
    miQR.print();
    cout << endl;
    miQR.push(2);
    miQR.print();
    cout << endl;
    
    cout << miQR.top() << endl;
    miQR.pop();
    cout << miQR.top() << endl;
    

    
    
    return 0;
}
