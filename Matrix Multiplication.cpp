#include <stdio.h>

int main() {
    int row1, column1, row2, column2, i, j, k;

    printf("Enter the row of the first matrix: ");
    scanf("%d", &row1);
    printf("Enter the column of the first matrix: ");
    scanf("%d", &column1);

    printf("Enter the row of the second matrix: ");
    scanf("%d", &row2);
    printf("Enter the column of the second matrix: ");
    scanf("%d", &column2);

    int Mat1[row1][column1], Mat2[row2][column2], Mat3[row1][column2];

    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < column1; j++) {
            scanf("%d", &Mat1[i][j]);
        }
    }

    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < column2; j++) {
            scanf("%d", &Mat2[i][j]);
        }
    }

    printf("Matrix 1 is:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < column1; j++) {
            printf("%d\t", Mat1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Matrix 2 is:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < column2; j++) {
            printf("%d\t", Mat2[i][j]);
        }
        printf("\n");
    }

    printf("\nThe multiplication of Mat1 and Mat2 is:\n");
    if (column1 == row2) {
        int Res[row1][column2];
        for (i = 0; i < row1; i++) {
            for (j = 0; j < column2; j++) {
                Res[i][j] = 0;
                for (k = 0; k < row2; k++) {
                    Res[i][j] += Mat1[i][k] * Mat2[k][j];
                }
            }
        }

        for (i = 0; i < row1; i++) {
            for (j = 0; j < column2; j++) {
                printf("%d\t", Res[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Matrix multiplication cannot be performed.\n");
    }

    return 0;
}

