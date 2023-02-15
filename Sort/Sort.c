#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include "Stack.h"

int callCount = 0;  // 计数递归次数 

//打印
void PrintArray(int* a, int size)
{
	assert(a && size != 0);

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}

//交换
void Swap(int* left, int* right)
{
	assert(left && right);

	int tmp = 0;
	tmp = *left;
	*left = *right;
	*right = tmp;
}



//直接插入排序 时间O(N^2) 空间(1) 稳定
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		//[0,end]有序，把end+1位置的值插入，保持有序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//希尔排序  时间平均：O(N^1.3）空间(1) 不稳定
// 
// void ShellSort(int* a, int n) // 基础版本
//{
//   // 1、预处理 -- 让整个结构变得更接近有序
//	/*int gap = 3;*/
//
//	/*for (int j = 0; j < gap; ++j) // 有gap组数据
//	{
//		for (int i = j; i < n - gap; i += gap) // 每一组之间的切换
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0) // 等价于单趟直接插入
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end]; // 注意跨度为gap
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}*/    (上面版本有漏洞，但是可以参考数据挪动的思想)
//
//	// gap > 1时是预排序
//	// gap 最后一次等于1，是直接插入排序
//	//PrintArray(a, n);
//
// // 优化后的版本
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		//gap = gap / 2;
//
//		for (int i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//
//		//printf("gap:%d->", gap);
//		//PrintArray(a, n);
//	}
//}


// 希尔排序 简化版  gap组数据交替插入排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;  // 控制gap最后一次除法能为1
		//gap = gap / 2;

		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}


// 选择排序    时间O(N^2) 最好的情况：O(N^2)
// 选择排序 对比 插入排序， 插入更好
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0, end = n - 1;

	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] < a[mini]) // 找最小
				mini = i;

			if (a[i] > a[maxi]) // 找最大
				maxi = i;
		}
		Swap(&a[begin], &a[mini]);  // 交换

		// 如果begin和maxi重叠，那么要修正一下maxi的位置
		if (begin == maxi)
		{
			maxi = mini; // 第一次查就查到最大的
		}

		Swap(&a[end], &a[maxi]); // 那就把它放到最后
		++begin; // 最小放头，最大放尾，往中间靠拢
		--end;
	}
}





// 堆排序  时间O(N*logN)
// 升序 -- 建大堆 (再把堆顶数据向下调整，形成升序)
// 降序 -- 建小堆 （同理）
void AdjustDwon(int* a, int size, int parent) // 建堆
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		// 选出左右孩子中 小/大 的那个
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}

		// 孩子跟父亲比较
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n) // 建完堆，开始排序
{
	// 建堆 O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)  // i = 最后一个数据的父亲下标
	{
		AdjustDwon(a, n, i);
	}

	// O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);  
		--end;
	}
}


//冒泡排序    时间O(N^2)  最好的情况：O(N)
// 冒泡 对比 插入排序， 插入更好
void BubbleSort(int* a, int n)
{
	assert(a);

	for (int j = 0; j < n - 1; ++j)
	{
		int exchange = 0;
		for (int i = 1; i < n - j; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (0 == exchange)
		{
			break;  // 检查第一次就已经有序
		}

	}
}


// 快速单趟排序： hoare版本
int PartSort1(int* a, int begin, int end)
{
	int left = begin;
	int right = end;
	int keyi = left;

	while (left < right)
	{
		//右边先走，找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		//左边再走，找大
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		//停下来的位置，进行交换
		Swap(&a[left], &a[right]);
	}

	//改变keyi位置
	Swap(&a[keyi], &a[left]);
	keyi = left;

	return keyi;
}

// 快速单趟排序：挖坑法
int PartSort2(int* a, int begin, int end)
{
	int key = a[begin];
	int piti = begin; //坑位

	while (begin < end)
	{
		//右边找小，填到左边的坑里面，这个位置形成新的坑
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[piti] = a[end]; //填原来的坑
		piti = end; //更新坑位

		//左边找大，填到刚更新的右边的坑
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		a[piti] = a[begin];
		piti = begin;
	}

	//把最后一个坑填上key
	a[piti] = key;
	return piti;
}

// 快速单趟排序： 前后指针法: 三数取中法 (优化)
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) >> 1;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] < a[end])
			return end;
		else
			return begin;
	}
	else // (a[begin] >= a[mid])
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}
// 快速单趟排序： 前后指针法
int PartSort3(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;

	//加入三数取中的优化
	int midi = GetMidIndex(a, begin, end);
	Swap(&a[keyi], &a[midi]);

	while (cur <= end)
	{
		//cur位置的值 小于 prev位置的值 交换
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		++cur;
	}

	//cur走完了，prev在中间位置
	Swap(&a[keyi], &a[prev]);
	keyi = prev;

	return keyi;
}

// 快速排序： 递归
void QuickSort(int* a, int begin, int end)
{
	//callCount++;
	//printf("%p\n", &callCount);  // 计数递归次数
	
	//区间不存在，或者只有一个值，都不需要处理
	if (begin >= end)
	{
		return;
	}

	int keyi = PartSort3(a, begin, end); // 单趟排序

	// [begin, keyi-1]  keyi  [keyi+1, end]
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}


// 快速排序（非递归）
// 要求掌握，递归改非递归
// 递归大问题，极端场景下面，如果深度太深，会出现栈溢出
// 1、直接改循环 -- 比如斐波那契数列、归并排序
// 2、用数据结构栈模拟递归过程
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, end);
	StackPush(&st, begin);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);  // 取头为左 
		StackPop(&st);

		int right = StackTop(&st); // 取尾为右
		StackPop(&st);

		int keyi = PartSort3(a, left, right); // 单趟排序
		// [left, keyi-1] keyi [keyi+1, right] 

		if (keyi + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyi + 1);
		}

		if (left < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, left);
		}
	}
	StackDestory(&st);
}





//归并排序  时间O(N*logN)  空间O(N)
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;

	// [begin, mid]  [mid+1, end] 分治递归，让子区间有序
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	// 归并 [begin, mid] [mid+1, end]
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	// 其中有一方结束，就把另一方全加进去
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	// 把归并数据拷贝回原数组
	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}

// 归并：非递归
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	int gap = 1;
	while (gap < n)
	{
		//printf("gap=%d->", gap);
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [i, i+gap-1] [i+gap, i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// end1越界或者begin2越界,则可以不归并了
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			//printf("[%d,%d] [%d, %d]--", begin1, end1, begin2, end2);

			int m = end2 - begin1 + 1;
			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			// 其中有一方结束，就把另一方全加进去
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * m);
		}
		gap *= 2;
	}
	free(tmp);
}

//文件归并排序  
// 从文件中提取要排序的数据，然后保存到新建文件中，再对
void _MergeFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* fout1 = fopen(file1, "r"); // 打开指定的文件, 返回关联该文件的流
	if (fout1 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1); // 从文件流中读取数据.
	int ret2 = fscanf(fout2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1); // 指定的格式，发送信息到指定的文件
			ret1 = fscanf(fout1, "%d\n", &num1);
		}
		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}

	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}

	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}

	fclose(fout1); // 关闭给出的文件流
	fclose(fout2);
	fclose(fin);
}
void MergeSortFile(const char* file)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	// 分割成一段一段的数据，内存排序后写到，小文件
	int n = 10;
	int a[10];
	int i = 0, num = 0;
	char subfile[20];
	int filei = 1;

	memset(a, 0, sizeof(int) * n);  // a[]的数据，全部改0
	while (fscanf(fout, "%d\n", &num) != EOF)
	{
		if (i < n - 1)
		{
			a[i++] = num;
		}
		else
		{
			a[i] = num;
			QuickSort(a, 0, n - 1);  // 快排
			sprintf(subfile, "%d", filei++); // 把输出发送到buffer(缓冲区)中
			FILE* fin = fopen(subfile, "w");
			if (fin == NULL)
			{
				printf("打开文件失败\n");
				exit(-1);
			}
			
			for (int j = 0; j < n; ++j)
			{
				fprintf(fin, "%d\n", a[j]);
			}
			fclose(fin);

			i = 0;
			memset(a, 0, sizeof(int) * n);
		}
	}

	// 利用互相归并到文件，实现整体有序
	char mfile[100] = "12";
	char file1[100] = "1";
	char file2[100] = "2";
	for (int i = 2; i <= n; ++i)
	{
		//读取file1和file2，进行归并出mfile
		_MergeFile(file1, file2, mfile);

		strcpy(file1, mfile);
		sprintf(file2, "%d", i + 1);
		sprintf(mfile, "%s%d", mfile, i + 1);
	}

	printf("%s文件排序成功\n", file);
	fclose(fout);
}




//计数排序   时间O(max(range, N))    空间O(range)
//统计每个数据出现的次数 (只适用于正负整数)
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];

	//计数出最大和最小
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	//统计次数的数组
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int*) * range);
	if (count == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	memset(count, 0, sizeof(int) * range);

	//统计次数
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}

	//回写 - 排序
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		//出现几次就回写几个i+min
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(count);
}


//基数排序
