# Airport Direct Flight Connections Using Adjacency Matrix

## Problem Statement
Develop a graph using an adjacency matrix to represent airports and direct flight connections, and display the available direct flights from each airport.

## Objective
To implement a graph using an adjacency matrix in C++ to represent airports and their direct flight connections.

## Concepts Used
 Graph
 Adjacency Matrix
 Two-Dimensional Array
 Strings
 Nested Loops
 Conditional Statements

## Description
This project represents airports as vertices and direct flight connections as edges in a graph. An adjacency matrix stores the connections between airports.

The user enters the number of airports, their names, and the direct flight connections. The program displays the adjacency matrix and lists all available direct flights from each airport.

## Working
1. Enter the number of airports.
2. Enter the names of the airports.
3. Enter the direct flight connections between airports.
4. Enter 1 if a direct flight exists and 0 if no direct flight exists.
5. Display the adjacency matrix.
6. Display the available direct flights from each airport.

## Example

Consider four airports: Pune, Mumbai, Delhi, and Chennai.

### Adjacency Matrix

| Airport | Pune | Mumbai | Delhi | Chennai |
|---------|------|--------|-------|---------|
| Pune    | 0    | 1      | 1     | 0       |
| Mumbai  | 1    | 0      | 1     | 1       |
| Delhi   | 0    | 1      | 0     | 1       |
| Chennai | 0    | 1      | 0     | 0       |

### Output

    Available Direct Flights:

    Pune -> Mumbai Delhi
    Mumbai -> Pune Delhi Chennai
    Delhi -> Mumbai Chennai
    Chennai -> Mumbai

## Algorithm
1. Start the program.
2. Read the number of airports.
3. Store the airport names.
4. Initialize the adjacency matrix with zeros.
5. Read the direct flight connections.
6. Display the adjacency matrix.
7. Traverse each row to find direct flight connections.
8. Display the available direct flights from each airport.
9. Stop the program.

## Time and Space Complexity
 •Time Complexity: O(n²)
 •space Complexity: O(n²)

Here, n represents the number of airports.

## Applications
  Airline route management
  Airport connectivity representation
  Flight network analysis
  Graph-based network systems

## Technologies Used
  Programming Language: C++
  Data Structure: Graph
  Graph Representation: Adjacency Matrix

## Limitations
  The program supports a maximum of 20 airports.
  Flight connections are entered manually.
  Flight connections are directional. A flight from one airport to another does not automatically mean a return flight is available.

## Conclusion
This project demonstrates graph implementation using an adjacency matrix in C++. It represents airport connectivity and displays the available direct flights from each airport.
