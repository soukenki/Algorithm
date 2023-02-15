#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

int main()
{
	int arr[] = { 2,3,4, 8,9,5, 7,6,1, 0,-1 }; //11
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, size);

	// InsertSort(arr, size); // 插入
	// ShellSort(arr, size);  // 希尔
	
	// SelectSort(arr, size);  // 选择 
	// HeapSort(arr, size);  // 堆
	// BubbleSort(arr, size);  // 冒泡
	 
	// QuickSort(arr, 0, size - 1);  // 快排 递归
	// QuickSortNonR(arr, 0, size - 1); // 快排 非递归
	 
	// MergeSort(arr, size);     // 归并 递归
	// MergeSortNonR(arr, size);  //归并 非递归
	// MergeSortFile("SortData.txt"); // 文件归并
	
	// CountSort(arr, size);  // 计数排序
	
 	PrintArray(arr, size);
	return 0;
 }