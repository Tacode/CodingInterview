#include <iostream>
#include "MinStack.h"
using namespace std;

int main(int argc, char *argv[])
{
    MinStack<int> *minstack1 = new MinStack<int>(100);
    minstack1->push(4);
    minstack1->push(2);
    minstack1->push(5);
    minstack1->push(3);
    cout << "size: " << minstack1->size() << endl;
    cout << "min: " << minstack1->min_value() << endl;
    minstack1->pop();
    cout << "size: " << minstack1->size() << endl;
    cout << "min: " << minstack1->min_value() << endl;
    minstack1->pop();
    cout << "size: " << minstack1->size() << endl;
    cout << "min: " << minstack1->min_value() << endl;
    minstack1->pop();
    cout << "size: " << minstack1->size() << endl;
    cout << "min: " << minstack1->min_value() << endl;

    MinStack<double> *minstack2 = new MinStack<double>(100);
    minstack2->push(4.0);
    minstack2->push(2.0);
    minstack2->push(5.0);
    minstack2->push(3.0);
    cout << "size: " << minstack2->size() << endl;
    cout << "min: " << minstack2->min_value() << endl;
    minstack2->pop();
    cout << "size: " << minstack2->size() << endl;
    cout << "min: " << minstack2->min_value() << endl;
    minstack2->pop();
    cout << "size: " << minstack2->size() << endl;
    cout << "min: " << minstack2->min_value() << endl;
    minstack2->pop();
    cout << "size: " << minstack2->size() << endl;
    cout << "min: " << minstack2->min_value() << endl;

    return 0;
}
