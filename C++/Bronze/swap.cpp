// swap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

void ascii() {

    cout << "/=========================\\\n";
    cout << "|                         |\n";
    cout << "|  M   M     A     X   X  |\n";
    cout << "|  MM MM    A A     X X   |\n";
    cout << "|  M M M   AAAAA     X    |\n";
    cout << "|  M   M   A   A    X X   |\n";
    cout << "|  M   M   A   A   X   X  |\n";
    cout << "|                         |\n";
    cout << "\\=========================/\n";

}

int changeOrder(int x, int a1, int a2, int b1, int b2) {
    if (!(x < a1 || x > a2)) {
        int xd1 = x - a1;
        x = a2 - xd1;
    }
    if (x < b1 || x > b2) {
        return x;
    }
    int xd2 = x - b1;
    return b2 - xd2;
}

int main()
{
    //ifstream cin("swap.in");
    //ofstream cout("swap.out");
    
    int n, k;
    cin >> n >> k;

    int a1, a2;
    int b1, b2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    a1--; a2--; b1--; b2--;

    vector<int> cows(n);

    vector<int> cycleLength(n,0);
    
    for (int i = 0; i < n; i++) {
        int c = i;
        int original = c;
        while (c != original || cycleLength[i] == 0) {
            c = changeOrder(c, a1, a2, b1, b2);
            cycleLength[i] += 1;
        }
    }

    vector<int> shuffled(n, 0);
    for (int i = 0; i < n; i++) {
        int loc = i;
        int cyclesLeft = k % cycleLength[i];
        for (int j = 0; j < cyclesLeft; j++) {
            loc = changeOrder(loc, a1, a2, b1, b2);
        }
        shuffled[loc] = i + 1;
    }

    for (int cow : shuffled) {
        cout << cow << "\n";
    }

    //ascii();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
