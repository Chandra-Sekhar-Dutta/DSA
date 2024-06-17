#include<stdio.h> 
#include<stdlib.h>
int main(){
    int n,*ptr1,*ptr2,i;
    
    printf("Enter the number of elements to be entered=");
    scanf("%d",&n);
    
    ptr1=(int*)malloc(n*sizeof(int));
    ptr2=(int*)calloc(n,sizeof(int));
    
    
    printf("The inputs of the array1 are-\n");
    for(i=0;i<n;i++){
        scanf("%d",ptr1+i);
    }
    
    printf("The inputs of the array2 are-\n");
    for(i=0;i<n;i++){
        scanf("%d",ptr2+i);
    }
    
    printf("printing array1 =\n");
    for(i=0;i<n;i++){
        printf("%d\t",*(ptr1+i));
    }
    
    printf("\nprinting array2 =\n");
    for(i=0;i<n;i++){
        printf("%d\t",*(ptr2+i));
    }
    
    int m;
    printf("\n\nReallocating memory.\n");
    printf("Enter the value of m, which will be multiplied with sizeof(int):");
    scanf("%d",&m);
    
    ptr1=(int*)realloc(ptr1,m*sizeof(int));
    printf("\nEnter the elements=\n");
    for(i=0;i<m;i++){
        scanf("%d",ptr1+i);
    }
    
    printf("The elements are-\n");
    for(i=0;i<m;i++){
        printf("%d\t",*(ptr1+i));
    }
    ptr2=(int*)realloc(ptr2,m*sizeof(int));
     printf("\nEnter the elements=\n");
    for(i=0;i<m;i++){
        scanf("%d",ptr2+i);
    }
    
    printf("\nThe elements are-\n");
    for(i=0;i<m;i++){
        printf("%d\t",*(ptr2+i));
    }
    
    free(ptr1);
    free(ptr2);
}
