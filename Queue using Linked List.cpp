#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL,*rear=NULL;
struct node *new_node,*temp;

void enqueue(int data){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    
    if(front==NULL && rear==NULL){
        front = rear = new_node;
    }
    else{
        rear->next=new_node;
        rear=new_node;
    }
}

void dequeue(){
    if(front==NULL && rear==NULL){
        printf("The queue is empty. Elements cannot be delelted");
    }
    
    else{
        temp=front;
        printf("Deleting element= %d\n",front->data);
        front=front->next;
        free(temp);  
    }
}

void peek(){
	if(front!=NULL){
		printf("\nThe first data= %d\n",front->data);
	}
	else{
		printf("No elements are there");
	}
}

void display(){
    if(front==NULL && rear==NULL){
        printf("the queue is empty");
    }
    else{
    temp=front;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
        }
    printf("NULL\n");
    }
}

int main()
{
    
enqueue(0);
enqueue(1);
enqueue(2);
enqueue(3);

display();
peek();

dequeue();
dequeue();
peek();
dequeue();
dequeue();
peek();
    return 0;
}

