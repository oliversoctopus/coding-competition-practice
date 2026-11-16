//============================================================================
// Name        : 235num.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int> pq;
	pq.push(9);
	pq.push(10);
	pq.push(6);
	cout << pq.top() << " ";
	pq.pop();
	cout << pq.top() << " ";
}
