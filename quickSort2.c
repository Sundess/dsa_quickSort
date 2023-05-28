#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateNonDuplicateArray(int arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        int randomNum = (rand() % size) + 1;
        int duplicateEle = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] == randomNum)
            {
                duplicateEle = 1;
                break;
            }
        }
        if (duplicateEle == 0)
        {
            arr[i] = randomNum;
        }
        else
        {
            i--;
        }
    }
}

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

    size_t n;
    printf("Enter the input size of the problem: ");
    scanf("%zu", &n);

    int *array = (int *)malloc(sizeof(int) * n);
    generateNonDuplicateArray(array, n);

    printf("Unsorted Array:\n");
    printArray(array, n);
    printf("\n");

    quickSort(array, 0, n - 1);

    printf("Sorted array in ascending order:\n");
    printArray(array, n);

    return 0;
}
