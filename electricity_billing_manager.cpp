#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const double RATE = 6.0;  // Example rate per unit

// Monthly billing record
struct RecordData {
    string month;
    int year;
    double previousReading;
    double currentReading;
    double units;
    double bill;
};

// Doubly linked list node
struct Node {
    RecordData data;
    Node* prev;
    Node* next;
};

// Stack node for Undo
struct StackNode {
    char action;
    RecordData data;
    StackNode* next;
};

Node* head = nullptr;
Node* tail = nullptr;
StackNode* undoTop = nullptr;

// Find a monthly record
Node* findRecord(string month, int year) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data.month == month &&
            temp->data.year == year) {
            return temp;
        }
        temp = temp->next;
    }

    return nullptr;
}

// Insert a record at the end
void insertRecord(RecordData data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = tail;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Push action onto Undo stack
void pushUndo(char action, RecordData data) {
    StackNode* newNode = new StackNode;
    newNode->action = action;
    newNode->data = data;
    newNode->next = undoTop;
    undoTop = newNode;
}

// Remove a record from the list
void removeRecord(Node* target) {
    if (target == nullptr)
        return;

    if (target->prev != nullptr)
        target->prev->next = target->next;
    else
        head = target->next;

    if (target->next != nullptr)
        target->next->prev = target->prev;
    else
        tail = target->prev;

    delete target;
}

// Display one record
void displayOne(RecordData data) {
    cout << left << setw(12) << data.month
         << setw(8) << data.year
         << setw(15) << data.previousReading
         << setw(15) << data.currentReading
         << setw(12) << data.units
         << "Rs. " << data.bill << '\n';
}

// First-time meter registration
void firstTimeMeterRegistration() {
    string month;
    int year;
    double reading;

    cout << "\n--- First-Time Meter Registration ---\n";
    cout << "Enter starting month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    if (findRecord(month, year) != nullptr) {
        cout << "A record for this month already exists.\n";
        return;
    }

    cout << "Enter current meter reading: ";
    cin >> reading;

    if (cin.fail() || reading < 0) {
        cout << "Invalid reading.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    RecordData data;
    data.month = month;
    data.year = year;
    data.previousReading = reading;
    data.currentReading = reading;
    data.units = 0;
    data.bill = 0;

    // Save starting baseline; do not create a billing record.
    // Baseline is stored separately below.
    // The first actual bill will use this reading.
    extern double baselineReading;
    extern bool baselineSet;

    baselineReading = reading;
    baselineSet = true;

    cout << "Meter registered successfully!\n";
    cout << "Starting reading: " << reading << '\n';
    cout << "No bill generated for initial registration.\n";
}

// Starting meter baseline
double baselineReading = 0;
bool baselineSet = false;

// Add monthly bill
void addMonthlyRecord() {
    string month;
    int year;
    double currentReading;

    cout << "\nEnter billing month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    if (findRecord(month, year) != nullptr) {
        cout << "A billing record already exists for this month.\n";
        return;
    }

    if (!baselineSet) {
        cout << "Please register the meter first (Option 1).\n";
        return;
    }

    cout << "Enter current meter reading: ";
    cin >> currentReading;

    if (cin.fail() || currentReading < baselineReading) {
        cout << "Invalid reading. It cannot be less than the last reading.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    RecordData data;
    data.month = month;
    data.year = year;
    data.previousReading = baselineReading;
    data.currentReading = currentReading;
    data.units = currentReading - baselineReading;
    data.bill = data.units * RATE;

    pushUndo('A', data);
    insertRecord(data);

    // Update baseline for the next billing period
    baselineReading = currentReading;

    cout << "\nBilling record added successfully!\n";
    cout << "Units consumed: " << data.units << '\n';
    cout << "Estimated bill: Rs. " << data.bill << '\n';
}

// Display all billing records
void displayAll() {
    if (head == nullptr) {
        cout << "\nNo billing records available.\n";
        return;
    }

    cout << "\n--- Electricity Billing History ---\n";
    cout << left << setw(12) << "Month"
         << setw(8) << "Year"
         << setw(15) << "Prev. Reading"
         << setw(15) << "Curr. Reading"
         << setw(12) << "Units"
         << "Estimated Bill\n";

    Node* temp = head;
    while (temp != nullptr) {
        displayOne(temp->data);
        temp = temp->next;
    }
}

// Search for a billing record
void searchRecord() {
    string month;
    int year;

    cout << "Enter month to search: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    Node* found = findRecord(month, year);

    if (found == nullptr) {
        cout << "Record not found.\n";
    } else {
        cout << "\nRecord found:\n";
        cout << left << setw(12) << "Month"
             << setw(8) << "Year"
             << setw(15) << "Prev. Reading"
             << setw(15) << "Curr. Reading"
             << setw(12) << "Units"
             << "Estimated Bill\n";
        displayOne(found->data);
    }
}

// Update a monthly record
void updateRecord() {
    string month;
    int year;
    double newReading;

    cout << "Enter month to update: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    Node* found = findRecord(month, year);

    if (found == nullptr) {
        cout << "Record not found.\n";
        return;
    }

    pushUndo('U', found->data);

    cout << "Enter corrected current reading: ";
    cin >> newReading;

    if (cin.fail() || newReading < found->data.previousReading) {
        cout << "Invalid reading. Update cancelled.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        delete undoTop;
        undoTop = nullptr; // Clear this failed undo entry
        return;
    }

    found->data.currentReading = newReading;
    found->data.units =
        newReading - found->data.previousReading;
    found->data.bill = found->data.units * RATE;

    cout << "Record updated successfully.\n";
}

// Delete a monthly record
void deleteRecord() {
    string month;
    int year;

    cout << "Enter month to delete: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    Node* found = findRecord(month, year);

    if (found == nullptr) {
        cout << "Record not found.\n";
        return;
    }

    pushUndo('D', found->data);
    removeRecord(found);

    cout << "Record deleted successfully.\n";
}

// Undo the latest add, delete or update
void undoOperation() {
    if (undoTop == nullptr) {
        cout << "Nothing to undo.\n";
        return;
    }

    StackNode* action = undoTop;
    undoTop = undoTop->next;

    Node* found = findRecord(
        action->data.month, action->data.year);

    if (action->action == 'A') {
        if (found != nullptr)
            removeRecord(found);
        cout << "Last addition undone.\n";
    } else if (action->action == 'D') {
        if (found == nullptr)
            insertRecord(action->data);
        cout << "Last deletion undone.\n";
    } else if (action->action == 'U') {
        if (found != nullptr)
            found->data = action->data;
        cout << "Last update undone.\n";
    }

    delete action;
}

// Navigate through records using DLL
void navigateRecords() {
    if (head == nullptr) {
        cout << "No records available.\n";
        return;
    }

    Node* current = head;
    char choice;

    while (current != nullptr) {
        cout << "\nCurrent record:\n";
        displayOne(current->data);

        cout << "N = Next, P = Previous, Q = Quit: ";
        cin >> choice;

        if (choice == 'N' || choice == 'n') {
            if (current->next != nullptr)
                current = current->next;
            else
                cout << "This is the last record.\n";
        } else if (choice == 'P' || choice == 'p') {
            if (current->prev != nullptr)
                current = current->prev;
            else
                cout << "This is the first record.\n";
        } else if (choice == 'Q' || choice == 'q') {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
}

// Calculate yearly total
void showTotals() {
    if (head == nullptr) {
        cout << "No billing records available.\n";
        return;
    }

    int year;
    double totalUnits = 0;
    double totalBill = 0;

    cout << "Enter year: ";
    cin >> year;

    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data.year == year) {
            totalUnits += temp->data.units;
            totalBill += temp->data.bill;
        }
        temp = temp->next;
    }

    cout << "\nYear: " << year << '\n';
    cout << "Total units consumed: " << totalUnits << '\n';
    cout << "Total estimated bill: Rs. " << totalBill << '\n';
}

// Free all dynamically allocated memory
void cleanup() {
    while (head != nullptr)
        removeRecord(head);

    while (undoTop != nullptr) {
        StackNode* temp = undoTop;
        undoTop = undoTop->next;
        delete temp;
    }
}

int main() {
    int choice;

    cout << fixed << setprecision(2);

    do {
        cout << "\n====== Electricity Usage and Billing History Manager ======\n";
        cout << "1. First-Time Meter Registration\n";
        cout << "2. Add Monthly Billing Record\n";
        cout << "3. Display All Records\n";
        cout << "4. Search Record\n";
        cout << "5. Update Record\n";
        cout << "6. Delete Record\n";
        cout << "7. Undo Last Operation\n";
        cout << "8. Navigate Previous/Next Record\n";
        cout << "9. Show Yearly Totals\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                firstTimeMeterRegistration();
                break;
            case 2:
                addMonthlyRecord();
                break;
            case 3:
                displayAll();
                break;
            case 4:
                searchRecord();
                break;
            case 5:
                updateRecord();
                break;
            case 6:
                deleteRecord();
                break;
            case 7:
                undoOperation();
                break;
            case 8:
                navigateRecords();
                break;
            case 9:
                showTotals();
                break;
            case 0:
                cleanup();
                cout << "Thank you for using the system!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}