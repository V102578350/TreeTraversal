#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

template <class DataType>
class TreeNode
{
public:
    typedef TreeNode<DataType> Node;

private:
    DataType fValue;
    std::vector<Node*> fChildren;

    TreeNode(); //sentinal constructor (for private use only)

public:
    static Node NIL;


    //default construtor
    TreeNode(DataType aValue);
    //copy constructor
    TreeNode(TreeNode<DataType>* aNode);

    //attach nodes to tree
    void attachNode(Node aNode);
    //returns size of vector
    int getSize();
    //removes node from the tree node with the first occurence of aValue
    void removeNode(DataType aValue);
    //get node by index
    TreeNode<DataType>* getChildByIndex(int aIndex);
    //dfs
    std::string dfs();
    //returns value of this node
    DataType getValue();


};
template<class DataType>
TreeNode<DataType> TreeNode<DataType>::NIL;

template<class DataType>
TreeNode<DataType>::TreeNode() 
{
    fValue = DataType();
}

template<class DataType>
TreeNode<DataType>::TreeNode(DataType aValue) 
{
    fValue = aValue;
}

template<class DataType>
TreeNode<DataType>::TreeNode(TreeNode<DataType>* aNode)
{
    fValue = aNode->getValue();
    for(size_t i = 0; i < aNode->getSize(); i++)
    {
        fChildren.push_back(aNode->getChildByIndex(i));
    }
}

template<class DataType>
void TreeNode<DataType>::attachNode(Node aNode)
{
    fChildren.push_back(new Node(aNode));
}

template<class DataType>
DataType TreeNode<DataType>::getValue()
{
    return fValue;
}

template<class DataType>
int TreeNode<DataType>::getSize() 
{
    return fChildren.size();
}

template<class DataType>
void TreeNode<DataType>::removeNode(DataType aValue) 
{
    for(size_t i = 0; i < getSize(); i++)
    {
        if(fChildren[i] == aValue)
        {
            fChildren.erase(fChildren.begin() + i);
        }
    }
}

template<class DataType>
TreeNode<DataType>* TreeNode<DataType>::getChildByIndex(int aIndex)
{
    if(aIndex < getSize())
        return fChildren[aIndex];
    else
        throw std::out_of_range("Parameter index was out of range.");
}

template<class DataType>
std::string TreeNode<DataType>::dfs()
{
    std::string result = getValue() + " ";

    for(size_t i = 0; i < getSize(); i++)
    {
        result.append(getChildByIndex(i)->dfs());
        std::cout << getChildByIndex(i)->getSize() << std::endl;
    }

    return result;
}
