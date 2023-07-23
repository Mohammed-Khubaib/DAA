#include <stdio.h>

void swap(int arr[] , int i ,int j){
   int temp=arr[i];
   arr[i]=arr[j];
   arr[j] =temp;
}

int partition(int arr[],int l, int r){
   int pivot = arr[r];
   int i = l-1;
   for(int j=l;j<r;j++){
      if(arr[j]<pivot){
         i++;
         swap(arr,i,j);
      }
   }
   swap(arr,i+1,r);
   return i+1;
}

void quickSort(int arr[],int l,int r){
   if (l<r){
      int pi = partition(arr,l,r);
      quickSort(arr,l,pi-1);
      quickSort(arr,pi+1,r);
   }
}

int main() {
   int arr[] = {9, 5, 7, 1, 4, 3};
   printf("Original Array :\n");
   int l=0 ;
   int r = (sizeof(arr) / sizeof(arr[0]));
   for(int i=0;i<r;i++){
       printf("%d ",arr[i]);
   }
   //  printf("\nSize : %d\n",r);
   quickSort(arr,l,r-1);
   printf("\nAfter Applying QuickSort Sort :\n");
   for(int i=0;i<r;i++){
       printf("%d ",arr[i]);
   }
   printf("\n");
   return 0;
}