#include<stdio.h>
struct Structure{
  int a;
  char b;
  struct Structure *ptr;
};

int main(){
    struct Structure S1,S2;
    
    printf("Enter the int value of a:");
    scanf("%d",&S2.a);
    printf("Enter the character value of b:");
    scanf(" %c",&S2.b);
    
    S1.ptr=NULL;
    
    S1.ptr=&S2;
    
    printf("The value of 'a' in S2 is %d",S1.ptr->a);
    printf("\nThe value of 'b' in S2 is %c",S1.ptr->b);
}
