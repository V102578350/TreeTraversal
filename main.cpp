

#include <iostream>
#include <string>
#include "TreeNode.h"

using namespace std;

int main()
{
    typedef TreeNode<string> StringTreeNode;

    StringTreeNode a1("A1");
    StringTreeNode b1("B1");
    StringTreeNode b2("B2");
    StringTreeNode b3("B3");
    StringTreeNode c1("C1");
    StringTreeNode c2("C2");
    StringTreeNode d1("D1");


    //Create The following tree structure with the given elements

    //Tree Structure
    //      A1
    // B1   B2   B3
    //     C1     D1

    a1.attachNode(b1);
    a1.attachNode(b2);
    a1.attachNode(b3);
    b2.attachNode(c1);
    b2.attachNode(c2);
    c1.attachNode(d1);
    
    cout << "[ > ] Depth First Search Operation Results:" << endl;
    cout << a1.dfs() << endl;
    return 0;
}