#include "graph.h"

int main() {

    RailwayNetwork network;
    preloadData(network);  // Auto load Sri Lanka railway data

    int choice;

    while (true) {
        cout << "\n====== Sri Lanka Railway Network Optimization ======\n";
        cout << "1. Display All Stations\n";
        cout << "2. Find Shortest Route\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            network.displayStations();
        }
        else if (choice == 2) {
            string source, destination;
            cout << "Enter source station: ";
            cin >> source;
            cout << "Enter destination station: ";
            cin >> destination;
            network.shortestPath(source, destination);
        }
        else if (choice == 3) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}