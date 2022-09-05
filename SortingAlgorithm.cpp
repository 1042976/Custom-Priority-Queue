//
// Created by Xiaodong Liu on 9/4/22.
//
#include <cstdlib>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::swap;
//void swap(int* i, int* j){
//    int temp = *i;
//    *i = *j;
//    *j = temp;
//}
void printArray(int arr[], int size){
    for(int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int arr[], int n, int start){
    int largest = start;
    int l = start*2+1;
    int r = start*2+2;
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != start){
        swap(arr[largest], arr[start]);
        heapify(arr, n, largest);
    }
}
//T-O(nlogn) S-O(1)
void heapSort(int arr[], int size){
    cout << "heap sort" << endl;
    for(int i = size/2-1; i >= 0; --i){
        heapify(arr, size, i);
    }
    for(int i = size-1; i > 0; --i){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int partition(int arr[], int l, int r){
    swap(arr[rand()%(r-l+1)+l], arr[r]);
    int last = l, first = r;
    while(last < first){
        if(arr[last] > arr[r]){
            swap(arr[last], arr[--first]);
        }else{
            ++last;
        }
    }
    swap(arr[first], arr[r]);
    return first;
}

void quickSort(int arr[], int l, int r){
    if(l >= r){
        return;
    }
    int m = partition(arr, l, r);
    quickSort(arr, l, m-1);
    quickSort(arr, m+1, r);
}
//T-O(n^2), S-O(1)
void quickSort(int arr[], int size){
    cout << "quick sort" << endl;
    srand(time(NULL));
    quickSort(arr, 0, size-1);
}
void merge(int arr[], int l, int m, int r){
    std::unique_ptr<int[]> arr1 = std::make_unique<int[]>(r-l+1);
    int i = l, j = m+1, k = 0;
    while(i <= m && j <= r){
        arr[i] <= arr[j]? arr1[k++] = arr[i++] : arr1[k++] = arr[j++];
    }
    while(i <= m){
        arr1[k++] = arr[i++];
    }
    while(j <= r){
        arr1[k++] = arr[j++];
    }
    while(--k >= 0){
        arr[--j] = arr1[k];
    }
}
void mergeSort(int arr[], int l, int r){
    int m = l+((r-l)>>1);
    if(l == m){
        if(arr[l] > arr[r]){
            swap(arr[l], arr[r]);
        }
        return;
    }
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

//T-O(nlogn) S-O(n)
void mergeSort(int arr[], int size){
    cout << "merge sort" << endl;
    mergeSort(arr, 0, size-1);
}


void selectionSort(int arr[], int size){
    for(int i = 0; i < size; ++i){
        int minIndex = i;
        for(int j = i+1; j < size; ++j){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

//T-O(n^2) S-O(1)
void bubbleSort(int arr[], int size){
    int i = size-1;
    int swappedIndex = -1;
    while(i >= 0){
        for(int j = 0; j < i; ++j){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swappedIndex = j;
            }
        }
        if(i == swappedIndex){
            break;
        }else{
            i = swappedIndex;
        }
    }
}

//T-O(n^2) S-O(1)
void insertionSort(int arr[], int size){
    for(int i = 1; i < size; ++i){
        int j = i;
        int temp = arr[j];
        while(--j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
        }
        arr[++j] = temp;
    }
}
int main(){
    int arr[] = {1, 5, 3, 2, 6, 6, 4, 10, 8};
    int size = sizeof(arr)/ sizeof(*arr);
    printArray(arr, size);
    heapSort(arr, size);
//    quickSort(arr, size);
//    mergeSort(arr, size);
//    selectionSort(arr, size);
//    bubbleSort(arr, size);
//    insertionSort(arr, size);
    printArray(arr, size);
    return EXIT_SUCCESS;
}