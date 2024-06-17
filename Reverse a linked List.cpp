
#include <stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};
struct node*head=NULL;

void createNode(){
    int data;
    printf("Enter the data=");
    scanf("%d",&data);
    
    struct node *NewNode=(struct node*)malloc(sizeof(struct node));
    NewNode->data=data;
    NewNode->next=NULL;
    
    if(head==NULL){
        head=NewNode;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=NewNode;
        temp=NewNode;
    }
}

struct node * reverse_List( struct node * head){
    struct node *prev=NULL,*current=head,*nextptr;
    
//	prev ptr is ahead of the head pointer
//    current ptr is storing the head pointer
//    nextptr will store the address of the next node of the head pointer
//    
//    iteratively, every pointer will shift to the direction of traversal by reversing the links of the list.
//    then it will return the prev pointer and NewHead will store the prev ptr.

    while(current!=NULL){
        nextptr=current->next;
        current->next=prev;
        prev=current;
        current=nextptr;
    }
    return prev;
}

void show(struct node* head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    createNode();
    createNode();
    show(head);
    struct  node *NewHead=reverse_List(head);
    show(NewHead);

    return 0;
}

