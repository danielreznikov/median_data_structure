# median_data_structure
A data structure for quickly finding the median value amoungst a collection of values. 

This implementation stores supports only non-duplicate integers and is designed for fast run-time access of the median 
value amoungst inserted keys. 


# API
It exposes two public methods:

    int getMedian()     : Retrieves the median value of all ints stored in the data structure.
    void add(int value) : Safely adds value to the data structure.

# Design Choices
The data structure uses a set as the backing storage. The design is quite simple, wrapping the set API. Code complexity 
comes from mantaining the median as an instance variable without extra passes over the underlying structure.


This implementation assumes that duplicate values are not inserted. In order to support duplicate values, I could
use std::vector as the underlying storage structure but sorting a vector is expensive - O(nlogn). Alternatively, I
could mantain a map of unique keys in the set, and their respective occurance counts. While in
itself easy, this would complicate the logic for udpating the median in place.

I considered a design that allowed for constant time insertions at the expense of added compelexity for retrieving 
the median value. Ultimately, I assume that at worst, the client will retrieve the median value after every insertion, 
motivating the currrent design. 

# Complexity
Insert needs to iterate over the sorted set to identify the insertion position. The standard template library implements 
an ordered set as red-black tree, with O(log n) time for insertion of a single element. The median value is updated 
during insertion, allowing constant time complexity for retrieval.

    getMedian()     : O(1)
    add(int value)  : O(log n)


# Testing
I am using Catch2, a common test framework for C++ (https://github.com/catchorg/Catch2). Running the executable will 
automatically run the following Testcases:

1) **Empty List:** Validate that requesting a median value from an empty structure throws an exception.
2) **Forward Insertion Test:** Insert numbers in ascending order, validating the median value after each insertion.
3) **Backward Insertion Test:** Insert numbers in descending order, validating the median value after each insertion.
4) **Middle Key Insertion Test:** Validate that inserting 5 into a structure containing 3 and 7 returns 5 as the median.
5) **Negative Numbers Test:** Validate that the structure supports negative integers.
6) **Random Insertion Test:** A stress test that inserts 100 numbers at random and verifies the median value.


 # Build & Execute Instructions
 Clone this repository:
    
    git clone <URL>
 cd into the project directory:
 
    cd median_data_structure
 
 Run cmake to generate build files:
    
    cmake .
    
 Use Make to generate the executable:
 
    make
    
 Run the executable. You will see the test outputs (6 test cases, 14 assertions).
 
    ./median


