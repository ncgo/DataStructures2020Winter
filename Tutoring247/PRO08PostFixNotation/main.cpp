#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

void asignacionStack( stack <int> &miStack, int &iX, int &iY) {
	iX = miStack.top();
	miStack.pop();
	iY = miStack.top();
	miStack.pop();
}

void asignacionQueue( queue <int> &miQ, int &iX, int &iY) {
	iX = miQ.front();
	miQ.pop();
	iY = miQ.front();
	miQ.pop();
}

void asignacionPQueue( priority_queue < int, vector<int>, greater<int> > &miPQ, int &iX, int &iY) {
	iX = miPQ.top();
	miPQ.pop();
	iY = miPQ.top();
	miPQ.pop();
}

int main() {
  string data;
	int d, iX, iY;
	priority_queue< int, vector<int>, greater<int> > miPQ;
	stack <int> miStack;
	queue <int> miQ;
	do {
		while( data != "\n") {
			cin >> data;
			if( data == "+" ) {
				//Stack
				asignacionStack( miStack, iX, iY );
				miStack.push(iY + iX);
				//Queue
				asignacionQueue( miQ, iX, iY );
				miQ.push(iY + iX);
				//Priority Queue
				asignacionPQueue( miPQ, iX, iY);
				miPQ.push(iY + iX);
			} else if( data == "-" ) {
					//Stack
					asignacionStack( miStack, iX, iY );
					miStack.push(iY - iX);
					//Queue
					asignacionQueue( miQ, iX, iY );
					miQ.push(iY - iX);
					//Priority Queue
					asignacionPQueue( miPQ, iX, iY);
					miPQ.push(iY - iX);
			} else if( data == "/" ) {
					asignacionStack( miStack, iX, iY );
					miStack.push(iY / iX);
					//Queue
					asignacionQueue( miQ, iX, iY );
					miQ.push(iY / iX);
					//Priority Queue
					asignacionPQueue( miPQ, iX, iY);
					miPQ.push(iY / iX);
			} else if( data == "*" ) {
					asignacionStack( miStack, iX, iY );
					miStack.push(iY * iX);
					//Queue
					asignacionQueue( miQ, iX, iY );
					miQ.push(iY * iX);
					//Priority Queue
					asignacionPQueue( miPQ, iX, iY);
					miPQ.push(iY * iX);
			} else {
				istringstream iss (data);
				iss >> d;
				miStack.push(d);
				miQ.push(d);
				miPQ.push(d);
			}
		}
		cout << miStack.top() << " " << miQ.front() << " " << miPQ.top() << endl;
	} while( data != "#" );
	

}
