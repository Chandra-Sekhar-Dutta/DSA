//Single Linked List

#include <stdio.h>
#include<stdlib.h>

struct node{
  char data;
  struct node *next;
};

int position=0;

struct node *head=NULL,*temp,*nodeBeforeTemp;

void addNode(char data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
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
        temp=newNode;
    }
}

void insertNodeAtAnyPositon(char data,int position){
    
    struct node *insertNode=(struct node*)malloc(sizeof(struct node));
    insertNode->data=data;
    insertNode->next=NULL;
    
    temp=head;
    
    if(head==NULL){
        head=insertNode;
    }
    
    else if(position==0){
            insertNode->next=head;
            head=insertNode;
        }
    
    else{

        if(temp==NULL){
            printf("Insertion not possible");
        }
        
        else{
            for(int i=0;i<position-1 && temp!=NULL;i++){
                temp=temp->next;
            }
            insertNode->next=temp->next;
            temp->next=insertNode;
            temp=insertNode;
        }
    }
}

void insertAtLast(char data){
    struct node *LastNode=(struct node*)malloc(sizeof(struct node));
    LastNode->data=data;
    LastNode->next=NULL;
    
    if(head==NULL){
        head=LastNode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=LastNode;
    }
}

void DeleteAtAnyPosition(int position){
    temp=head;
    if(head==NULL){
        printf("deletion not possible");
    }
    else {
        if(position==0){
            temp=head;
            head=head->next;
            free(temp);
        }
        else{
            nodeBeforeTemp = NULL; // Initialize nodeBeforeTemp
            for (int i = 0; i < position && temp != NULL; i++) {
                nodeBeforeTemp = temp;
                temp = temp->next;
        }
        nodeBeforeTemp->next=temp->next;
        free(temp);
    }
    }
}
void DeleteAtLast(){
    temp=head;
    while(temp->next!=NULL){
        nodeBeforeTemp = temp;
        temp=temp->next;
    }
    nodeBeforeTemp->next=NULL;
    free(temp);
}

void searchByPosition(int position) {
    int currentPosition = 0;  
    temp = head;
    int dataFound = 0;

    while(temp != NULL) {
        if(position == currentPosition) {
            printf("Data found at %d = '%c'\n", position, temp->data);
            dataFound = 1;
            break; 
        }
       
        temp = temp->next;
        currentPosition++;
    }

    if(!dataFound) {
        printf("Data not found at position %d\n", position);
    }
}

void searchByData(char data) {
    temp = head;
    
    int dataFound = 0;

    while (temp != NULL) {
        if (temp->data == data) {
            printf("Data '%c' found at position %d\n", temp->data, position);
            dataFound = 1;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!dataFound) {
        printf("Data '%c' not found\n",data);
    }
}

void print(){
    temp=head;
    while(temp!=NULL){
        printf("%c->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    addNode('a');
    addNode('1');
    addNode('b');
    addNode('2');
    print();
    
    insertNodeAtAnyPositon('F',0);
    print();
    insertNodeAtAnyPositon('S',2);
    print();
    insertAtLast('L');
    print();
    
    searchByPosition(2);
    searchByPosition(8);
    searchByData('a');
    searchByData('z');
    
    DeleteAtAnyPosition(0);
    print();
    DeleteAtAnyPosition(2);
    print();
    DeleteAtLast();
    print();

    return 0;
}

