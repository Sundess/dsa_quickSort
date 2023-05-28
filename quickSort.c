#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main()
{
    srand(time(NULL));
    clock_t start, end;

    size_t n;
    printf("Enter the input size of the problem: ");
    scanf("%zu", &n);

    int data[n];

    for (size_t i = 0; i < n; i++)
    {
        data[i] = i + 1;
    }

    for (size_t i = 0; i < n; i++)
    {
        size_t j = rand() % n;
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    printf("Unsorted Array:\n");
    printArray(data, n);
    printf("\n");

    quickSort(data, 0, n - 1);

    printf("Sorted array in ascending order:\n");
    printArray(data, n);

    return 0;
}
