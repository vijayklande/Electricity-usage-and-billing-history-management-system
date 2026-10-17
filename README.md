  Electricity Billing System

 1. About the Project

The Electricity Billing System is a C++ project developed to manage electricity consumer records and calculate monthly electricity bills. It uses a **Doubly Linked List** to store and manage consumer details and billing history. The system allows users to register consumers, add monthly billing records, display billing history, and search for consumer records using a simple menu-driven interface.

 2. Features

 Basic Features

- **Register New Consumer:** Register a consumer with a unique ID, name, and initial meter reading.
- **Add Monthly Billing Record:** Enter the current meter reading and rate per unit to calculate the electricity bill.
- **Display Billing History:** View consumer details, previous readings, current readings, units consumed, and bill amounts.
- **Search Consumer Record:** Find billing records using the consumer ID.
- **Exit System:** Exit the program safely.

 Electricity Billing Management Features

- **Consumer Identification:** Use a consumer ID to identify each registered consumer.
- **Meter Reading Tracking:** Store previous and current meter readings.
- **Unit Calculation:** Calculate electricity consumption by subtracting the previous reading from the current reading.
- **Bill Calculation:** Calculate the total bill by multiplying units consumed by the rate per unit.
- **Input Validation:** Prevent duplicate consumer registration, negative initial readings, decreasing meter readings, and negative electricity rates.
- **Billing History:** Maintain multiple billing records for consumers using a linked list.

 3. Data Structure Used

**Doubly Linked List**

Each node stores:

- Consumer ID
- Consumer name
- Previous meter reading
- Current meter reading
- Units consumed
- Billing month
- Rate per unit
- Total bill amount
- Pointer to the previous node
- Pointer to the next node

This structure allows consumer and billing records to be stored dynamically. Each node contains pointers to the previous and next nodes, making it suitable for managing a sequence of records.

4. Technologies Used

- C++
- Structures and pointers
- Dynamic memory allocation
- Doubly Linked List
- Functions
- Conditional statements and loops
- Menu-driven programming
- Basic input validation

5. Applications

- Basic electricity billing management
- Consumer record management
- Monthly electricity consumption tracking
- Electricity bill calculation
- Learning data structures through a practical example

6. Conclusion

This project demonstrates how a doubly linked list can be used to manage electricity consumer records and monthly billing information. It provides basic operations for registering consumers, calculating electricity bills, displaying billing history, and searching for records. The project also demonstrates the practical application of C++ structures, pointers, dynamic memory allocation, and functions. It can be further improved by adding features such as bill payment tracking, late payment charges, report generation, and file handling for permanent data storage.


