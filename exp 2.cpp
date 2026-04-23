#include <iostream>
#include <ctime>   // for clock()
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter number of elements";
    cin >> n;

    int arr[n], temp[n];

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    clock_t start, end;
    double cpu_time;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Copy original array
        for (int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }

        switch (choice) {
            case 1:
                start = clock();               // Start time
                bubbleSort(temp, n);
                end = clock();                 // End time

                cpu_time = double(end - start) / CLOCKS_PER_SEC;

                cout << "Sorted array using Bubble Sort:\n";
                display(temp, n);
                cout << "CPU Execution Time: " << cpu_time << " seconds\n";
                break;

            case 2:
                start = clock();               // Start time
                insertionSort(temp, n);
                end = clock();                 // End time

                cpu_time = double(end - start) / CLOCKS_PER_SEC;

                cout << "Sorted array using Insertion Sort:\n";
                display(temp, n);
                cout << "CPU Execution Time: " << cpu_time << " seconds\n";
                break;

            case 3:
                cout << "Exiting program ??\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}

