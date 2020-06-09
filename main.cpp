#include <iostream>
#include "Node.h"
#include <string>

using namespace std;

int main(int argc, char ** args)
{
    typedef Node<string> StringNode;

    //initialize 3 nodes objects
    StringNode n1("Node-1");
    StringNode n2("Node-2");
    StringNode n3("Node-3");

    //test
    n1.setRHS(n2);
    n2.setRHS(n3);

    cout << n1.value() << endl;
}