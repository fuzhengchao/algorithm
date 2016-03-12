#include <stdio.h>


/** 打印数组*/
void printArray(int array[], int start, int end);

/**插入排序声明*/
void insertSort(int array[], int n);

/**归并排序*/
void mergeSort(int array[], int start, int end,  int tmpArray[]);
/**合并一数组前后两部分， 前后部分均为有序状态*/
void merge(int array[], int start, int middle, int end, int mergedArray[]);


int main () {
    int array[10] = {11, 12, 5, 9, 14, 2, 13, 9, 21, 12};
    // insertSort(array, 10);

    int tmpArray[10];
    mergeSort(array, 0, 9, tmpArray);
    printArray(array, 0, 10);
    return 0;
}


/** 打印数组*/
void printArray(int array[], int start, int end) {
    for (int i = start; i < end; i++) {
        printf("%d ",  array[i]);
    }

    printf("\n");
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


    printArray(array, 0, n);
}


/** 归并排序*/
void mergeSort(int array[], int start, int end, int tmpArray[]) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(array, start, middle, tmpArray);
        mergeSort(array,  middle + 1, end, tmpArray);
        merge(array, start, middle, end, tmpArray);
    }
}

/**合并一数组前后两部分， 前后部分均为有序状态*/
void merge(int array[], int start, int middle, int end, int mergedArray[]) {
    int left = start;
    int right = middle + 1;
    int index = start;

    while (left <= middle && right <= end) {
        if (array[left] > array[right]) {       
            mergedArray[index++] = array[right++];
        } else {
            mergedArray[index++] = array[left++];
        }
    }

    while (left <= middle) {
        mergedArray[index++] = array[left++];
    }

    while (right <= end) {
        mergedArray[index++] = array[right++];
    }

    for (int i = start; i < index; i++) {
        array[i] = mergedArray[i];
    }
}















