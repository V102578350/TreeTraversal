template <class T>
class Node 
{
private:
    Node* fLHS;
    Node* fRHS;
    T fValue;

public:
    Node(T aValue) 
    {
        fLHS = nullptr;
        fRHS = nullptr;
        fValue = aValue;
    }

    T value() 
    {
        return fValue;
    }

    void setLHS(Node& aNode) 
    {
        fLHS = &aNode;
        aNode.setRHS(*this);
    }

    void setRHS(Node& aNode)
    {
        fRHS = &aNode;
        aNode.setLHS(*this);
    }

    Node& lhs() 
    {
        return *fLHS;
    }

    Node& rhs() 
    {
        return *fRHS;
    }
};