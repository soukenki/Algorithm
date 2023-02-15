#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//声明 (用于计数递归次数)
extern int callCount;

//打印
void PrintArray(int* a, int size); 


//插入排序
void InsertSort(int* a, int n);
//希尔排序
void ShellSort(int* a, int n);


//选择排序
void SelectSort(int* a, int n);

//堆排序
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);


//快速排序： hoare版本
int PartSort1(int* a, int begin, int end);
//快速排序：挖坑法
int PartSort2(int* a, int begin, int end);
//快速排序： 前后指针法
int PartSort3(int* a, int begin, int end);
//快速排序：前后指针 + 三数取中法
int GetMidIndex(int* a, int begin, int end);
//快速排序： 递归
void QuickSort(int* a, int begin, int end);
//快速排序（非递归）
void QuickSortNonR(int* a, int begin, int end);

//归并排序:递归
void MergeSort(int* a, int n);
//归并排序：非递归
void MergeSortNonR(int* a, int n);
//文件归并排序
void MergeSortFile(const char* file); // 参数为文件名


//计数排序
//统计每个数据出现的次数(只适用于正负整数)
void CountSort(int* a, int n);

//基数排序

//...



