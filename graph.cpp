#include "graph.h"

void RailwayNetwork::addStation(string name) {
    if (stationIndex.count(name))
        return;

    int index = stationIndex.size();
    stationIndex[name] = index;
    indexToStation.push_back(name);
    graph.push_back(vector<pair<int, int>>());
}

void RailwayNetwork::addTrack(string from, string to, int distance) {
    if (!stationIndex.count(from) || !stationIndex.count(to))
        return;

    int u = stationIndex[from];
    int v = stationIndex[to];

    graph[u].push_back({v, distance});
    graph[v].push_back({u, distance});
}

int RailwayNetwork::getStationCount() {
    return indexToStation.size();
}

// ✅ Dijkstra Algorithm
// Time Complexity: O((V + E) log V)
void RailwayNetwork::shortestPath(string source, string destination) {

    if (!stationIndex.count(source) || !stationIndex.count(destination)) {
        cout << "Invalid station name!\n";
        return;
    }

    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    int start = stationIndex[source];
    int end = stationIndex[destination];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (currentDist > dist[node])
            continue;

        for (auto neighbor : graph[node]) {
            int next = neighbor.first;
            int weight = neighbor.second;

            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                parent[next] = node;
                pq.push({dist[next], next});
            }
        }
    }

    if (dist[end] == INT_MAX) {
        cout << "No route available!\n";
        return;
    }

    // ✅ Travel Time Calculation (50 km/h)
    double speed = 50.0;
    double totalHours = dist[end] / speed;

    int hours = (int)totalHours;
    int minutes = (totalHours - hours) * 60;

    // ✅ Class Selection
    int classChoice;
    double costPerKm;

    cout << "\nSelect Travel Class:\n";
    cout << "1. First Class (LKR 8 per km)\n";
    cout << "2. Second Class (LKR 5 per km)\n";
    cout << "3. Third Class (LKR 3 per km)\n";
    cout << "Enter choice: ";
    cin >> classChoice;

    if (classChoice == 1)
        costPerKm = 8;
    else if (classChoice == 2)
        costPerKm = 5;
    else
        costPerKm = 3;

    double totalCost = dist[end] * costPerKm;

    cout << "\n========== ROUTE DETAILS ==========\n";
    cout << "Distance           : " << dist[end] << " km\n";
    cout << "Estimated Time     : " << hours << " hours "
         << minutes << " minutes\n";
    cout << "Total Ticket Cost  : LKR " << fixed << setprecision(2)
         << totalCost << endl;

    vector<int> path;
    for (int v = end; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Route              : ";
    for (int i = 0; i < path.size(); i++) {
        cout << indexToStation[path[i]];
        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << endl;
}

void RailwayNetwork::displayStations() {
    cout << "\nTotal Stations: " << getStationCount() << endl;
    cout << "----------------------------------\n";
    for (auto station : indexToStation)
        cout << "- " << station << endl;
}

// ✅ Sri Lanka Railway Data
void preloadData(RailwayNetwork &network) {

    string stations[] = {
        "ColomboFort","Maradana","Ragama","Gampaha","Veyangoda",
        "Polgahawela","Peradeniya","Kandy","Nawalapitiya","Hatton",
        "NanuOya","Badulla","Panadura","KalutaraSouth","Aluthgama",
        "Bentota","Hikkaduwa","Galle","Matara",
        "Kurunegala","Anuradhapura","Vavuniya","Jaffna"
    };

    for (string s : stations)
        network.addStation(s);

    network.addTrack("ColomboFort","Maradana",2);
    network.addTrack("Maradana","Ragama",14);
    network.addTrack("Ragama","Gampaha",10);
    network.addTrack("Gampaha","Veyangoda",15);
    network.addTrack("Veyangoda","Polgahawela",20);
    network.addTrack("Polgahawela","Peradeniya",60);
    network.addTrack("Peradeniya","Kandy",5);
    network.addTrack("Kandy","Nawalapitiya",35);
    network.addTrack("Nawalapitiya","Hatton",30);
    network.addTrack("Hatton","NanuOya",32);
    network.addTrack("NanuOya","Badulla",65);

    network.addTrack("ColomboFort","Panadura",27);
    network.addTrack("Panadura","KalutaraSouth",13);
    network.addTrack("KalutaraSouth","Aluthgama",24);
    network.addTrack("Aluthgama","Bentota",7);
    network.addTrack("Bentota","Hikkaduwa",35);
    network.addTrack("Hikkaduwa","Galle",20);
    network.addTrack("Galle","Matara",45);

    network.addTrack("Polgahawela","Kurunegala",42);
    network.addTrack("Kurunegala","Anuradhapura",100);
    network.addTrack("Anuradhapura","Vavuniya",60);
    network.addTrack("Vavuniya","Jaffna",110);
}