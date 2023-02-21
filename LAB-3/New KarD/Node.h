#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int value;
    Node *prevaddr = nullptr;
    Node *nextaddr = nullptr;

public:
    Node();
    Node(int value, Node *newprevaddr, Node *newnextaddr);
    int getValue();
    void setValue(int newValue);
    void setprevaddr(Node *newprevaddr);
    void setnextaddr(Node *newnextaddr);
    Node *getprevaddr();
    Node *getnextaddr();
};

#endif // NODE_H
