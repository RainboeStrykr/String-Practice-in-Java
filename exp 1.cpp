#include <iostream>
using namespace std;
class MaxHeap {
private:
    int heap[100];
    int size;
    
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                int temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
    }
    
    void heapifyDown(int index) {
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            
            if (left < size && heap[left] > heap[largest])
                largest = left;
            
            if (right < size && heap[right] > heap[largest])
                largest = right;
            
            if (largest != index) {
                int temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;
                index = largest;
            } else {
                break;
            }
        }
    }
    
public:
    MaxHeap() : size(0) {}
    
    void insert(int value) {
        heap[size] = value;
        heapifyUp(size);
        size++;
    }
    
    int deleteMax() {
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        
        if (size > 0) {
            heapifyDown(0);
        }
        
        return maxVal;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    void display() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
    
    AVLNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLTree {
private:
    AVLNode* root;
    
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    
    int getHeight(AVLNode* node) {
        if (node == NULL)
            return 0;
        return node->height;
    }
    
    int getBalance(AVLNode* node) {
        if (node == NULL)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    
    void updateHeight(AVLNode* node) {
        if (node != NULL) {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }
    
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        updateHeight(y);
        updateHeight(x);
        
        return x;
    }
    
    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        updateHeight(x);
        updateHeight(y);
        
        return y;
    }
    
    AVLNode* insert(AVLNode* node, int value) {
        if (node == NULL) {
            return new AVLNode(value);
        }
        
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            return node;
        }
        
        updateHeight(node);
        int balance = getBalance(node);
        
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }
        
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }
        
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    void inorderTraversal(AVLNode* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
    
public:
    AVLTree() {
        root = NULL;
    }
    
    void insert(int value) {
        root = insert(root, value);
    }
    
    void displaySorted() {
        cout << "Sorted list: ";
        inorderTraversal(root);
        cout << endl;
    }
};

void heapSort(int arr[], int n) {
    MaxHeap heap;
    
    for (int i = 0; i < n; i++) {
        heap.insert(arr[i]);
    }
    
    int sorted[100];
    int index = 0;
    
    while (!heap.isEmpty()) {
        int max = heap.deleteMax();
        sorted[index++] = max;
    }
    
    cout << "\nSorted list in Ascending: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << sorted[i] << " ";
    }
    cout << endl;
}

void avlSort(int arr[], int n) {
    AVLTree avl;
    
    for (int i = 0; i < n; i++) {
        avl.insert(arr[i]);
    }
    
    avl.displaySorted();
}

int main() {
    int choice;
    
    while (true) {
        cout << "\nMENU-DRIVEN SORTING PROGRAM" << endl;
        cout << "1. Heap Sort (Max Heap)" << endl;
        cout << "2. AVL Tree Sort" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 3) {
            cout << "\nExiting program. Goodbye!" << endl;
            break;
        }
        
        if (choice != 1 && choice != 2) {
            cout << "\nInvalid choice! Please try again." << endl;
            continue;
        }
        
        int n;
        cout << "\nEnter the number of elements: ";
        cin >> n;
        
        if (n <= 0 || n > 100) {
            cout << "Invalid number! Enter between 1-100." << endl;
            continue;
        }
        
        int numbers[100];
        cout << "Enter " << n << " numbers: ";
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        
        if (choice == 1) {
            heapSort(numbers, n);
        } else if (choice == 2) {
            avlSort(numbers, n);
        }
    }
    
    return 0;
}
