# Binary Search
It is an efficient searching algorithm that works on **monotonic sequences**, which are sequence that consistently move in one direction (either increasing or decreasing).

## Complexities
- Time Complexity: $\mathcal{O}(\log N)$
- Space Complexity: $\mathcal{O}(1)$

## Number of Comparisons
To calculate the number of comparisons, the following formula used is
$$\text{Comparisons} = \lfloor \log_2N\rfloor + 1$$

Where $\lfloor x \rfloor$ is the floor function.

## Applications
- Find **first occurrence** of an element in a sorted array
- Find **last occurrence** of an element in a sorted array
- Find **total occurrence** of an element in a sorted array
- Find peak element in a **bitonic sequence** (strictly increasing then strictly decreasing)
- Find pivot element in a **rotated sorted array**