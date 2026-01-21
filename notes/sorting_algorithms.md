# Sorting Algorithms
At its core, sorting is just about putting data in a specific order (like 1,2,3 or A,B,C). There exists many sorting algorithms, with their use in different scenarios

## Selection Sort

### Properties
> **Time Complexity:** $\mathcal{O}(n^2)$ \
> **Space Complexity:** $\mathcal{O}(1)$ \
> **Stablity:** Unstable \
> **Adaptivity:** Non-Adaptive

### Code

```python
def selection_sort(arr):
    n = len(arr)
    
    for i in range(n):
        # Assume the current index is the minimum
        min_idx = i
        
        # Search the unsorted part of the list
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Swap the found minimum with the first element of unsorted part
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    
    return arr
```

## Bubble Sort

### Properties
> **Time Complexity:** $\mathcal{O}(n^2)$ \
> **Space Complexity:** $\mathcal{O}(1)$ \
> **Stablity:** Stable \
> **Adaptivity:** Adaptive

### Code

```python 
def bubble_sort(arr):
    n = len(arr)
    
    for i in range(n):
        # 1. Initialize the flag as False at the start of each pass
        swapped = False
        
        # 2. Last i elements are already in place
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap if the element found is greater than the next
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                # 3. If a swap happened, set flag to True
                swapped = True
        
        # 4. If no two elements were swapped by inner loop, then break
        if not swapped:
            break
            
    return arr
```

# What to Consider When Choosing an Algorithm

## Dataset Size

- **Small Datasets ($N<50$):** Simple algorithms like `InsertionSort` often outperform complex ones ($\mathcal{O}(n\log n)$) because they have very low overhead and "constant factors."

- **Large Datasets:** You almost always need an $\mathcal{O}(n \log n)$ algorithm like `QuickSort` or `MergeSort`. $\mathcal{O}(n^2)$ algorithms become exponentially slower as data grows.

## Space Constraints

- **In-Place:** Used when space is limited. Uses $\mathcal{O}(1)$ or $\mathcal{O}(\log n)$ extra space.

- **Auxillary:** Requires $\mathcal{O}(n)$ extra memory.

## Stability Requirements

- **Stable:** A stable sorting algorithm maintains the order of equal elements

- **Unstable:** An unstable algorithm may shuffle the order of equal items.

## Data Distribution (Presortedness)

- **Nearly Sorted:** Some algorithms (such as `InsertionSort`) can reach linear time ($\mathcal{O}(1)$) if the data is mostly in order.

- **Reverse:** Some algorithms (like basic `QuickSort`) can degrade to $\mathcal{O}(n^2)$ if they pick a poor "pivot" in a reversed list.

## Hardware & Cache Friendliness

- `QuickSort` is often faster than `HeapSort` in practice because it accesses memory sequentially, making better use of the CPU Cache.

- In systems programming, "cache misses" often hurt performance more than the actual number of comparisons.