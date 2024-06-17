
#include <stdio.h>

struct University{
  char Name[10];
  int no_of_students;
};

struct University U1;


void Get(struct University *U){
    printf("Enter the University name:");
    scanf("%s",U->Name);
    printf("Enter the Number of the students:");
    scanf("%d",&U->no_of_students);
}

void show(struct University U){
    printf("The name is %s",U.Name);
    printf("\nThe number of students in the college is %d",U.no_of_students);
}

int main()
{
    struct University *U=&U1;
    Get(&U1);
    show(U1);
    return 0;
}


