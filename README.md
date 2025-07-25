# Vectors
During my in-depth study of the C++ programming language, I began exploring data structures. Arrays were a natural starting point, given their widespread use in programming. After reviewing educational materials, including video lectures and specialized articles, I am ready to present the results of my work and share the conclusions I have drawn.

### **Vector Class Implementation**

The vector implementation will utilize object-oriented programming (OOP) principles.

#### **Private Class Members**

The class will contain the following private members:

- A pointer to the dynamically allocated data array
    
- The current size of the vector
    
- The maximum capacity of allocated memory
    

Additionally, a method for dynamic array resizing will be implemented to ensure efficient memory reallocation when necessary.

#### **Public Class Interface**

In addition to standard constructors (including default, copy, and move constructors) and a destructor that ensures proper memory deallocation, the class will include the following methods:

**Element Addition and Removal:**

- `push_back()` - adds an element to the end of the vector
    
- `pop_back()` - removes the last element
    

**Vector State Information:**

- `size()` - returns the current number of elements
    
- `capacity()` - returns the current allocated memory capacity
    
- `empty()` - checks whether the vector is empty
    

**Element Access:**

- `operator[]` - provides indexed access to elements
    

**Element Insertion and Removal at Arbitrary Positions:**

- `push()` - inserts an element at a specified position
    
- `pop()` - removes an element from a specified position
