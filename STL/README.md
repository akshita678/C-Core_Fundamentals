# C++ STL Vectors & Algorithms Practice
My code exploring the C++ Standard Template Library (STL). I practiced adding, deleting, inserting, sorting, and using binary search inside a vector container, and I even caught a few small comment bugs along the way!

## 📝 Concept Description
A `std::vector` is a dynamic array in C++ that can change its size automatically when elements are added or deleted. Unlike regular arrays where the size is fixed at the start, vectors manage their own memory footprint, making them perfect for DSA problem-solving.

---

## 💡 Code Breakdown & Observations

### 1. Vector Operations & Bug Tracking
I tested out the basic operations for managing data inside a vector:
* **Dynamic Sizing:** Using `push_back()` adds an element to the end, and `pop_back()` removes the last element.
* **Random Insertion:** Using `v.insert(v.begin() + 1, 78)` shifts elements to squeeze `78` exactly into index 1.
* **STL Algorithms:** I used `sort()` to order the array from smallest to largest and `binary_search()` to look for an element in $O(\log n)$ time.

### ⚠️ My Catch (The Comment Bugs)
While reviewing my output logs, I noticed my code comments had a couple of mistakes about what `v.size()` actually returns:
* **The First Sizing Comment:** After pushing 4 items and popping 1, my comment said `// returns 1`. But since there are still 3 items left in the array, `v.size()` actually returns **3**!
* **The Second Sizing Comment:** After running the insert operation, the vector grew by 1 more item. My comment said `// return 4`, which is completely correct here! 

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // needed for sort function
using namespace std;

int main(){
    vector<int> v;
    
    // adding new values into vector 
    v.push_back(90);
    v.push_back(89);
    v.push_back(78);
    v.push_back(98);
    
    // deleting values 
    v.pop_back();
    cout << v.size(); // Note: This actually prints 3, not 1!
    
    // insertion 
    v.insert(v.begin() + 1, 78); // adds 78 at 1st index 
    cout << v.size(); // prints 4 
    
    // sorting in vector 
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; 
    }
    
    // binary search
    int ans = binary_search(v.begin(), v.end(), 90); // returns 1 (true) because 90 is present 
    cout << ans << endl;
    
    // clearing a vector 
    // v.clear(); // clears entire vector
    
    return 0;
}
```

---

## 📊 Complexity Analysis

| Operation | Complexity | Reason |
| :--- | :--- | :--- |
| **push_back() / pop_back()** | `O(1)` | Adding or deleting from the very end of a vector takes constant time. |
| **insert()** | `O(n)` | Inserting at an index forces all elements after it to shift over by one slot. |
| **sort()** | `O(n log n)` | The STL sort algorithm uses Introsort, which scales logarithmically with array size. |
| **binary_search()** | `O(log n)` | Since the array is sorted, it discards half the search pool during every single step. |

---

## 🛠️ How to Run Locally
You can test these STL commands on your machine by copying the code block directly into a local file.

1. **Save the file:** Save the code as `main.cpp`.
2. **Run it in terminal:**
```bash
g++ main.cpp -o main
./main
```
