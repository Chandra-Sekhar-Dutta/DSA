#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* previous;
    struct node* next;
};

struct node* head = NULL;
struct node* new_Node;
struct node* temp,*temp2;
struct node* insert_node;
struct node* insert_after_position;
struct node* insert_nodeAtTail;
struct node* last_node_after_deletion;

void create_node(int data) {
    new_Node = (struct node*)malloc(sizeof(struct node));

    new_Node->data = data;
    new_Node->next = NULL;
    new_Node->previous = NULL;

    if (head == NULL) {
        head = new_Node;
    }
    else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_Node;
        new_Node->previous = temp;
        temp=new_Node;
    }
}

void insertNode(int data, int position) {
    insert_node = (struct node*)malloc(sizeof(struct node));
    insert_node->data = data;

    if (position == 0) {
        insert_node->next = head;
        insert_node->previous = NULL;
        if (head != NULL) {
            head->previous = insert_node; // Update the previous of the current head
        }
        head = insert_node;
    }
    else {
        temp = head;
        for (int i = 0; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL) {
            insert_node->previous = temp;
            insert_node->next = temp->next;
            if (temp->next != NULL) {
                temp->next->previous = insert_node;
            }
            temp->next = insert_node;
        }
    }
}

void insertAfterPosition(int data, int position) {
    insert_after_position = (struct node*)malloc(sizeof(struct node));
    insert_after_position->data = data;

    temp = head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        insert_after_position->previous = temp;
        insert_after_position->next = temp->next;
        if (temp->next != NULL) {
            temp->next->previous = insert_after_position;
        }
        temp->next = insert_after_position;
    }
}

void insertAtEnd(int data) {
    insert_nodeAtTail = (struct node*)malloc(sizeof(struct node));
    insert_nodeAtTail->data = data;
    insert_nodeAtTail->next = NULL;
    insert_nodeAtTail->previous = NULL;

    if (head == NULL) {
        head = insert_nodeAtTail;
    }
    else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = insert_nodeAtTail;
        insert_nodeAtTail->previous = temp;
    }
}

void Delete_Node(int position) {
    if (head == NULL) {
        printf("No node is there\n");
    }
    else if (position == 0) {
        temp = head;
        head = head->next;
        if (head != NULL) {
            head->previous = NULL;
        }
        free(temp);
    }
    else {
        temp = head;
        for (int i = 0; i < position && temp != NULL; i++) {
            last_node_after_deletion = temp;
            temp = temp->next;
        }
            last_node_after_deletion->next = temp->next;
            temp->next->previous = last_node_after_deletion;
            free(temp);
    }
}


void Delete_Node_at_End(){
    last_node_after_deletion=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=NULL){
        last_node_after_deletion=temp;
        temp=temp->next;
    }
    last_node_after_deletion->next=NULL;
    free(temp);
}

void show() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

int main() {
    create_node(1);
    create_node(2);
    create_node(3);
    printf("Printing the Doubly Linked List-\n");
    show();

    insertNode(4, 0); // Insert at the beginning
    printf("Printing the Doubly Linked List afer inserting node at the beginning-\n");
    show();

    insertNode(5, 2); // Insert at any position
    printf("Printing the Doubly Linked List afer inserting node at any position-\n");
    show();

    insertAfterPosition(4, 2); // Insert after a position
    printf("Printing the Doubly Linked List afer inserting node after any position-\n");
    show();

    insertAtEnd(8); // Insert at the end
    printf("Printing the Doubly Linked List afer inserting node at the end-\n");
    show();
    
    Delete_Node(0);//deleting at head
    printf("Printing the Doubly Linked List afer deleting node at the head-\n");
    show();
    
    Delete_Node_at_End();//deleting at end
    printf("Printing the Doubly Linked List afer deleting node at the end-\n");
    show();
    
    Delete_Node(3);//deleting at any position
    printf("Printing the Doubly Linked List afer deleting node at any position-\n");
    show();

    return 0;
}
