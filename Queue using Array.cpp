#include <stdio.h>
#define N 5


int Queue[N];
int front =-1;int rear = -1;

void Enqueue(int data){
    if(rear==N-1){
    printf("Queue is full, data cannot be entered.");
        }
    else if(front==-1 && rear==-1){
    front=rear=0;
    Queue[rear]=data;
        }
    else{
    rear++;
    Queue[rear]=data;
        }
}

void display(){
    if(front==-1 && rear==-1){
        printf("The Queue is empty.");
    }
    else{
        printf("The elements of the queue is -\n");
        for(int i=front;i<=rear;i++){
            printf("%d\t",Queue[i]);
        }
        printf("\n");
    }
}

void peek(){
    if(front==-1 &&rear==-1){
        printf("\n\nQueue is empty.");
    }
    else{
        printf("\nThe first value is=%d\n",Queue[front]);
    }
}

void Deque(){
    if(front==-1 &&rear==-1){
        printf("\nQueue is empty already as the last element is deleted.");
    }
    else if(front == rear){
        printf("\nOnly one element is left in the queue and that is %d\n",Queue[front]);
        front=rear=-1;
    }
    else{
        printf("\nThe deleted element is = %d\n",Queue[front]);
        front++;
    }
}


int main()
{

Enqueue(0);
Enqueue(1);
Enqueue(2);
Enqueue(3);

display();
peek();

Deque();

peek();

Deque();
Deque();
Deque();
Deque();
peek();

    return 0;
}

