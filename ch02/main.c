#include <stdio.h>

/**插入排序声明*/
void insertSort(int array[], int n);
/** 打印数组*/
void printArray(int array[], int n);

int main () {
    int array[10] = {5, 6, 3, 9, 2, 8, 6, 4, 10, 12};
    insertSort(array, 10);
    printArray(array, 10);
    return 0;
}


/**插入排序实现*/
void insertSort(int array[], int n) {
    int i, j, insertNum, insertIndex;

    for (i = 1; i < n; i++) {
        insertNum = array[i];
        insertIndex = i;

        for (j = i - 1; j >= 0; j--) {
            if (array[j] <= insertNum) {
                break;
            }

            array[insertIndex--] = array[j];
        }

        array[insertIndex] = insertNum;
    }
}

/** 打印数组*/
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ",  array[i]);
    }

    printf("\n");
}
