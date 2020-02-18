// MarLibs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SinglyLinked.h"

int main()
{
    std::cout << "Singly Linked!\n";

    SinglyLinked *sl = new SinglyLinked("Singly");
    for (int i = 0; i < 26; i++)
        sl->Insert(i);

    sl->print(true);
    cout << (sl->Search(5) ? "Found" : "Not Found") << endl;
    sl->reverse();
    sl->print(false);

    cout << "Midpoint element:" << sl->FindMid() << endl;

    sl->DeleteAtPosition(0);
    sl->print(false);

    sl->TieLoop(12, 2);
    cout << "Is looped:" << (sl->IsLoop() ? "Yes" : "No") << endl;
    sl->Untie();
    cout << "Is looped:" << (sl->IsLoop() ? "Yes" : "No") << endl;
    //sl->print(false);

    delete sl;

    return 0;
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
