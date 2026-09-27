# Max Heap vs Linear Search – Student Score Analysis

## 1. Aim

To implement a **Max Heap** and **Linear Search** in C to find the highest student score, compare their performance, and determine the most suitable approach for continuously maintaining the highest score.

---

## 2. Problem Statement

A university wants to identify the highest student score from the following data:

**Student Scores:**

`78, 92, 65, 88, 95, 72, 84, 90`

The program performs the following tasks:

- Inserts all scores into a Max Heap.
- Records the heap arrangement after every insertion.
- Finds the highest score using a Max Heap.
- Finds the highest score using Linear Search.
- Counts the comparisons/operations.
- Compares the performance of both approaches.
- Analyses time and space complexity.
- Determines the most suitable approach for continuously maintaining the highest score.

---

## 3. Input Data

```text
78, 92, 65, 88, 95, 72, 84, 90
```

Number of students: **8**

---

## 4. Algorithm Used

### Max Heap

A Max Heap is a complete binary tree in which every parent node is greater than or equal to its children.

When a new score is inserted:

1. Insert the score at the end of the heap.
2. Compare it with its parent.
3. If the new score is greater than the parent, swap them.
4. Continue until the Max Heap property is restored.

The highest score is always stored at the root of the Max Heap.

### Linear Search

1. Assume the first score is the maximum.
2. Compare it with every remaining score.
3. If a larger score is found, update the maximum.
4. Continue until all scores are checked.
5. The final maximum is the highest score.

---

## 5. Trace Table

| Step | Inserted Score | Heap Arrangement | Comparisons |
|---|---:|---|---:|
| 1 | 78 | 78 | 0 |
| 2 | 92 | 92 78 | 1 |
| 3 | 65 | 92 78 65 | 1 |
| 4 | 88 | 92 88 65 78 | 2 |
| 5 | 95 | 95 92 65 78 88 | 2 |
| 6 | 72 | 95 92 72 78 88 65 | 1 |
| 7 | 84 | 95 92 84 78 88 65 72 | 1 |
| 8 | 90 | 95 92 90 78 88 65 72 84 | 2 |

### Final Max Heap

```text
95 92 90 78 88 65 72 84
```

---

## 6. Program Output

```text
MAX HEAP INSERTIONS
-------------------
After inserting 78: 78  | Comparisons: 0
After inserting 92: 92 78  | Comparisons: 1
After inserting 65: 92 78 65  | Comparisons: 1
After inserting 88: 92 88 65 78  | Comparisons: 2
After inserting 95: 95 92 65 78 88  | Comparisons: 2
After inserting 72: 95 92 72 78 88 65  | Comparisons: 1
After inserting 84: 95 92 84 78 88 65 72  | Comparisons: 1
After inserting 90: 95 92 90 78 88 65 72 84  | Comparisons: 2

Final Max Heap: 95 92 90 78 88 65 72 84

MAXIMUM USING MAX HEAP
Highest score: 95
Comparisons: 0 (root access)

MAXIMUM USING LINEAR SEARCH
Highest score: 95
Comparisons: 7

TOTAL INSERTION COMPARISONS: 10
```

---

## 7. Execution Results

### Max Heap

- Highest score = **95**
- Maximum is obtained directly from the root.
- Root comparisons = **0**
- Root access = **1 operation**
- Total insertion comparisons = **10**

### Linear Search

- Highest score = **95**
- Total comparisons = **7**

Both methods correctly identify **95** as the highest score.

---

## 8. Complexity Analysis

| Operation | Max Heap | Linear Search |
|---|---|---|
| Find Maximum | O(1) | O(n) |
| Insert New Score | O(log n) | O(1)* |
| Space Complexity | O(n) | O(n) |

\*For an unsorted array, insertion itself is O(1), but finding the maximum later requires O(n).

### Max Heap

- Insertion: **O(log n)**
- Finding maximum: **O(1)**
- Space: **O(n)**

### Linear Search

- Finding maximum: **O(n)**
- Space: **O(n)** for storing the input array.

---

## 9. Performance Comparison

| Feature | Max Heap | Linear Search |
|---|---|---|
| Finding Maximum | O(1) | O(n) |
| Inserting New Score | O(log n) | O(1) |
| Maximum for 8 students | Root access | 7 comparisons |
| Maintains maximum automatically | Yes | No |
| Suitable for continuous updates | Yes | Less suitable |

---

## 10. Analysis

For the given 8 scores, both methods find the highest score as **95**.

Linear Search requires checking the scores one by one. Therefore, as the number of students increases, the number of comparisons required to find the maximum also increases.

In a Max Heap, the highest score is always maintained at the root. Therefore, finding the maximum takes **O(1)** time.

Although inserting a new score into a Max Heap requires **O(log n)** time, the maximum can be obtained immediately after insertion without scanning all the students again.

---

## 11. Conclusion

The Max Heap is suitable for a system where student scores are continuously added and the highest score needs to be obtained frequently.

The main advantage is that the maximum element is always available at the root and can be accessed in **O(1)** time. New scores can be inserted in **O(log n)** time while maintaining the heap property.

Linear Search is simple and works well for a small or fixed set of scores, but finding the maximum requires **O(n)** comparisons.

Therefore, for **continuously maintaining and frequently accessing the highest student score**, a **Max Heap** provides an efficient approach.

---

## 12. Files Included

```text
Max-Heap-vs-Linear-Search/
│
├── source_code.c
├── input.txt
├── output.txt
├── trace_table.txt
├── complexity_analysis.txt
├── comparison_table.txt
└── README.md
```

---

## 13. Technologies Used

- **Programming Language:** C
- **Data Structure:** Max Heap
- **Searching Technique:** Linear Search
- **Compiler:** C Compiler
- **Version Control:** GitHub

---

## 14. Final Result

**Highest Student Score: 95**

Both Max Heap and Linear Search successfully identify the highest score.

For continuously maintaining the highest score, **Max Heap provides efficient maximum access with O(1) time and insertion with O(log n) time.**
