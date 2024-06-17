#include <stdio.h>

int main() {

    int i, j, nonzero = 0, zero = 0, mat[3][3];  // Specify matrix dimensions here

    printf("Enter the values=\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nThe entered matrix is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    // verifying the matrix is sparse matrix or not
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (mat[i][j] == 0) {
                zero++;
            } else {
                nonzero++;
            }
        }
    }

    if (nonzero > zero) {
        printf("It is not a sparse matrix");
    } else if (nonzero == 0) {
        printf("It is a zero matrix\n");
    } else {
        printf("It is a sparse matrix\n\n");

        int sparseMatrix[nonzero][3], k = 0;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (mat[i][j] != 0) {
                    sparseMatrix[k][0] = i;
                    sparseMatrix[k][1] = j;
                    sparseMatrix[k][2] = mat[i][j];
                    k++;
                }
            }
        }
        printf("i\tj     values\t\n");
        for (i = 0; i < nonzero; i++) {
            for (j = 0; j < 3; j++) {
                printf("%d\t", sparseMatrix[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

