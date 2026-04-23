#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Swap function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // pivot at end
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized partition
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);  // move random pivot to end
    return partition(arr, low, high);
}

// Randomized Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);

        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Display function
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nBefore Sorting:\n";
    display(arr, n);

    srand(time(0)); // seed for randomness

    clock_t start, end;

    start = clock();
    randomizedQuickSort(arr, 0, n - 1);
    end = clock();

    double cpu_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nAfter Sorting:\n";
    display(arr, n);

    cout << "\nCPU Execution Time: " << cpu_time << " seconds\n";

    return 0;
}
