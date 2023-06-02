#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <Windows.h>
// -------------- Get the wall time -------------- //
double get_wall_time() {
    LARGE_INTEGER time, frequency;
    QueryPerformanceCounter(&time);
    QueryPerformanceFrequency(&frequency);
    return (double)time.QuadPart / frequency.QuadPart;
}

// -------------- Generate a non-duplicate array -------------- //
void generateNonDuplicateArray(int arr[], int size)
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

// -------------- Print arrays in  the list -------------- //
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }
}

// -------------- Partition the array -------------- //
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

// -------------- Quick sort -------------- //
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// -------------- Main -------------- //
int main()
{
    srand(time(NULL));
    double start_time, end_time, execution_time;
    int n;

    
    printf("Enter the input size of the problem: ");
    scanf("%d", &n);   // Getting the input size of the problem

   
    int *array = (int *)malloc(sizeof(int) * n);  // Allocating memory for the array
    
    generateNonDuplicateArray(array, n); // Generate a non-duplicate array


    printf("Unsorted Array:\n");
    printArray(array, n);     // Print the unsorted array
    printf("\n");


    start_time = get_wall_time();    // Get the starting time.

    quickSort(array, 0, n - 1);

    end_time = get_wall_time();  // Get the ending time
    execution_time = (end_time - start_time) * 1000.0;  // Calculate the execution time in milliseconds

    printf("Execution Time: %.2f milliseconds\n", execution_time);


    printf("Sorted array in ascending order:\n");
    printArray(array, n);

    return 0;
}
