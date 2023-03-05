#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void LinkedList::print()    
{
    Node *dummy = head;
    cout << "head of the line" << endl ;
    cout << "___________    _________" << endl ;
    for (int i = 0; i < size; i++){
        cout << "\t  | " << dummy->getvalue() << " |" << endl ;
        dummy = dummy->getnext();
    }
    cout << "-----------    ---------" << endl ;
    cout << "last in a row" << endl ;
    cout << "Queue : " << size << endl ;
    cout << endl;
    
}

void LinkedList::insert(Node *newNode, int index)
{
    if (size == 0){
        head = newNode ;
        tail = newNode ;
        head->setnext(nullptr);
        head->setprev(nullptr);
        tail->setnext(nullptr);
        tail->setprev(nullptr);
        size++ ;
    }
    else if (size != 0 && index >= 0){
        if (abs(index) > size){
        cout << "Error!!!!!!! please thy agian." << endl;
        }
        else if (index == 0){
            newNode->setnext(head);
            newNode->setprev(nullptr);
            head->setprev(newNode);
            head = newNode ;
            size++ ;
        }
        else if (index < size && index > 0){
            Node *dummy = head ;
            for (int i = 0 ; i < index-1 ; i++){
                dummy = dummy->getnext();
            }
            Node *nextOFdummy = dummy->getnext() ;
            dummy->setnext(newNode);
            newNode->setnext(nextOFdummy);
            newNode->setprev(dummy);
            nextOFdummy->setprev(newNode);
            size++ ;
        }
        else if (index == size){
            newNode->setnext(nullptr);
            newNode->setprev(tail);
            tail->setnext(newNode);
            tail = newNode ;
            size++ ;
        }
    }
    else if (size != 0 && index < 0){
        if (abs(index) > size){
        cout << "Error!!!!!!! please thy agian." << endl;
        }
        else if (abs(index) < size){
            Node *dummy = tail ;
            for (int i = index+1 ; i < 0 ; i++){
                dummy = dummy->getprev();
            }
            Node *prevOFdummy = dummy->getprev() ;
            prevOFdummy->setnext(newNode);
            newNode->setnext(dummy);
            newNode->setprev(prevOFdummy);
            dummy->setprev(newNode);
            size++ ;
        }
        else if (abs(index) == size){
            newNode->setnext(head);
            newNode->setprev(nullptr);
            head->setprev(newNode);
            head = newNode ;
            size++ ;
        }
    }

}

void LinkedList::remove(int index)
{
    if (index >= 0){
        if (abs(index) > size-1){
        cout << "Error!!!!!!! I cant remove." << endl;
        }
        else if (index == 0){

            Node *nexthead = head->getnext();
            nexthead->setprev(nullptr);
            head->setnext(nullptr);
            head = nexthead ;
            size-- ;
        }
        else if (index < size-1 && index > 0){
            Node *dummy = head;
            for (int i = 0; i < index ; i++){
                dummy = dummy->getnext();  
            }
            Node *nextOFdummy = dummy->getnext() , *prevOFdummy = dummy->getprev();
            prevOFdummy->setnext(nextOFdummy);
            nextOFdummy->setprev(prevOFdummy);
            dummy->setnext(nullptr);
            dummy->setprev(nullptr);
            size-- ;
        }
        else if (index == size-1){
            Node *prevtail = tail->getprev();
            prevtail->setnext(nullptr);
            tail->setprev(nullptr);
            tail = prevtail ;
            size-- ;
        }
    }
    else if (index < 0){
        if (abs(index) > size){
        cout << "Error!!!!!!! I cant remove." << endl;
        }
        else if (index == -1){
            Node *prevtail = tail->getprev();
            prevtail->setnext(nullptr);
            tail->setprev(nullptr);
            tail = prevtail ;
            size-- ;
        }
        else if (abs(index) < size && index != -1){
            Node *dummy = tail ;
            for (int i = index+1 ; i < 0 ; i++){
                dummy = dummy->getprev();
            }
            Node *nextOFdummy = dummy->getnext() , *prevOFdummy = dummy->getprev();
            prevOFdummy->setnext(nextOFdummy);
            nextOFdummy->setprev(prevOFdummy);
            dummy->setnext(nullptr);
            dummy->setprev(nullptr);
            size-- ;
        }
        else if (abs(index) == size){
            Node *nexthead = head->getnext();
            nexthead->setprev(nullptr);
            head->setnext(nullptr);
            head = nexthead ;
            size-- ;
        }
    }
}

void LinkedList::append(Node *newNode)
{
    newNode->setnext(nullptr);
    newNode->setprev(tail);
    tail->setnext(newNode);
    tail = newNode ;
    size++ ;
}

Node *LinkedList::gethead()
{
    return head ;
}

Node *LinkedList::gettail()
{
    return tail ;
}

int LinkedList::getsize()
{
    return size;    
}
