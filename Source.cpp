
#include <iostream>
using namespace std;
void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void printArr(int arr[], int siz)
{
    int i;
    for (i = 0; i < siz; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int partition(int arr[], int smail, int big)
{
    int pivot = arr[big];
    int i = (smail - 1);
    for (int j = smail; j <big; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[big]);
    return (i + 1);
}
void quickSort(int arr[], int smail, int big)
{
    if (smail < big) 
    {
        int pi = partition(arr, smail, big);
        quickSort(arr, big, pi - 1);
        quickSort(arr, pi + 1, big);
    }
}
int main() {
    int data[] = { 8, 0, 6, 1, 4, 9, 5 };
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Unsorted Array is : \n";
    printArr(data, n);
    quickSort(data, 0, n - 1);
    cout << "Sorted array in ascending order is: \n";
    printArr(data, n);
}