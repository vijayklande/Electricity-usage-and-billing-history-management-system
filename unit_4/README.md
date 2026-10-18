Family Tree Representation Using Array and Wasted Space Analysis

1. About the Project

The Family Tree Representation Using Array and Wasted Space Analysis is a C++ project developed to store family members in an array and represent their parent-child relationships. The program allows users to enter the array size, store family member names, identify missing members, display each node's index, and calculate the number of empty array slots. It uses array-based binary tree representation to organize family members.

2. Features

Basic Features

Array size input: Allow users to specify the size of the array.

Store family members: Enter family member names at different array indices.

Missing members: Enter - to represent a missing family member.

Display family tree: Display family members with their respective indices.

Show node index: Display the array index of each node.

Parent identification: Display the parent of each family member.

Child identification: Display the left and right children of each family member.


Space Utilization Features

Occupied slots: Calculate the number of array positions containing family members.

Wasted slots: Count the empty array positions.

Missing node detection: Identify positions where family members are missing.

Space analysis: Demonstrate how missing members affect array utilization.


3. Data Structure Used

Array-Based Binary Tree

The project uses a dynamically sized array implemented with vector<string> to store family members.

Each array position represents a node in the binary tree.

The following formulas are used to identify relationships:

Root node: Index 0

Parent node: (i - 1) / 2

Left child: 2 * i + 1

Right child: 2 * i + 2


This representation helps identify parent-child relationships and demonstrates how missing nodes can leave empty array slots.

4. Technologies Used

C++

Arrays and vectors

Strings

Binary tree representation

Loops and conditional statements

Dynamic memory management through vector


5. Applications

Representing hierarchical family information.

Understanding array-based binary tree representation.

Learning parent-child relationships in tree data structures.

Studying memory utilization and empty array slots.

Understanding the limitations of array-based tree storage when nodes are missing.


6. Conclusion

This project demonstrates how a family tree can be represented using an array in C++. It identifies parent-child relationships, displays node indices, detects missing family members, and calculates empty array slots. The project helps explain binary tree representation, array traversal, and space utilization in data structures.

7. Language

C++
