#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>
#include <iomanip>

using namespace std;

class RailwayNetwork {
private:
    map<string, int> stationIndex;
    vector<string> indexToStation;
    vector<vector<pair<int, int>>> graph;

public:
    void addStation(string name);
    void addTrack(string from, string to, int distance);
    void shortestPath(string source, string destination);
    void displayStations();
    int getStationCount();
};

void preloadData(RailwayNetwork &network);

#endif