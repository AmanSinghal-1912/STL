# C++ Standard Template Library (STL)

The C++ Standard Template Library (STL) provides a collection of powerful and flexible data structures and algorithms. This document covers key STL containers, including `map`, `set`, `list`, `vector`, `stack`, and `queue`.

## 1. Associative Containers

### **Map (std::map)**

- Stores key-value pairs in sorted order.
- Keys are unique.
- Implemented as a balanced binary tree (usually Red-Black Tree).
- Operations: `insert()`, `erase()`, `find()`, `[]` operator.

#### Example:

```cpp
#include <iostream>
#include <map>
using namespace std;
int main() {
    map<int, string> mp;
    mp[1] = "One";
    mp[2] = "Two";
    for (auto &p : mp) {
        cout << p.first << " : " << p.second << endl;
    }
    return 0;
}
```

### **Multimap (std::multimap)**

- Similar to `map`, but allows duplicate keys.

#### Example:

```cpp
multimap<int, string> mmp;
mmp.insert({1, "A"});
mmp.insert({1, "B"});
```

### **Unordered Map (std::unordered\_map)**

- Stores key-value pairs without any specific order.
- Implemented as a hash table.

#### Example:

```cpp
unordered_map<string, int> umap;
umap["apple"] = 5;
```

## 2. Set Containers

### **Set (std::set)**

- Stores unique elements in sorted order.

### **Multiset (std::multiset)**

- Allows duplicate values but maintains sorted order.

### **Unordered Set (std::unordered\_set)**

- Stores unique elements in no particular order.

#### Example:

```cpp
set<int> s;
s.insert(10);
s.insert(5);
```

## 3. Sequential Containers

### **List (std::list)**

- Doubly linked list, allowing fast insertions and deletions.

#### Example:

```cpp
list<int> lst = {1, 2, 3};
lst.push_back(4);
lst.push_front(0);
```

### **Vector (std::vector)**

- Dynamic array with fast random access.

#### Example:

```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);
```

## 4. Stack & Queue

### **Stack (std::stack)**

- LIFO (Last-In-First-Out) data structure.

#### Example:

```cpp
stack<int> st;
st.push(10);
st.pop();
```

### **Queue (std::queue)**

- FIFO (First-In-First-Out) data structure.

#### Example:

```cpp
queue<int> q;
q.push(1);
q.pop();
```

## Conclusion

STL provides efficient implementations for various data structures, making C++ programming easier and more optimized.

ok

