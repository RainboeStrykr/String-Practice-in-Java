#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Function to add two matrices
vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B, int size) {
    vector<vector<int>> C(size, vector<int>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to subtract two matrices
vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B, int size) {
    vector<vector<int>> C(size, vector<int>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen function
vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B, int size) {

    vector<vector<int>> C(size, vector<int>(size));

    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int newSize = size / 2;

    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    // Dividing matrices into submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // 7 Recursive multiplications
    auto M1 = strassen(add(A11, A22, newSize), add(B11, B22, newSize), newSize);
    auto M2 = strassen(add(A21, A22, newSize), B11, newSize);
    auto M3 = strassen(A11, subtract(B12, B22, newSize), newSize);
    auto M4 = strassen(A22, subtract(B21, B11, newSize), newSize);
    auto M5 = strassen(add(A11, A12, newSize), B22, newSize);
    auto M6 = strassen(subtract(A21, A11, newSize), add(B11, B12, newSize), newSize);
    auto M7 = strassen(subtract(A12, A22, newSize), add(B21, B22, newSize), newSize);

    // Computing C submatrices
    auto C11 = add(subtract(add(M1, M4, newSize), M5, newSize), M7, newSize);
    auto C12 = add(M3, M5, newSize);
    auto C21 = add(M2, M4, newSize);
    auto C22 = add(subtract(add(M1, M3, newSize), M2, newSize), M6, newSize);

    // Combining submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

int main() {
    int n;
    cout << "Enter order of square matrices (power of 2): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    cout << "Enter Matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter Matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    clock_t start, end;

    start = clock();
    vector<vector<int>> C = strassen(A, B, n);
    end = clock();

    double cpu_time = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nResultant Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    cout << "\nCPU Execution Time: " << cpu_time << " seconds\n";

    return 0;
}
