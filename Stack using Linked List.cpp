#include <stdio.h>
#include<stdlib.h>


struct node{
  int data;
  struct node *link;
};

struct node *top=NULL;
struct node *new_node;
struct node *temp;

void push(int data){
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->link=top;
    
    //here the linked list is in reverse order, that means, the flow of link is not from the top(or head)
    //to the tail. Here the next of new_node points to the previous node. It is done to get the O(1) time complexity in stack.
    //Here to perform any stack operation, traverse operation is not needed.
    
    top=new_node;//The top pointer is updated everytime when a new node is created and we don't have to maintain a tail pointer.
}

void peek(){
    if(top==NULL){
        printf("No elements in the stack");
    }
    else{
        printf("\nThe top element is %d\n",top->data);
    }
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
    } 
    else {
        int popped_data = top->data;
        temp = top;
        top = top->link;
        printf("\nThe deleted data is %d",temp->data);
        free(temp); // Free the memory of the popped node
    }
}

void display(){
    temp=top;
    if(top==NULL){
        printf("Stack is empty");
    }
    
    else{
        printf("The stack using Linked List is-\n");
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->link;
        }
        printf("\n(The first value of the Stack is reached through traverse operation)\n");
    }
}

int main()
{
    push(0);
    push(1);
    push(2);
    push(3);
    push(4);
    
    display();
    peek();
    
    pop();
    pop();
    peek();
    return 0;
}

