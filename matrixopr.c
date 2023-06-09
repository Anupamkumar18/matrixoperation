#include <stdio.h>

#define MAX_SIZE 10

// Function to read matrix elements from the user
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix elements
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int columnsA, int columnsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columnsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposedMatrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
}

// Main function
int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE], transposedMatrix[MAX_SIZE][MAX_SIZE];
    int rowsA, columnsA, rowsB, columnsB;

    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d%d", &rowsA, &columnsA);

    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d%d", &rowsB, &columnsB);

    if (rowsA <= 0 || columnsA <= 0 || rowsB <= 0 || columnsB <= 0 || columnsA != rowsB) {
        printf("Invalid matrix dimensions. Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter the elements for Matrix A:\n");
    readMatrix(matrixA, rowsA, columnsA);

    printf("Enter the elements for Matrix B:\n");
    readMatrix(matrixB, rowsB, columnsB);

    printf("\nMatrix A:\n");
    displayMatrix(matrixA, rowsA, columnsA);

    printf("\nMatrix B:\n");
    displayMatrix(matrixB, rowsB, columnsB);

    int choice;
    do {
        printf("\nChoose the matrix operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rowsA != rowsB || columnsA != columnsB) {
                    printf("Matrix addition is not possible.\n");
                    break;
                }
                addMatrices(matrixA, matrixB, result, rowsA, columnsA);
                printf("Sum of matrices:\n");
                displayMatrix(result, rowsA, columnsA);
                break;
            case 2:
                if (rowsA != rowsB || columnsA != columnsB) {
                    printf("Matrix subtraction is not possible.\n");
                    break;
                }
                subtractMatrices(matrixA, matrixB, result, rowsA, columnsA);
                printf("Subtraction of matrices:\n");
                displayMatrix(result, rowsA, columnsA);
                break;
            case 3:
                multiplyMatrices(matrixA, matrixB, result, rowsA, columnsA, columnsB);
                printf("Multiplication of matrices:\n");
                displayMatrix(result, rowsA, columnsB);
                break;
            case 4:
                printf("Transpose of Matrix A:\n");
                transposeMatrix(matrixA, transposedMatrix, rowsA, columnsA);
                displayMatrix(transposedMatrix, columnsA, rowsA);

                printf("Transpose of Matrix B:\n");
                transposeMatrix(matrixB, transposedMatrix, rowsB, columnsB);
                displayMatrix(transposedMatrix, columnsB, rowsB);
                break;
            case 5:
                printf("Thank you.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (1);

    return 0;
}
