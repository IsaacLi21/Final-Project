#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include <iostream>
#include <vector>

using namespace std;

struct airport;

struct flight{
    airport *a;
    int distance;
};

struct airport{
    string name;
    bool visited;
    bool infected;
    vector<flight> departures;

    airport(std::string toAdd){
        name=toAdd;
        visited=false;
    }
};

class Graph
{
    public:
        Graph(){};  
        ~Graph(){}; 
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
        airport *findAirport(string name);  
              
        
        
    protected:
    private:
        std::vector<airport*> airports;


        
};

#endif // GRAPH_H
