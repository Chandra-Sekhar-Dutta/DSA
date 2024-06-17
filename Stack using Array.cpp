#include <stdio.h>
#define Size 5

int a,top=-1;
int stack[Size];

void push(){
    
    printf("Enter the data=");
    scanf("%d",&a);
    
    if(top>=Size-1){
        printf("\nOverflow\n\n");
    }
    
    else{
        top++;
        stack[top]=a;
    }
}

void peek(){
    if(top==-1){
        printf("No elements in the stack");
    }
    else{
        printf("\nThe top element is= %d\n\n",stack[top]);
    }
}

void display(){
    
    if(top==-1){
        printf("The stack is empty");
    }
    
    else{
    printf("\nShowing the elements of the stack-\n");
    for(int i=top;i>=0;i--){
        printf("%d\t",stack[i]);
    }
    printf("\n");
    }
}

void pop(){
    int deleted_Value;
    if(top==-1){
        printf("\nUnderflow");
    }
    
    else{
        deleted_Value=stack[top];
        top--;//here the value becomes a garbage value which can be rewritten later.
        printf("the deleted Value is=%d\n",deleted_Value);
    }
}

int main()
{
    push();
    push();
    push();
    push();
    push();
    push();
    display();
    peek();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    
    return 0;
}

