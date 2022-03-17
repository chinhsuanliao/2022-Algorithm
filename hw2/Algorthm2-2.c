#include <stdio.h>

void combine_increase(int* arr, int start, int* result, int count, const int NUM, const int arr_len)
{
   int i = 0;
   for (i = start; i < arr_len + 1 - count; i++)
   {
     result[count - 1] = i;
     if (count - 1 == 0)
     {
       int j;
       for (j = NUM - 1; j >= 0; j--)
         printf("%d ",arr[result[j]]);
       printf("\n");
     }
     else
       combine_increase(arr, i + 1, result, count - 1, NUM, arr_len);
   }
}

void combine_decrease(int* arr, int start, int* result, int count, const int NUM)
{
    int i;
    for (i = start; i >=count; i--)
   {
     result[count - 1] = i - 1;
     if (count > 1)
     {
       combine_decrease(arr, i - 1, result, count - 1, NUM);
     }
     else
     {
       int j;
       for (j = NUM - 1; j >=0; j--)
     printf("%d ",arr[result[j]]);
       printf("\n");
     }
   }
}


int main()
{
   int arr[13] = {0};
   int num = 6;
   int result[num];
   int size;
   int i=0;

   scanf("%d", &size);

   for (i=0; i<size; i++)
   	scanf("%d", &arr[i]);


   combine_increase(arr, 0, result, num, num, size);
   return 0;
}
