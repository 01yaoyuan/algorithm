#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

// typedef struct
// {
//     int length;
//     int *p;
// } SqList;
// void CreateSqList(SqList *L, int n)
// {
//     int i, j;
//     L->length = n;
//     L->p = (int *)malloc(n * sizeof(int));
//     for (i = 0; i < L->length; i++)
//         scanf("%d", &(L->p[i]));
// }
// void CreateSqList1(SqList *L, int n)
// {
//     int i, j;
//     L->length = n;
//     L->p = (int *)malloc(n * sizeof(int));
//     for (i = 1; i <= L->length; i++)
//         scanf("%d", &(L->p[i]));
// }
// void Destroy(SqList *L)
// {
//     L->length = 0;
//     free(L);
// }
// void Print1(SqList L)
// {
//     int i;
//     for (i = 1; i <= L.length; i++)
//         printf("%d ", L.p[i]);
// }
// void Print(SqList L)
// {
//     int i;
//     for (i = 0; i < L.length; i++)
//         printf("%d ", L.p[i]);
// }
// void input(int a[], int n)
// {
//     for (int i = 1; i <= n; i++)
//         scanf("%d", &a[i]);
// }
// void output(int a[], int n)
// {
//     for (int i = 1; i <= n; i++)
//         printf("%d ", a[i]);
//     printf("\n");
// }
// void Swap(SqList *L, int i, int j)
// {
//     int temp = L->p[j];
//     L->p[j] = L->p[i];
//     L->p[i] = temp;
// }
// int Partition(SqList *L, int low, int high)
// {
//     int Pivot;
//     Pivot = L->p[low];
//     while (low < high)
//     {
//         while (low < high && L->p[high] >= Pivot)
//             high--;
//         Swap(L, low, high);
//         while (low < high && L->p[low] <= Pivot)
//             low++;
//         Swap(L, low, high);
//     }
//     return low;
// }
// void Sort(SqList *L, int low, int high)
// {
//     int pivot; //����һ������λ�ã�
//     if (low < high)
//     {
//         pivot = Partition(L, low, high);
//         Sort(L, low, pivot - 1);
//         Sort(L, pivot + 1, high);
//     }
// }
// void Quicksort(SqList *L) { Sort(L, 0, L->length - 1); }

// void QuickSort(int p[], int low, int high)
// {
//     int i, j, term; //����term��Ϊ�м���Ŧ��
//     i = low, j = high;
//     if (low < high)
//     {
//         term = p[low];
//         while (i < j)
//         {
//             while (i < j && p[j] >= term)
//                 j--;
//             if (i < j)
//             {
//                 p[i] = p[j];
//                 i++;
//             }
//             while (i < j && p[i] < term)
//                 i++;
//             if (i < j)
//             {
//                 p[j] = p[i];
//                 j--;
//             }
//         }
//         p[i] = term;
//         QuickSort(p, low, i - 1);
//         QuickSort(p, i + 1, high);
//     }

// } //���ְ汾�Ŀ��ţ�
// void SelectSort(SqList *L)
// {
//     int i, j, min;
//     for (i = 0; i < L->length; i++)
//     {
//         min = i;
//         for (j = i + 1; j < L->length; j++)
//         {
//             if (L->p[j] < L->p[min])
//                 min = j;
//         }
//         if (min != i)
//             Swap(L, i, min);
//     }
// } //��ѡ������
// /*void InsertSort(SqList *L)
// {
//     int i,j,temp;

//     for(i=1;i<L->length;i++)
//     {
//             if(L->p[i]<L->p[i-1])
//         {
//             temp=L->p[i];
//             for(j=i-1;L->p[j]>temp;j--)
//                 L->p[j+1]=L->p[j];
//             L->p[j]=temp;

//         }
//      }
//  }
// */

// void InsertSort(int a[], int n)
// {
//     int i, j;
//     for (i = 2; i <= n; i++)
//     {
//         if (a[i] < a[i - 1])
//         {
//             a[0] = a[i];
//             for (j = i - 1; a[j] > a[0]; j--)
//                 a[j + 1] = a[j];
//             a[j + 1] = a[0];
//         }
//     }
// }
// void Insert(int a[], int gap, int i)
// {
//     int insert = a[i], j;
//     for (j = i - gap; j >= 0 && insert < a[j]; j -= gap)
//         a[j + gap] = a[j];
//     a[j + gap] = insert;
// }
// void ShellSort(int a[], int n)
// {
//     int i, j, k, N, gap;
//     N = n;
//     for (gap = N / 2; gap > 0; gap /= 2)
//         for (i = gap; i < N; i++)
//         {
//             Insert(a, gap, i);
//         }
// }
// void HeapAdjust(SqList *L, int s, int m)
// {
//     int i, j, temp;
//     temp = L->p[s];
//     for (j = 2 * s; j <= m; j *= 2)
//     {
//         if (j < m && L->p[j] < L->p[j + 1])
//             j++;
//         if (temp >= L->p[j])
//             break;
//         L->p[s] = L->p[j];
//         s = j;
//     }
//     L->p[s] = temp;
// }
// void HeapSort(SqList *L)
// {
//     int i, j;
//     for (i = L->length / 2; i > 0; i--)
//     {
//         HeapAdjust(L, i, L->length);
//     }
//     for (i = L->length; i > 1; i--)
//     {
//         Swap(L, 1, i);
//         HeapAdjust(L, 1, i - 1);
//     }
// }

/**
 * @brief 从倒数最后一个非叶子节点开始自上向下，自左向右进行进行调整
 * 	   从而自下向上构建大顶锥
 * @param arr
 * @param start 起始位置（从0开始）
 * @param end 终止位置（len-1）
 */
void HeapAdjust(int arr[], int start, int end)
{
    int pivot = arr[start]; //选取根节点与左右节点进行比较；
    for (int i = 2 * start + 1; i <= end; i++)
    { //寻找左右子节点中最大的一个
        if (i < end && arr[i] < arr[i + 1])
        {
            i++;
        }
        if (pivot < arr[i])
        {
            arr[start] = arr[i];
            start = i;
        }
        else
            break;
    }
    arr[start] = pivot;
}

/**
 * @brief 在构建好大顶锥后，将
 *
 * @param arr
 * @param len
 */
void HeapSort(int arr[], int len)
{
    //从最后一个根节点开始,
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        HeapAdjust(arr, i, len - 1);
    }

    for (int i = len - 1; i >= 0; i--)
    {

        std::swap(arr[0], arr[i]);
        HeapAdjust(arr, 0, i - 1);
    }
}
