#include <stdio.h>

#define MAX 1000

// Function to copy array
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = source[i];
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Bubble Sort (Ascending) - used before Binary Search
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Linear Search
int linearSearch(int arr[], int n, int key, int *comparisons) {
    *comparisons = 0;

    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key, int *comparisons) {
    int low = 0, high = n - 1;
    *comparisons = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        (*comparisons)++;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

// Insertion Sort
void insertionSort(int arr[], int n, int *comparisons) {
    *comparisons = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            (*comparisons)++;

            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n, key;
    int original[MAX], arr[MAX];
    int comparisons, pos;

    printf("Experiment 1: Searching, Sorting and Complexity Analysis\n\n");

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &original[i]);

    printf("Enter search key: ");
    scanf("%d", &key);

    // ---------------- Linear Search ----------------
    printf("\n========== LINEAR SEARCH ==========\n");

    pos = linearSearch(original, n, key, &comparisons);

    if (pos != -1)
        printf("Element found at position %d\n", pos + 1);
    else
        printf("Element Not Found\n");

    printf("Comparisons performed = %d\n", comparisons);

    // ---------------- Binary Search ----------------
    printf("\n========== BINARY SEARCH ==========\n");

    copyArray(original, arr, n);
    bubbleSort(arr, n);

    printf("Sorted Array:\n");
    printArray(arr, n);

    pos = binarySearch(arr, n, key, &comparisons);

    if (pos != -1)
        printf("Element found at position %d (in sorted array)\n", pos + 1);
    else
        printf("Element Not Found\n");

    printf("Comparisons performed = %d\n", comparisons);

    // ---------------- Insertion Sort ----------------
    printf("\n========== INSERTION SORT ==========\n");

    copyArray(original, arr, n);

    printf("Array Before Sorting:\n");
    printArray(arr, n);

    insertionSort(arr, n, &comparisons);

    printf("Array After Sorting:\n");
    printArray(arr, n);

    printf("Key Comparisons = %d\n", comparisons);

    // ---------------- Comparison ----------------
    printf("\n========== PERFORMANCE SUMMARY ==========\n");
    printf("1. Linear Search works on any array.\n");
    printf("2. Binary Search requires a sorted array.\n");
    printf("3. Binary Search generally performs fewer comparisons than Linear Search.\n");
    printf("4. Insertion Sort Performance:\n");
    printf("   - Already Sorted     : Best Case  O(n)\n");
    printf("   - Random/Unsorted    : Average    O(n^2)\n");
    printf("   - Reverse Sorted     : Worst Case O(n^2)\n");
    printf("5. Number of comparisons depends on the input arrangement.\n");

    return 0;
}
