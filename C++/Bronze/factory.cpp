// factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    std::ifstream read("factory.in");
    int n;
    read >> n;

    vector<int> outgoing(n);
    for (int i = 0; i < n - 1; i++) {
        int s1, s2;
        read >> s1 >> s2;
        s1--;
        outgoing[s1]++;
    }

    vector<int> sink;
    for (int i = 0; i < n; i++) {
        if (outgoing[i] == 0) {
            sink.push_back(i + 1);
        }
    }

    std::ofstream out("factory.out");
    if (sink.size() == 1) {
        out << sink[0] << "\n";
    }
    else {
        out << -1 << "\n";
    }
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
