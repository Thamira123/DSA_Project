#include "graph.h"

int main() {
    RailwayNetwork network;
    int choice;

    while (true) {
        cout << "\n====== Railway Network Optimization ======\n";
        cout << "1. Add Station\n";
        cout << "2. Add Track\n";
        cout << "3. Find Shortest Path\n";
        cout << "4. Display Stations\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter station name: ";
            cin >> name;
            network.addStation(name);
        }
        else if (choice == 2) {
            string from, to;
            int distance;
            cout << "Enter source station: ";
            cin >> from;
            cout << "Enter destination station: ";
            cin >> to;
            cout << "Enter distance (km): ";
            cin >> distance;
            network.addTrack(from, to, distance);
        }
        else if (choice == 3) {
            string source, destination;
            cout << "Enter source station: ";
            cin >> source;
            cout << "Enter destination station: ";
            cin >> destination;
            network.shortestPath(source, destination);
        }
        else if (choice == 4) {
            network.displayStations();
        }
        else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}