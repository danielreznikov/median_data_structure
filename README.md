# median_data_structure
A data structure for quickly finding the median value.

# API
It exposes two public methods:
    int getMedian();
    void add(int value);

# Idea
The data structure uses a linked-list as the backing storage.
Insert needs to iterate over the sorted linked-list to identify the insertion position.
The median value is updated during insertion. As a result, we achieve fast retrievals and reasonable insertions with a time complexity of:
    getMedian()     : O(1)
    add(int value)  : O(n)

# Testing
I am using Catch2, a common test framework for C++ (https://github.com/catchorg/Catch2). Testcases:
    1) Empty List: Validate that requesting a median value from an empty structure throws an exception.
    2) Forward Insertion Test: Insert numbers in ascending order, validating the median value after each insertion.
    3) Backward Insertion Test: Insert numbers in descending order, validating the median value after each insertion.
    4) Middle Key Insertion Test: Validate that inserting 5 into a structure containing 3 and 7 returns 5 as the median.
    5) Negative Numbers Test: Validate that the structure supports negative integers.
    6) Random Insertion Test: A stress test that inserts 100 numbers at random and verifies the median value.

 # Build & Execute Instructions
    1) Clone this repository
        git clone <URL>
    2) cd median_data_structure
    3) Run cmake to generate the build files
        cmake .
    4) Use Make to generate the executable
        make
    5) Run the executable. You will see the test outputs (6 test cases, 14 assertions).
        ./median


