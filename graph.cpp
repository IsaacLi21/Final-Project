#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

void Graph::addEdge(string v1, string v2, int dist){
    for(int i = 0; i < airports.size(); i++){
        if(airports[i]->name == v1){
            for(int j = 0; j < airports.size(); j++){
                if(airports[j]->name == v2 && i != j){
                    flight av;
                    av.a = airports[j];
                    av.distance = dist;
                    airports[i]->departures.push_back(av);
                }
            }
        }
    }
}

void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < airports.size(); i++){
        if(airports[i]->name == n){
            found = true;
            //cout<<airports[i]->name<<" found."<<endl;
        }
    }
    if(found == false){
        airport* v=new airport(n);
        airports.push_back(v);
    }
}



airport *Graph::findAirport(std::string name){
    //loop through vertices and return the vertex with the same name as name
    for (int i = 0; i < airports.size(); i++) {
        if (airports[i]->name == name) {
            return airports[i];
        }
    }
    return NULL;
}
