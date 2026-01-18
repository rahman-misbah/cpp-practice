# Binary Search
It is an efficient searching algorithm that works on **monotonic sequences**, which are sequence that consistently move in one direction (either increasing or decreasing).

## Complexities
- Time Complexity: $\mathcal{O}(\log N)$
- Space Complexity: $\mathcal{O}(1)$

## Number of Comparisons
To calculate the number of comparisons, the following formula used is
$$\text{Comparisons} = \lfloor \log_2N\rfloor + 1$$

Where $\lfloor x \rfloor$ is the floor function.