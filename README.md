# Electricity Usage and Billing History Manager

## Project Overview
The Electricity Usage and Billing History Manager is a C++ console-based project developed using Data Structures and Algorithms (DSA). It manages monthly electricity consumption records, calculates estimated electricity bills, and maintains billing history.

## Technologies Used
- Programming Language: C++
- Data Structures: Doubly Linked List and Stack using Linked List
- Concepts: Dynamic Memory Allocation, Searching, Insertion, Deletion, Updating, and Undo Operations

## Features
1. **First-Time Meter Registration** – Registers the initial electricity meter reading.
2. **Add Monthly Billing Record** – Calculates units consumed and the estimated bill.
3. **Display All Records** – Displays complete electricity billing history.
4. **Search Record** – Searches for a billing record by month and year.
5. **Update Record** – Updates an existing billing record.
6. **Delete Record** – Deletes a selected billing record.
7. **Undo Last Operation** – Reverses the latest addition, deletion, or update.
8. **Navigate Records** – Moves forward and backward through billing records.
9. **Yearly Totals** – Calculates total electricity consumption and estimated bills for a selected year.

## Data Structures Used

### 1. Doubly Linked List
Each billing record contains:
- Month and year
- Previous meter reading
- Current meter reading
- Units consumed
- Estimated bill

Each node contains `prev` and `next` pointers, allowing traversal in both directions.

### 2. Stack Using Linked List
The stack stores previous operations for undo functionality. It follows the **LIFO (Last In, First Out)** principle.

## Electricity Bill Calculation
The program uses an example rate of ₹6 per unit.

