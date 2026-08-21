#include<iostream>
#include<vector>
#include<utility> // Required explicitly for std::pair
using namespace std;

void explainVector(){
    
    // 1. INITIALIZATION & INSERTION
 
    vector <int> v;
    v.push_back(1);    // Adds 1 to the back. Copies/moves the element into memory.
    v.emplace_back(2); // Adds 2 to the back. Constructs the element directly in-place (faster).

    vector <pair<int,int>> u ;
    u.push_back ({1,2}); // push_back needs explicit curly braces to create a pair first
    u.emplace_back (2,3); // emplace_back accepts raw comma-separated arguments directly
    
    vector<int> v1 (5,100); // Size 5, filled with 100: {100, 100, 100, 100, 100}
    vector<int> v2 (5);     // Size 5, filled with default 0s: {0, 0, 0, 0, 0}
    vector<int> v3 (v2);    // Copy constructor: v3 becomes an independent copy of v2: {0, 0, 0, 0, 0}

    
    // 2. ITERATORS & RANDOM ACCESS

    // v3 = {0, 0, 0, 0, 0}
    vector<int>:: iterator it = v3.begin(); // Points to index 0
    it++;                                   // Moves to index 1
    cout << *(it) << " ";                   // Prints value at index 1 -> '0'
    it = it + 2;                            // Vector iterators support arithmetic! Moves to index 3
    cout << *(it) << endl;                  // Prints value at index 3 -> '0'

    // Endpoint boundaries:
    vector<int>:: iterator pt = v1.end();           // Points RIGHT AFTER the last element (Index 5). Do not dereference!
    vector<int>:: reverse_iterator qt = v1.rend();   // Reverse end: Points RIGHT BEFORE the first element.
    vector<int>:: reverse_iterator rt = v1.rbegin(); // Reverse begin: Points exactly at the last element.

    // Element Access Methods:
    cout << v1[2] << " " << endl;    // Array style: Fast, but unsafe (No bounds checking)
    cout << v1.at(2) << " " << endl; // Function style: Safer (Throws out_of_range exception if invalid)

    
    // 3. LOOPING THROUGH VECTORS

    // Method A: Manual Iterator Loop (Using comparison operator '<')
    for (vector<int>:: iterator it = v1.begin(); it < v1.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    // Method B: Clean Iterator Loop (Using standard inequality '!=' and 'auto' shorthand)
    for (auto it = v1.begin(); it != v1.end(); it++) {
        cout << *(it) << " ";
    }
    cout << " ";

    // Method C: Range-Based For Loop (Cleanest syntax, reads elements directly as values)
    for (auto x : v1) {
        cout << x << " ";
    }
    cout << endl;

 
    // 4. DELETING ELEMENTS (ERASE)
   
    vector<int> v4; 
    v4.push_back(11); v4.push_back(12); v4.push_back(19); v4.push_back(13); v4.push_back(15);
    // Initial state: v4 = {11, 12, 19, 13, 15}

    // Single element deletion example (commented out):
    // v4.erase(v4.begin()+1); // Deletes element at index 1 (12) -> {11, 19, 13, 15}
    
    // Range deletion: [start, end) -> 'start' is INCLUDED, 'end' is EXCLUDED!
    // v4.begin()+2 points to 19. v4.begin()+4 points to 15.
    // Elements at index 2 and 3 (19 and 13) are wiped out.
    v4.erase(v4.begin()+2, v4.begin()+4); 
    // State now: v4 = {11, 12, 15}
   
   
    // 5. INSERTING ELEMENTS (INSERT)
    
    // Insert single value: v4.insert(iterator, value)
    v4.insert(v4.begin()+1, 32); 
    // State now: v4 = {11, 32, 12, 15}

    // Insert copies: v4.insert(iterator, count, value)
    v4.insert(v4.begin()+2, 3, 13); // Inserts the number 13 three times starting at index 2
    // State now: v4 = {11, 32, 13, 13, 13, 12, 15}

    // Insert an entire vector range into another:
    vector<int> v5 = {2, 3};
    // Copies everything from v4's start to finish and inserts it at the very beginning of v5
    v5.insert(v5.begin(), v4.begin(), v4.end());
    
    // Loop Prints: 11 32 13 13 13 12 15 2 3 
    for(auto x : v5) {
        cout << x << " "; 
    }
    cout << endl;

   
    // 6. UTILITY FUNCTIONS
   
    cout << v5.size() << endl; // Returns current number of elements -> 9
    
    v5.pop_back(); // Removes the very last element (drops 3) -> v5 size becomes 8

    // Swap: O(1) constant time operation. Swaps underlying pointers, extremely fast.
    v5.swap(v4); // v5 now contains v4's data, v4 now contains v5's data

    v4.clear(); // Wipes out all elements from v4, reducing its size to 0

    cout << v4.empty(); // Returns 1 (true) if empty, 0 (false) if it contains elements -> Prints '1'
}

int main() {
    explainVector();
    return 0;
}
