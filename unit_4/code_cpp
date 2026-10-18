#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int size, wasted = 0;

    cout << "Enter array size: ";
    cin >> size;
    cin.ignore();

    if (size <= 0) {
        cout << "Invalid array size!";
        return 0;
    }

    vector<string> tree(size);

    cout << "\nEnter family members (- for missing):\n";

    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": ";
        getline(cin, tree[i]);

        if (tree[i] == "-")
            tree[i] = "";
    }

    cout << "\n--- FAMILY TREE ---\n";

    for (int i = 0; i < size; i++) {
        cout << "\nIndex " << i << ": ";

        if (tree[i] == "") {
            cout << "Empty";
            wasted++;
            continue;
        }

        cout << tree[i];

        if (i == 0) {
            cout << " | Root (No Parent)";
        } else {
            int parent = (i - 1) / 2;

            if (tree[parent] != "")
                cout << " | Parent: " << tree[parent];
            else
                cout << " | Parent: Missing";
        }

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size)
            cout << " | Left Child: "
                 << (tree[left] == "" ? "Missing" : tree[left]);

        if (right < size)
            cout << " | Right Child: "
                 << (tree[right] == "" ? "Missing" : tree[right]);
    }

    cout << "\n\nTotal Array Slots: " << size;
    cout << "\nOccupied Slots: " << size - wasted;
    cout << "\nWasted Slots: " << wasted << endl;

    return 0;
}
