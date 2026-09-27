#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;
int totalInsertComparisons = 0;

// Insert an element into Max Heap
void insert(int value)
{
    int i = size++;
    heap[i] = value;

    int comparisons = 0;

    // Heapify up
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        comparisons++;

        if (heap[parent] >= heap[i])
            break;

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }

    totalInsertComparisons += comparisons;

    printf("After inserting %d: ", value);

    for (int j = 0; j < size; j++)
        printf("%d ", heap[j]);

    printf(" | Comparisons: %d\n", comparisons);
}

// Find maximum using Max Heap
int findMaxHeap(int *comparisons)
{
    *comparisons = 0;
    return heap[0];
}

// Find maximum using Linear Search
int linearSearchMax(int arr[], int n, int *comparisons)
{
    int max = arr[0];
    *comparisons = 0;

    for (int i = 1; i < n; i++)
    {
        (*comparisons)++;

        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int main()
{
    int scores[] = {78, 92, 65, 88, 95, 72, 84, 90};
    int n = sizeof(scores) / sizeof(scores[0]);

    printf("MAX HEAP INSERTIONS\n");
    printf("-------------------\n");

    // Insert all scores
    for (int i = 0; i < n; i++)
        insert(scores[i]);

    // Display final heap
    printf("\nFinal Max Heap: ");

    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);

    // Max Heap method
    int heapComparisons;
    int heapMax = findMaxHeap(&heapComparisons);

    // Linear Search method
    int linearComparisons;
    int linearMax = linearSearchMax(scores, n, &linearComparisons);

    printf("\n\nMAXIMUM USING MAX HEAP\n");
    printf("Highest score: %d\n", heapMax);
    printf("Comparisons: %d (root access)\n", heapComparisons);

    printf("\nMAXIMUM USING LINEAR SEARCH\n");
    printf("Highest score: %d\n", linearMax);
    printf("Comparisons: %d\n", linearComparisons);

    printf("\nTOTAL INSERTION COMPARISONS: %d\n",
           totalInsertComparisons);

    return 0;
}
