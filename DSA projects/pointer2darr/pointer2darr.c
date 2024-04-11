#include <stdio.h>

void deleteElement(int *arr, int rows, int cols, int targetRow, int targetCol) {
    int *ptr = arr;
    int totalElements = rows * cols;

    // Calculate the index of the target element
    int targetIndex = targetRow * cols + targetCol;

    // Shift elements after the target element
    for (int i = targetIndex; i < totalElements - 1; i++) {
        *(ptr + i) = *(ptr + i + 1);
    }
}

void print2DArray(int *arr, int rows, int cols) {
    int *ptr = arr;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(ptr + i * cols + j));
        }
        printf("\n");
    }
}

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int rows = 3;
    int cols = 4;
    int targetRow = 1;
    int targetCol = 2;

    printf("Before deletion:\n");
    print2DArray((int *)arr, rows, cols);

    // Delete the element
    deleteElement((int *)arr, rows, cols, targetRow, targetCol);
    rows--; // Reduce the number of rows

    printf("\nAfter deletion:\n");
    print2DArray((int *)arr, rows, cols);

    return 0;
}
