#include<iostream>

using namespace std;

class node;
node *head=NULL;
node *temp=NULL;

class node{
    public:
    
  int data;
  node *next;

void createNode(int value){
    node *newNode=new node();
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    
    else{
        temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
        temp->next=newNode;
        }
    }
    
    node *reverseLinkedList(node *head)// here we will traverse using recursion
    {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        node *reverse=reverseLinkedList(head->next);//it is doing the task of traversing without temp pointer
        head->next->next=head;
        // this means the 2nd last node becomes the head by recursion and its next pointer points to the last pointer and its next pointer stores the address of the last node. 
        // hence the link is reversed.
        head->next=NULL;
        // since the last node link is reversed, there is no meaning of the link between the head and the last node in the forward direction so the link is destroyed.
        // this process continues recursively
        
        return reverse;
    }
    
    void printList(node *head){
        temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

};

int main(){
    node N;
    N.createNode(0);
    N.createNode(1);
    N.createNode(2);
    N.createNode(3);
    N.createNode(4);

    N.printList(head);
    
    node *reversedHead=N.reverseLinkedList(head);
    N.printList(reversedHead);
}
