#include <iostream>

void merge(int arr[],int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++){
        L[i] = arr[l+i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = arr[m+1+i];
    }
    
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}




void mergeSort(int arr[], int l, int r)
{
    if(l < r){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr,l,m,r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}




int partition(int arr[], int s, int e){
    int randomindex = s + rand()%(e-s+1);
    int pivitindex = s;
    int pivit = arr[randomindex];
    std::swap(arr[s],arr[randomindex]);
    s++;
    while(s < e){
        while(s < e && arr[s]<=pivit){
            s++;
        }
        while(s < e && arr[e] > pivit){
            e--;
        }
        if(s < e){
            std::swap(arr[s],arr[e]);
            s++;
            e--;
        }
    }
    if (arr[e] < arr[pivitindex])
        std::swap(arr[e],arr[pivitindex]);

    return e;
}

void quick(int arr[], int s, int e){
    if (s < e){
        int middle = partition(arr, s, e);
        quick(arr,s,middle-1);
        quick(arr,middle,e);
    }
}

int main()
{
    int arr[] = {12, 11, 91, 5, 6, 7,88,20,16,14,2,56,7,42};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printf("\nMerge Sorted array is \n");
    printArray(arr, arr_size);
    
    int arr2[] = {12, 11, 91, 5, 6, 7,88,20,16,14,2,56,7,42};
    int arr2_size = sizeof(arr2)/sizeof(arr[0]);
    printf("\nGiven array is \n");
    printArray(arr2, arr2_size);

    quick(arr2, 0, arr2_size-1);
    printf("\nQuick Sorted array is \n");
    printArray(arr2, arr2_size);
    return 0;
}
