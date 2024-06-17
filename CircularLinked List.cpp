#include<stdlib.h>
#include<stdio.h>

struct node{
  int data;
  struct node *next;
};

int position=0;

struct node *head=NULL,*new_head,*new_Node,*temp,*temp2,*new_node,*new_nodeAt_tail,*node_before_deletion,*node_before_lastNode;

void newNode(int data){
    new_Node=(struct node*)malloc(sizeof(struct node));
    new_Node->data=data;
    
    if(head==NULL){
        head=new_Node;
        head->next=head;
    }
    
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new_Node;
        new_Node->next=head;
    }
}

void insertNewNode(int data, int position){
    new_Node=(struct node*)malloc(sizeof(struct node));
    new_Node->data=data;
    
    if(temp==NULL){
        printf("Insertion not possible");
    }
    
    else if(head==NULL){
        head=new_Node;
        head->next=head;
    }
    
    else if(position==0){
        new_Node->next=head;
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=new_Node;
        head=new_Node;
    }
    
     else {
         temp=head;
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }
        
        new_Node->next=temp->next;
        temp->next=new_Node;
        temp=new_Node;
     }
  }
  
  void insertAtTail(int data){
      new_nodeAt_tail=(struct node*)malloc(sizeof(struct node));
      new_nodeAt_tail->data=data;
      
      temp=head;
      while(temp->next!=head){
          temp=temp->next;
      }
      new_nodeAt_tail->next=head;
      temp->next=new_nodeAt_tail;
  }
  
void delete_at_position(int position){
    
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
    }
    
    else if (position == 0) {
    temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = head->next;
    new_head = head->next;

    free(head);
    head = new_head;
    }
    
    else{
        for(int i=0;i<=position;i++){
            node_before_deletion=temp;
            temp=temp->next;
        }
        node_before_deletion->next=temp->next;
        free(temp);
    }
}

void delete_at_end(){
    temp=head;
    while(temp->next!=head){
        node_before_lastNode=temp;
        temp=temp->next;
    }
    node_before_lastNode->next=head;
    free(temp);
}

void show(){
    temp=head;
    while(temp->next!=head){
        printf("%d->",temp->data);//the last node will not be printed because the condition in the while loop will be false
        temp=temp->next;
        if(temp==head){
        break;
        }
    }
    printf("%d->%d(head)\n\n",temp->data,head->data);//last node is printed separatly
}

// Another way to traverse the circular LL->

//void print_list() {
//    struct node* temp = head;
//
//    // Check if the list is empty
//    if (temp == NULL) {
//        printf("List is empty.\n");
//        return;
//    }
//
//    // Traverse the circular linked list and print the data
//    do {
//        printf("%c->", temp->data);
//        temp = temp->next;
//    } while (temp!= head);
//
//    printf("%c(head)",temp->data);
//}


void free_list() {
    temp = head;
    while (temp->next != head) {
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    if(temp->next==head){
    free(temp); // Free the last node, which points back to the head
    head = NULL; // Set head to NULL to indicate that the list is empty
    }
}


int main(){
    newNode(0);
    newNode(1);
    newNode(2);
    newNode(3);
    newNode(4);
    printf("Printing the circular linked list->\n");
    show();
    
    insertNewNode(8,0);
    printf("Printing the circular linked list after inserting a node at head and updating the head->\n");
    show();
    
    insertNewNode(5,2);
    printf("Printing the circular linked list afer inserting a node at any position->\n");
    show();
    
    insertAtTail(9);
    printf("Printing the circular linked list after inserting a node at the tail->\n");
    show();
    
    delete_at_position(0);
    printf("Printing the circular linked list after deleting a node at the head->\n");
    show();
    
    delete_at_position(2);
    printf("Printing the circular linked list after deleting a node at any position->\n");
    show();
    
    delete_at_end();
    printf("Printing the circular linked list after deleting a node at the end->\n");
    show();

    free_list();
    
}
