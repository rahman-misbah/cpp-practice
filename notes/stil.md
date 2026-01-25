# Standard Template Library

C++ STL provides two fundamental two kinds of components: Containers and Algorithms

## Containers

Containers are template classes that manage collections of elements. They encapsulate the underlying data structure (like arrays, linked lists, or trees) and provide member functions to manage storage, access elements, and handle memory allocation automatically.

### Sequence Containers

These maintain the linear order of elements. The position of an element depends on when and where it was inserted, rather than its value. They are ideal when you need to access elements by index or preserve a specific sequence.

---

#### Array (`std::array`)
A thin wrapper around raw C-style arrays that provides the safety and features of a standard container without any performance overhead.

- **Fixed Size:** Size must be known at compile-time and cannot change.

- **No Decay:** Unlike raw arrays, it doesn't lose its size information when passed to functions.

- **Performance:** Stored on the stack, making it faster than Vector for small, fixed collections.

- **Safety:** Supports `.at()` for bounds checking and works seamlessly with STL algorithms.

#### Vector (`std::vector`)
A dynamic array that can grow in size. It is the "default" container choice in C++ due to its excellent performance and cache friendliness.

- **Memory:** Stores elements in contiguous memory, allowing for $\mathcal{O}(1)$ random access.

- **Expansion:** When full, it reallocates a larger block of memory and moves elements. Amortized $\mathcal{O}(1)$ insertion at the end.

- **Use Case:** Best for most scenarios where you need fast lookups and frequent additions/removals at the end.

#### Deque (`std::deque`)
Short for "Double-Ended Queue." It is a hybrid structure that acts like a dynamic array but grows in both directions.

- **Structure:** Implemented as a sequence of individually allocated fixed-size pages (a "map" of pointers to blocks).

- **Efficiency:** Provides $\mathcal{O}(1)$ insertion and removal at both the front and the back.

- **Use Case:** Use when you need to add/remove elements from both ends efficiently without the cost of shifting elements (unlike Vector).
    
#### List (`std::list`)
A doubly-linked list where each element (node) points to both its successor and predecessor.

- **Non-Contiguous:** Elements are scattered in memory; it does not support random access (no `[]` operator).

- **Efficiency:** $\mathcal{O}(1)$ insertion and deletion anywhere in the list once you have an iterator to that position.

- **Use Case:** Ideal for frequent insertions/deletions in the middle of a large collection where shifting elements would be too expensive.

#### Forward List (`std::forward_list`)
A singly-linked list that only keeps track of the next element.

- **Minimalist:** It has less memory overhead than `std::list` because it only stores one pointer per node instead of two.

- **Constraints:** Can only be traversed in one direction (forward). It does not have a `.size()` member for performance reasons.

- **Use Case:** Best for high-performance, memory-constrained situations where you only need forward iteration.

### Container Adaptors

These are not independent data structures but wrappers around existing sequence containers. They restrict the interface to provide specific behaviors, such as LIFO (Last-In, First-Out) for stacks or FIFO (First-In, First-Out) for queues.

---

#### Stack (`std::stack`)
A LIFO (Last-In, First-Out) structure.

- **Logic:** Think of a stack of plates; you add to the top and take from the top.

- **Default Underlying Container:** `std::deque` (chosen because it offers $\mathcal{O}(1)$ push/pop and better memory management than vector for large stacks).

- **Operations:** `push()`, `pop()`, `top()`.

- **Use Case:** Function call stacks, "Undo" mechanisms in games, or depth-first search (DFS).

#### Queue (`std::queue`)
A FIFO (First-In, First-Out) structure.

- **Logic:** Think of a line at a store; the first person to enter is the first to leave.

- **Default Underlying Container:** `std::deque` (chosen because it allows O(1) removal from the front, which vector cannot do).

- **Operations:** `push()`, `pop()`, `front()`, `back()`.

- **Use Case:** Handling asynchronous data (like a keyboard buffer) or Breadth-First Search (BFS).

#### Priority Queue (`std::priority_queue`)
A specialized queue where the "greatest" element is always at the front.

- **Logic:** Elements are sorted as they are pushed so that the highest-priority item is always accessible.

- **Structure:** Internally implements a Max-Heap data structure.

- **Default Underlying Container:** `std::vector` (heaps are most efficient when stored in contiguous memory).

- **Operations:** `push()`, `pop()`, `top()`.

- **Use Case:** Task scheduling in an OS Kernel (running the most urgent process first) or A* Pathfinding in GameDev.

### Associative Containers

Associative Containers These implement sorted data structures (typically Red-Black Trees) that can be searched quickly. Elements are stored based on a key, and the container automatically maintains a strict ordering, allowing for $\mathcal{O}(\log n)$ search complexity.

---

#### `Set` (`std::set`)
A collection of unique keys sorted automatically.

- **Structure:** Typically a Red-Black Tree (Self-balancing binary search tree).

- **Search:** $\mathcal{O}(\log n)$—significantly faster than linear containers for large data.

- **Use Case:** When you need a sorted list of unique items (e.g., a list of unique User IDs in a game).

#### `Map` (`std::map`)
A collection of key-value pairs with unique keys.

- **Structure:** A Red-Black Tree.

- **Access:** You can access values using the `[]` operator or `.at()`.

- **Use Case:** A "Dictionary" where you map a name to an object (e.g., mapping "Player1" to their Player object).

#### `MultiSet` / `MultiMap` (`std::multiset` / `std::multimap`)
Identical to Set and Map, but they allow duplicate keys.

- **Use Case:** A MultiMap could store high scores, where multiple players (keys) might have the exact same score.

### Unordered Associative Containers

Similar to associative containers, but they use Hash Tables instead of trees. They do not maintain any specific order, but they offer superior performance for lookups, typically achieving $\mathcal{O}(1)$ average time complexity.

---

#### Unordered Set (`std::unordered_set`)
A collection of unique keys with no specific order.

- **Performance:** $\mathcal{O}(1)$ average for Search, Insertion, and Deletion. (Worst case $\mathcal{O}(n)$ if many hash collisions occur).

- **Requirement:** The key must be "Hashable" (C++ provides hashes for primitives and strings).

- **Use Case:** Fast membership checking—e.g., a "Ban List" in a game where you just need to know "Is this User ID in the set?" as fast as possible.

#### Unordered Map (`std::unordered_map`)
A collection of unique key-value pairs.

- **Philosophy:** This is the C++ version of a Python Dictionary or a HashMap in other languages.

- **Structure:** Uses a "Buckets" array. If two different keys hash to the same bucket, it's called a Collision, usually handled by a linked list inside that bucket.

- **Use Case:** Resource management in GameDev—e.g., mapping a "Texture Name" (`string`) to a "`Texture ID`" (int).

#### Unordered MultiSet / Unordered MultiMap (`unordered_multiset` / `unordered_multimap`):

Identical to the above, but allow duplicate keys.

- **Use Case:** A MultiMap could store a "Word Frequency" index for a search engine where one word (key) maps to multiple page locations (values).

## Algorithms

Algorithms are template functions used to manipulate the data within containers. Because the STL separates data (Containers) from logic (Algorithms), these functions are generic; they interact with containers through Iterators rather than accessing memory directly. This allows a single algorithm, like find, to work on a Vector, a List, or even a raw C-style array.

### Searching & Range Queries

These algorithms locate elements or determine boundaries within a sorted range.

- **`binary_search`:** Checks if a specific value exists in a sorted range, returning a boolean.

- **`lower_bound` / `upper_bound`:** Essential for sorted data; lower_bound finds the first element not less than a value, while upper_bound finds the first element strictly greater. Together, they define the range of equivalent elements.

### Comparison & Extremes

Used to find values or compare elements based on specific criteria.

- **`min` / `max`:** Returns the smaller or larger of two values (or the smallest/largest in an entire range).

- **`min_element` / `max_element`:** Returns an iterator to the smallest or largest value in a container.

### Sequence Manipulation

These algorithms modify the order or arrangement of elements without necessarily changing their values.

- **`reverse`:** Flips the order of elements in a range.

- **`rotate`:** Shifts elements in a circular fashion so that a given element becomes the new first element.

- **`swap`:** Exchanges the values of two objects or elements.

### Sorting

Sorting is often the most performance-critical part of an application, especially in GameDev.

- **`sort`** Rearranges elements into ascending or descending order. In C++, this is typically implemented as Introsort, providing O(nlogn) complexity.

- **`stable_sort`:** Similar to sort, but preserves the relative order of elements with equal keys.