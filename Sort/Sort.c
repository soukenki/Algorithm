#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include "Stack.h"

int callCount = 0;  // �����ݹ���� 

//��ӡ
void PrintArray(int* a, int size)
{
	assert(a && size != 0);

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}

//����
void Swap(int* left, int* right)
{
	assert(left && right);

	int tmp = 0;
	tmp = *left;
	*left = *right;
	*right = tmp;
}



//ֱ�Ӳ������� ʱ��O(N^2) �ռ�(1) �ȶ�
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		//[0,end]���򣬰�end+1λ�õ�ֵ���룬��������
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

//ϣ������  ʱ��ƽ����O(N^1.3���ռ�(1) ���ȶ�
// 
// void ShellSort(int* a, int n) // �����汾
//{
//   // 1��Ԥ���� -- �������ṹ��ø��ӽ�����
//	/*int gap = 3;*/
//
//	/*for (int j = 0; j < gap; ++j) // ��gap������
//	{
//		for (int i = j; i < n - gap; i += gap) // ÿһ��֮����л�
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0) // �ȼ��ڵ���ֱ�Ӳ���
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end]; // ע����Ϊgap
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}*/    (����汾��©�������ǿ��Բο�����Ų����˼��)
//
//	// gap > 1ʱ��Ԥ����
//	// gap ���һ�ε���1����ֱ�Ӳ�������
//	//PrintArray(a, n);
//
// // �Ż���İ汾
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


// ϣ������ �򻯰�  gap�����ݽ����������
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;  // ����gap���һ�γ�����Ϊ1
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


// ѡ������    ʱ��O(N^2) ��õ������O(N^2)
// ѡ������ �Ա� �������� �������
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0, end = n - 1;

	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] < a[mini]) // ����С
				mini = i;

			if (a[i] > a[maxi]) // �����
				maxi = i;
		}
		Swap(&a[begin], &a[mini]);  // ����

		// ���begin��maxi�ص�����ôҪ����һ��maxi��λ��
		if (begin == maxi)
		{
			maxi = mini; // ��һ�β�Ͳ鵽����
		}

		Swap(&a[end], &a[maxi]); // �ǾͰ����ŵ����
		++begin; // ��С��ͷ������β�����м俿£
		--end;
	}
}





// ������  ʱ��O(N*logN)
// ���� -- ����� (�ٰѶѶ��������µ������γ�����)
// ���� -- ��С�� ��ͬ��
void AdjustDwon(int* a, int size, int parent) // ����
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		// ѡ�����Һ����� С/�� ���Ǹ�
		if (child + 1 < size && a[child + 1] > a[child])
		{
			++child;
		}

		// ���Ӹ����ױȽ�
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
void HeapSort(int* a, int n) // ����ѣ���ʼ����
{
	// ���� O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)  // i = ���һ�����ݵĸ����±�
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


//ð������    ʱ��O(N^2)  ��õ������O(N)
// ð�� �Ա� �������� �������
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
			break;  // ����һ�ξ��Ѿ�����
		}

	}
}


// ���ٵ������� hoare�汾
int PartSort1(int* a, int begin, int end)
{
	int left = begin;
	int right = end;
	int keyi = left;

	while (left < right)
	{
		//�ұ����ߣ���С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		//������ߣ��Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		//ͣ������λ�ã����н���
		Swap(&a[left], &a[right]);
	}

	//�ı�keyiλ��
	Swap(&a[keyi], &a[left]);
	keyi = left;

	return keyi;
}

// ���ٵ��������ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int key = a[begin];
	int piti = begin; //��λ

	while (begin < end)
	{
		//�ұ���С�����ߵĿ����棬���λ���γ��µĿ�
		while (begin < end && a[end] >= key)
		{
			--end;
		}

		a[piti] = a[end]; //��ԭ���Ŀ�
		piti = end; //���¿�λ

		//����Ҵ���ո��µ��ұߵĿ�
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}

		a[piti] = a[begin];
		piti = begin;
	}

	//�����һ��������key
	a[piti] = key;
	return piti;
}

// ���ٵ������� ǰ��ָ�뷨: ����ȡ�з� (�Ż�)
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
// ���ٵ������� ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;

	//��������ȡ�е��Ż�
	int midi = GetMidIndex(a, begin, end);
	Swap(&a[keyi], &a[midi]);

	while (cur <= end)
	{
		//curλ�õ�ֵ С�� prevλ�õ�ֵ ����
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		++cur;
	}

	//cur�����ˣ�prev���м�λ��
	Swap(&a[keyi], &a[prev]);
	keyi = prev;

	return keyi;
}

// �������� �ݹ�
void QuickSort(int* a, int begin, int end)
{
	//callCount++;
	//printf("%p\n", &callCount);  // �����ݹ����
	
	//���䲻���ڣ�����ֻ��һ��ֵ��������Ҫ����
	if (begin >= end)
	{
		return;
	}

	int keyi = PartSort3(a, begin, end); // ��������

	// [begin, keyi-1]  keyi  [keyi+1, end]
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}


// �������򣨷ǵݹ飩
// Ҫ�����գ��ݹ�ķǵݹ�
// �ݹ�����⣬���˳������棬������̫������ջ���
// 1��ֱ�Ӹ�ѭ�� -- ����쳲��������С��鲢����
// 2�������ݽṹջģ��ݹ����
void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, end);
	StackPush(&st, begin);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);  // ȡͷΪ�� 
		StackPop(&st);

		int right = StackTop(&st); // ȡβΪ��
		StackPop(&st);

		int keyi = PartSort3(a, left, right); // ��������
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





//�鲢����  ʱ��O(N*logN)  �ռ�O(N)
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;

	// [begin, mid]  [mid+1, end] ���εݹ飬������������
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);

	// �鲢 [begin, mid] [mid+1, end]
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

	// ������һ���������Ͱ���һ��ȫ�ӽ�ȥ
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	// �ѹ鲢���ݿ�����ԭ����
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

// �鲢���ǵݹ�
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

			// end1Խ�����begin2Խ��,����Բ��鲢��
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

			// ������һ���������Ͱ���һ��ȫ�ӽ�ȥ
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

//�ļ��鲢����  
// ���ļ�����ȡҪ��������ݣ�Ȼ�󱣴浽�½��ļ��У��ٶ�
void _MergeFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* fout1 = fopen(file1, "r"); // ��ָ�����ļ�, ���ع������ļ�����
	if (fout1 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1); // ���ļ����ж�ȡ����.
	int ret2 = fscanf(fout2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1); // ָ���ĸ�ʽ��������Ϣ��ָ�����ļ�
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

	fclose(fout1); // �رո������ļ���
	fclose(fout2);
	fclose(fin);
}
void MergeSortFile(const char* file)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	// �ָ��һ��һ�ε����ݣ��ڴ������д����С�ļ�
	int n = 10;
	int a[10];
	int i = 0, num = 0;
	char subfile[20];
	int filei = 1;

	memset(a, 0, sizeof(int) * n);  // a[]�����ݣ�ȫ����0
	while (fscanf(fout, "%d\n", &num) != EOF)
	{
		if (i < n - 1)
		{
			a[i++] = num;
		}
		else
		{
			a[i] = num;
			QuickSort(a, 0, n - 1);  // ����
			sprintf(subfile, "%d", filei++); // ��������͵�buffer(������)��
			FILE* fin = fopen(subfile, "w");
			if (fin == NULL)
			{
				printf("���ļ�ʧ��\n");
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

	// ���û���鲢���ļ���ʵ����������
	char mfile[100] = "12";
	char file1[100] = "1";
	char file2[100] = "2";
	for (int i = 2; i <= n; ++i)
	{
		//��ȡfile1��file2�����й鲢��mfile
		_MergeFile(file1, file2, mfile);

		strcpy(file1, mfile);
		sprintf(file2, "%d", i + 1);
		sprintf(mfile, "%s%d", mfile, i + 1);
	}

	printf("%s�ļ�����ɹ�\n", file);
	fclose(fout);
}




//��������   ʱ��O(max(range, N))    �ռ�O(range)
//ͳ��ÿ�����ݳ��ֵĴ��� (ֻ��������������)
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];

	//������������С
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	//ͳ�ƴ���������
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int*) * range);
	if (count == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	memset(count, 0, sizeof(int) * range);

	//ͳ�ƴ���
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}

	//��д - ����
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		//���ּ��ξͻ�д����i+min
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(count);
}


//��������
