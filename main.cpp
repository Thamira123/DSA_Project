#include "graph.h"

int main() {

    RailwayNetwork network;
    preloadData(network);

    int choice;

    while (true) {

        cout << "\n========================================\n";
        cout << "   SRI LANKA RAILWAY OPTIMIZATION\n";
        cout << "========================================\n";
        cout << "1. Display All Stations\n";
        cout << "2. Find Shortest Route\n";
        cout << "3. Exit\n";
        cout << "----------------------------------------\n";
        cout << "Enter your choice: ";
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