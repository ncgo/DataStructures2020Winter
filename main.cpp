//
//  main.cpp
//  PRO10 - Phone Book
//
//  Created by Nadia Garcia on 31/01/20.
//  Copyright © 2020 Nadia Garcia. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <map>
#include <queue>
using namespace std;

void find( map< int, string > phonebook, int iPhoneNo, queue<string> &findQ ) {
    auto itr = phonebook.find( iPhoneNo );
    if ( itr != phonebook.end() ) {
        findQ.push(itr -> second);
    } else {
        findQ.push("not found");
    }
}

int main() {
    int iN; //Number of queries
    int iPhoneNo;
    string sAction, sPerson;
    queue<string> findQ;
    
    map< int, string > phonebook;
    
    cin >> iN;
    if ( iN >= 1 && iN <= 105) {
        for ( int i = 0; i < iN; i++ ) {
            cin >> sAction;
            if ( sAction == "add" ) {
                cin >> iPhoneNo >> sPerson;
                phonebook.erase( iPhoneNo );
                phonebook.insert(pair< int, string > ( iPhoneNo, sPerson ));
            } else if ( sAction == "del" ) {
                cin >> iPhoneNo;
                phonebook.erase( iPhoneNo );
            } else if ( sAction == "find" ) {
                cin >> iPhoneNo;
                find( phonebook, iPhoneNo, findQ);
            }
        }
    }
    while( !findQ.empty() ) {
        cout << findQ.front() << endl;
        findQ.pop();
    }
}
    
