#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

int main()
{
	int arr[] = { 2,3,4, 8,9,5, 7,6,1, 0,-1 }; //11
	int size = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, size);

	// InsertSort(arr, size); // ����
	// ShellSort(arr, size);  // ϣ��
	
	// SelectSort(arr, size);  // ѡ�� 
	// HeapSort(arr, size);  // ��
	// BubbleSort(arr, size);  // ð��
	 
	// QuickSort(arr, 0, size - 1);  // ���� �ݹ�
	// QuickSortNonR(arr, 0, size - 1); // ���� �ǵݹ�
	 
	// MergeSort(arr, size);     // �鲢 �ݹ�
	// MergeSortNonR(arr, size);  //�鲢 �ǵݹ�
	// MergeSortFile("SortData.txt"); // �ļ��鲢
	
	// CountSort(arr, size);  // ��������
	
 	PrintArray(arr, size);
	return 0;
 }