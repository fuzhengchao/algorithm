#include <stdio.h>
#include <math.h>

/** 打印数组*/
void printArray(int array[], int start, int end);
/** 打印堆*/
void printHeap(int array[], int root, int n);
/** 堆排序*/
void heapSort(int heap[], int n);


// 最大堆数据结构数组实现
/** 构建堆*/
void buildHeap(int array[], int n);

/** 调整堆，root为调节根节点位置*/
void adjustHeap(int array[], int root, int n);

int main () {
    int array[10] = {1, 4, 16, 3, 8, 7, 9, 10, 14, 2};

    // 建堆
    buildHeap(array, 10);
    printArray(array, 0, 10);

    // 堆排序
    heapSort(array, 10);
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



/** 构建堆*/
void buildHeap(int array[], int n) {
    int root;
    // 最后一个根节点往树上面遍历
    for (root = (n - 1) / 2; root >= 0; root--) {
        adjustHeap(array, root, n);
    }
}

/** 调整堆，root为调节根节点位置*/
void adjustHeap(int array[], int root, int n) {
    int childBase = 2 * root;
    int left = childBase + 1;
    int right = childBase + 2;
    int max, temp;


    // 已经没有子节点
    if (left >= n) {
        return;
    }

    if (right >= n) {  // 没有右节点
        max = left;
    } else {  // 左右节点均存在
        max = array[right] > array[left] ? right : left;
    }

    // 根节点下移
    if (array[root] < array[max]) {
        temp = array[root];
        array[root] = array[max];
        array[max] = temp;

        // 下移根节点可能还会下移
        adjustHeap(array, max, n);
    }

}


/** 堆排序*/
void heapSort(int heap[], int n) {
    int temp;
    while (n > 1) {
        temp = heap[n - 1];
        heap[n - 1] = heap[0];
        heap[0] = temp;
        adjustHeap(heap, 0, --n);
    }
}
















