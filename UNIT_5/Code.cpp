#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of airports: ";
    cin >> n;

    string airports[20];
    int adj[20][20] = {0};

    // Enter airport names
    for (int i = 0; i < n; i++)
    {
        cout << "Enter airport " << i + 1 << " name: ";
        cin >> airports[i];
    }

    // Enter direct flight connections
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                cout << "Is there a direct flight from "
                     << airports[i] << " to "
                     << airports[j] << "? (1 = Yes, 0 = No): ";
                cin >> adj[i][j];
            }
        }
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix:\n    ";

    for (int i = 0; i < n; i++)
        cout << airports[i] << " ";

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << airports[i] << "  ";

        for (int j = 0; j < n; j++)
            cout << adj[i][j] << "   ";

        cout << endl;
    }

    // Display direct flights
    cout << "\nAvailable Direct Flights:\n";

    for (int i = 0; i < n; i++)
    {
        cout << airports[i] << " -> ";
        bool found = false;

        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
            {
                cout << airports[j] << " ";
                found = true;
            }
        }

        if (!found)
            cout << "No direct flights available";

        cout << endl;
    }

    return 0;
}
