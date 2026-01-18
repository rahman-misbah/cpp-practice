# Breakdown of The Template Used for Finding The Peak Element

The template of finding the peak element in a sequence is:

```cpp
int peak(int arr[], int size) {
    int low = 0;
    int high = size - 1;

    while(low < high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] < arr[mid+1]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }

    return low;
}
```

## How Array Bounds are Ensured

The only statement that accesses index is the `if` statement with the condition `arr[mid] < arr[mid + 1]`. This is the only place where out of range index can be a problem.

### How `mid` is Calculated

`mid` is calculated as `(low + high) / 2`. Let `low = n - 1` and `high = n`, then:

$$
\text{mid} = \lfloor \frac {n + n - 1}{2} \rfloor = \lfloor n - \frac 1 2 \rfloor = n - 1
$$

Hence, `mid` will always be a valid index.

>NOTE: `low` cannot be `n`, as the loop condition won't allow it.

### Updation of `low`

- Since `mid < high` is always true, **it is guaranteed that an index exists after `mid`** as long as the loop is valid.
- `if` check ensures that `mid + 1` is greater than `mid`, **eliminating any chances of `mid` being the peak**. This makes it safe to skip `mid`

Keeping the above two conditions in mind, it is safe to skip `mid` and update `low` as `low = mid + 1`

### Updation of `high`
Since `else` performs no condition checks, there is no guarantee that
- `mid - 1` is a valid index (`mid` can be 0 in case of an array of 2 element)
- `mid` is not the peak (since `if` has failed, `mid` has proven that it is the greatest number seen yet)

Keeping the above two conditions in mind, it is not safe to skip `mid`. Hence, `high` is updated as `high = mid`

## Result
`low` can never cross high, as the loop breaks when `low == high`. As a result, when the loop breaks, `low` is always equal to `high`, which is the peak. Thus, the result is can be returned using either `low` or `high`

## Remarks
The above approach ensures that
- Array boundaries are not violated
- No element is skipped without checking

making it a robust algorithm. However, the implicit nature of the checks makes the robustness unobvious.