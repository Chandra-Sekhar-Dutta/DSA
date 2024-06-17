#include <stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

struct node *front=NULL,*rear=NULL,*newnode,*temp;

void enque(int data){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    
    if (rear==NULL){
        rear=front=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    rear->next=front;//here circular queue is established.
}

void DEQUE(){
    
    if(front==rear){
        printf("\nThe circular queue is empty");
    }
    
    else{
    temp=front;
    printf("\nDeleting %d",front->data);
    front=front->next;
    free(temp);
    }
}

void peek(){
    if(front!=rear){
    printf("\nThe top most data=%d",front->data);
    }
    else{
        printf("\nNo data");
    }
}

void display(){
    temp=front;
    while(temp->next!=front){
        printf("%d->",temp->data);
        temp=temp->next;
        if(temp==front){
            break;
        }
    }
    printf("%d->%d(front)",temp->data,front->data);
}

int main()
{
    enque(0);
    enque(1);
    enque(2);
    enque(3);
    
    display();
    peek();
    
    DEQUE();
    peek();
    DEQUE();
    DEQUE();
    DEQUE();
    peek();


    return 0;
}

