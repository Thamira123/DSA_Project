#include "graph.h"

// Add new station
void RailwayNetwork::addStation(string name) {
    if (stationIndex.count(name)) {
        cout << "Station already exists!\n";
        return;
    }

    int index = stationIndex.size();
    stationIndex[name] = index;
    indexToStation.push_back(name);
    graph.push_back(vector<pair<int, int>>());

    cout << "Station added successfully!\n";
}

// Add track between stations
void RailwayNetwork::addTrack(string from, string to, int distance) {
    if (!stationIndex.count(from) || !stationIndex.count(to)) {
        cout << "One or both stations do not exist!\n";
        return;
    }

    int u = stationIndex[from];
    int v = stationIndex[to];

    graph[u].push_back({v, distance});
    graph[v].push_back({u, distance});

    cout << "Track added successfully!\n";
}

// Dijkstra shortest path
void RailwayNetwork::shortestPath(string source, string destination) {
    if (!stationIndex.count(source) || !stationIndex.count(destination)) {
        cout << "One or both stations do not exist!\n";
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
        int node = pq.top().second;
        pq.pop();

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
        cout << "No route found!\n";
        return;
    }

    cout << "\nShortest Distance: " << dist[end] << " km\n";

    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    cout << "Route: ";
    for (int i = 0; i < path.size(); i++) {
        cout << indexToStation[path[i]];
        if (i != path.size() - 1)
            cout << " -> ";
    }
    cout << endl;
}

// Display stations
void RailwayNetwork::displayStations() {
    cout << "\nAvailable Stations:\n";
    for (auto station : indexToStation) {
        cout << "- " << station << endl;
    }
}