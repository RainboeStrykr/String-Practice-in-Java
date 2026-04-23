# List of Experiments — Design and Analysis of Algorithms (DAA) Lab

---

## Experiment 1: Heap and AVL Tree Data Structures

**Aim:** Use heaps and AVL trees to sort a list of numbers in increasing order.

Design a menu-driven C/C++ program to sort a list of numbers using Heap and AVL Tree data structures based on the user's choice.

**Choice 1 — Heap Sort:**
Insert the elements into a max-heap one at a time, starting from an empty heap. Then perform repeated `deletemax` operations (which rebuild the heap automatically) to obtain the sorted order.

**Choice 2 — AVL Tree Sort:**
Insert the elements into an AVL tree one at a time, starting from an empty AVL tree. Traverse the AVL tree in the appropriate order (in-order traversal) to obtain the sorted list.

---

## Experiment 2: Insertion Sort and Bubble Sort

**Aim:** Design and implement a menu-driven program to sort a given set of integers using Bubble Sort and Insertion Sort algorithms.

- `n` should be at least 10,000 to ensure meaningful performance evaluation.
- The program must provide options to perform Bubble Sort or Insertion Sort based on the user's choice, and sort elements in ascending order.
- After each sorting operation, the sorted array should be displayed.
- For each algorithm, CPU execution time must be measured using the same input data and compared with the execution times from Experiment 1 (Heap Sort and AVL Tree Sort).

**Note:**
- `clock()` returns the CPU time used by the program.
- `CLOCKS_PER_SEC` gives clock ticks per second.
- CPU Time Formula: `CPU Time = (end - start) / CLOCKS_PER_SEC`

---

## Experiment 3: Brute Force String Matching

**Aim:** Develop a program to perform string matching using the Brute Force algorithm technique.

The program should:
1. Accept a main string (text) and a pattern string from the user.
2. Apply the Brute Force String Matching algorithm to search for the pattern in the given text.
3. Display all starting indices where the pattern is found.
4. Display a suitable message if the pattern is not found.

**Objective:** Understand the working of the Brute Force string matching technique and analyze its performance through direct character comparisons.

---

## Experiment 4: Merge Sort and Binary Search

**Aim:** Develop a program to implement Divide and Conquer algorithms — Merge Sort and Binary Search.

The program should:
1. Accept a set of `n` integer elements from the user.
2. Sort the elements using the Merge Sort algorithm (Divide and Conquer).
3. After sorting, search for a given key element using Binary Search.
4. Display the sorted array.
5. Display the position of the searched element if found, or an appropriate message if not found.

**Objective:** Understand the Divide and Conquer paradigm and analyze the efficiency of Merge Sort and Binary Search algorithms.

---

## Experiment 5: Quick Sort

**Aim:** Develop a program to sort a given set of elements using the Quick Sort algorithm based on the Divide and Conquer technique.

The program should:
1. Accept `n` integer elements from the user.
2. Apply Quick Sort by selecting a pivot element (first, last, middle, or random) and partitioning the array so that elements smaller than the pivot are on the left and greater elements are on the right, then recursively sort both subarrays.
3. Display the array elements before and after sorting.
4. Measure CPU execution time and compare it with Merge Sort from Experiment 4.

**Objective:** Understand the working of Quick Sort and analyze its performance using the Divide and Conquer approach.

---

## Experiment 6: Strassen's Matrix Multiplication

**Aim:** Design and implement a program to multiply two square matrices using Strassen's Matrix Multiplication algorithm based on the Divide and Conquer technique.

The program should:
1. Read two square matrices of order `n × n` from the user.
2. Apply Strassen's algorithm to compute the product by recursively dividing matrices into submatrices.
3. Display the resultant matrix after multiplication.
4. Measure CPU execution time and compare it with conventional matrix multiplication.

**Objective:** Understand the efficiency of Strassen's algorithm and analyze its performance compared to conventional matrix multiplication.

---

## Experiment 7a: Huffman Coding

**Aim:** Design and implement a program to generate Huffman codes for a given set of characters and their frequencies using the Greedy algorithm technique.

The program should:
1. Read the characters and their corresponding frequencies.
2. Construct a Huffman Tree by repeatedly selecting the two nodes with the minimum frequencies.
3. Assign binary codes to each character based on the constructed Huffman Tree.
4. Display the Huffman codes for all characters.
5. Calculate the total number of bits required to encode the given data.

**Objective:** Understand data compression using Huffman coding and analyze the effectiveness of the Greedy approach in minimizing average code length.

---

## Experiment 7b: Fractional Knapsack (Greedy)

**Aim:** Design and implement a program to solve the Fractional Knapsack problem using the Greedy approach.

The program should:
1. Read the number of items along with their weights and profits.
2. Read the capacity of the knapsack.
3. Compute the profit-to-weight ratio for each item.
4. Select items based on the maximum profit-to-weight ratio (greedy choice).
5. Display the selected items and the maximum profit obtained.

**Objective:** Understand the application of the Greedy method in solving optimization problems such as the Fractional Knapsack problem.

---

## Experiment 8: Longest Common Subsequence (Dynamic Programming)

**Aim:** Design and implement a program to find the Longest Common Subsequence (LCS) between two given sequences using the Dynamic Programming technique.

The program should:
1. Accept two input sequences (strings) from the user.
2. Construct a dynamic programming table to compute the length of the LCS.
3. Trace back through the table to obtain the actual longest common subsequence.
4. Display the length of the LCS and the LCS string.

**Objective:** Understand the Dynamic Programming approach and analyze its effectiveness in solving the Longest Common Subsequence problem.

---

## Experiment 9: N-Queens Problem (Backtracking)

**Aim:** Design and implement a program to solve the N-Queens problem using the Backtracking technique.

The program should:
1. Read the number of queens `N` from the user.
2. Place `N` queens on an `N × N` chessboard such that no two queens attack each other.
3. Ensure no two queens share the same row, column, or diagonal.
4. Generate and display all possible valid solutions (or at least one solution, as specified).
5. Display a suitable message if no solution exists for the given value of `N`.

**Objective:** Understand the Backtracking approach and analyze its efficiency in solving combinatorial problems.

---

## Experiment 10: Travelling Salesman Problem (Backtracking)

**Aim:** Design and implement a program to solve the Travelling Salesman Problem (TSP) for a given set of cities using the Backtracking technique.

The program should:
1. Read the number of cities `n` and the distance (cost) matrix representing distances between each pair of cities.
2. Determine the minimum cost tour that starts from a given city, visits each city exactly once, and returns to the starting city.
3. Display the optimal tour and the minimum travel cost.
4. Display a suitable message if no feasible tour exists.

**Objective:** Understand combinatorial optimization problems and analyze algorithmic strategies used to solve the Travelling Salesman Problem.

---

## Experiment 11: Randomized Quick Sort

**Aim:** Design and implement a program to sort a given list of elements using the Randomized Quick Sort algorithm.

The program should:
1. Read `n` elements from the user.
2. Select the pivot element randomly for each partition to reduce the chances of worst-case performance.
3. Partition the array so that elements less than the pivot are on its left and elements greater than the pivot are on its right.
4. Recursively apply Randomized Quick Sort to the left and right subarrays.
5. Display the list of elements before and after sorting.
6. Measure CPU execution time and compare it with the standard Quick Sort from Experiment 5.

**Objective:** Understand the concept of randomized algorithms and analyze how random pivot selection improves the average performance of Quick Sort.

---

## Experiment 12: Rabin–Karp String Matching

**Aim:** Design and implement a program to perform string matching using the Rabin–Karp algorithm.

The program should:
1. Read a text string and a pattern string from the user.
2. Compute the hash value of the pattern and the hash values of all possible substrings of the text having the same length as the pattern, using a rolling hash technique.
3. Compare hash values to identify potential matches and verify them using character-by-character comparison to avoid false positives.
4. Display all starting index positions where the pattern occurs in the text.
5. Display a suitable message if the pattern is not found.
6. Measure CPU execution time and compare it with the Brute Force string matching from Experiment 3.

**Objective:** Understand hashing-based string matching techniques and analyze the efficiency of the Rabin–Karp algorithm.
