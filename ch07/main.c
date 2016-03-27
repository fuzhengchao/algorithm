#include <stdio.h>

// 打印数组
void printArray(int array[], int start, int end);
// 获取数组array中start到end之间的基点并快排调整,返回基点index
int partition(int array[], int start, int end);
// 快速排序
void quickSort(int array[], int start, int end);


int main() {
    int array[10] = {11, 12, 5, 9, 14, 2, 13, 9, 21, 12};
    quickSort(array, 0, 9);
    printArray(array, 0, 9);

	return 0;
}


// 快排
void quickSort(int array[], int start, int end) {
    if (start >= end) {
        return;
    }

    int baseIndex = partition(array, start, end);
    if (baseIndex < 0) {
        return;
    }

    if (baseIndex - 1 > start) {
        quickSort(array, start, baseIndex - 1);
    }

    if (baseIndex + 1 < end) {
        quickSort(array, baseIndex + 1, end);
    }    
}


// 选择基点
int partition(int array[], int start, int end) {
    if (start >= end) {
        return -1;
    }

    // 基点选择为第一个点
    int baseIndex, baseValue, temp, i, j;
    baseIndex = start;
    baseValue = array[baseIndex];

    // 调整大于小于基点的点
    i = start + 1;
    j = end;
    while (i < j) {

        while (array[i] <= baseValue && i < j) {
            i++;
        }

        while (array[j] >= baseValue && i < j) {
            j--;
        }

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        i++;
        j--; 
    }

    // 将基点移动到合适的位置
    i = i - 1;
    while (baseIndex < i) {
        array[baseIndex] = array[baseIndex + 1];
        baseIndex++ ; 
    }
    
    array[baseIndex] = baseValue;

    return baseIndex;
}


/** 打印数组*/
void printArray(int array[], int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%d ",  array[i]);
    }

    printf("\n");
}
