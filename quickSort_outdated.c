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

// int main()
// {
//     srand(time(NULL));
//     clock_t start, end;

//     size_t n;
//     printf("Enter the input size of the problem: ");
//     scanf("%zu", &n);

//     int data[n];

//     for (size_t i = 0; i < n; i++)
//     {
//         data[i] = i + 1;
//     }

//     for (size_t i = 0; i < n; i++)
//     {
//         size_t j = rand() % n;
//         int temp = data[i];
//         data[i] = data[j];
//         data[j] = temp;
//     }

//     printf("Unsorted Array:\n");
//     printArray(data, n);
//     printf("\n");

    
//     /* Store time before function call */
//     start = clock();

//     quickSort(data, 0, n - 1);
//     end = clock();
//     /* Get the time taken by program to execute in seconds */
//     double duration = ((double)end - start)/CLOCKS_PER_SEC *  1000;
     
//     printf("Time taken to execute in seconds : %f", duration);


//     printf("Sorted array in ascending order:\n");
//     printArray(data, n);

//     return 0;
// }



#include <stdio.h>
#include <time.h>

#include <Windows.h>

double get_wall_time() {
    LARGE_INTEGER time, frequency;
    QueryPerformanceCounter(&time);
    QueryPerformanceFrequency(&frequency);
    return (double)time.QuadPart / frequency.QuadPart;
}

double measure_execution_time(void (*function)()) {
    double start_time, end_time, execution_time;

    start_time = get_wall_time();  // Get the starting time

    function();  // Execute the provided function

    end_time = get_wall_time();  // Get the ending time

    execution_time = end_time - start_time;  // Calculate the execution time in microseconds

    return execution_time;
}

int main() {
    double start_time, end_time, execution_time;
     size_t n;
    printf("Enter the input size of the problem: ");
    scanf("%zu", &n);
    
    int *array = (int *)malloc(sizeof(int) * n);
    generateNonDuplicateArray(array, n);

    printf("Unsorted Array:\n");
    printArray(array, n);
    printf("\n");

    start_time = get_wall_time();  // Get the starting time

    // Place your program code here
     quickSort(array, 0, n - 1);
    // ...
    // double execution_time = measure_execution_time(&quickSort(array, 0, n - 1));

    // printf("Execution Time: %.2f microseconds\n", execution_time);


    end_time = get_wall_time();  // Get the ending time

    execution_time = (end_time - start_time) * 1000.0;  // Calculate the execution time in milliseconds

    printf("Execution Time: %.2f milliseconds\n", execution_time);

    return 0;
}

