#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct airport;

struct flight{
    string time;
    airport *a;
    int distance;
};

struct airport{
    airport *parent;
    string name;
    bool visited;
    bool infected;
    int weight;
    vector<flight> departures;

    airport(std::string toAdd){
        name=toAdd;
        visited=false;
        infected=false;
        weight=INT16_MAX;
    }
};

class Graph
{
    public:
        Graph(){};  
        ~Graph(){}; 
        void addEdge(std::string v1, std::string v2, int weight, string t);
        void addVertex(std::string name);
        void displayEdges();
        airport *findAirport(string name);  
        void findShortestDistance(string src);
        airport* getMinNode();
        bool allVisitedCheck();
        airport* airportIsVisited(string name);
        int foundFlightDistance(string start, string end);
        void printAirportCodes();
        void deleteFlight(airport *a, int i);

    protected:
    private:
        std::vector<airport*> airports;
        
};

#endif // GRAPH_H
