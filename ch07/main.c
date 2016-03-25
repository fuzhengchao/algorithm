#include <stdio.h>


// 获取数组array中start到end之间的基点并快排调整,返回基点index
int partition(int array[], int start, int end);

// 快速排序
void quickSort(int array[], int start, int end);

int main() {
	return 0;
}


int partition(int array[], int start, int end) {
	int baseIndex, temp;
	baseIndex = (start + end) / 2;
}