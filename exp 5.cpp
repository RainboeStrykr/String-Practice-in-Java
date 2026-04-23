#include <iostream>
#include <ctime>
using namespace std;

// Partition Function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // Choosing last element as pivot
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

// Quick Sort Function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Display Function
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

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    clock_t start, end;
    double cpu_time;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    cpu_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nArray After Quick Sort:\n";
    display(arr, n);

    cout << "\nCPU Execution Time: " << cpu_time << " seconds\n";

    return 0;
}

