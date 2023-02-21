#include <iostream>

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtHead(Node *&head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

int main() {
    Node *head = nullptr;

    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);

    Node *temp = head;
    
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}