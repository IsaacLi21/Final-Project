#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

void Graph::addEdge(string v1, string v2, int dist, string t){
    for(int i = 0; i < airports.size(); i++){
        if(airports[i]->name == v1){
            for(int j = 0; j < airports.size(); j++){
                if(airports[j]->name == v2 && i != j){
                    flight av;
                    av.a = airports[j];
                    av.distance = dist;
                    av.time=t;
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


void Graph::displayEdges(){
    for(int i = 0; i < airports.size(); i++){
        cout<<airports[i]->name<<"-->";
        for(int j = 0; j < airports[i]->departures.size(); j++){
            cout<<airports[i]->departures[j].a->name<<"-";
            cout<<airports[i]->departures[j].distance<< " miles";
            if (j != airports[i]->departures.size()-1){
                cout<<"***";
            }
        }
        cout<<endl;
    }
}

airport* Graph::getMinNode(){
    int min = INT32_MAX;
    airport *result=NULL;

    for (int i = 0; i < airports.size(); i++){
        if(!airports[i]->visited){
            if(airports[i]->weight < min){
                min = airports[i]->weight;
                result = airports[i];
            }
        }
    }
    return result;
} 

bool Graph::allVisitedCheck(){
    for (int i = 0; i < airports.size(); i ++){
        if (!airports[i]->visited){
            return false;
        }
    }
    return true;
}

void Graph::findShortestDistance(string src) { 
    airport *source = airportIsVisited(src); 
    source->weight = 0; 
    int count=0;
    while (!allVisitedCheck()){
        airport *minNode = getMinNode();
        minNode->visited = true;

        for(int i = 0; i< minNode->departures.size(); i++){
            if(minNode->departures[i].a->weight > minNode->weight + minNode->departures[i].distance){
                minNode->departures[i].a->weight = minNode->weight + minNode->departures[i].distance;
                minNode->departures[i].a->parent = minNode;
            }
        }

    }

    for (int i = 0; i <airports.size(); i++){
        if (airports[i]->weight==32767){
            cout<< airports[i]->name<<" could not be reached"<<endl;
        }
        else cout << airports[i]->name << " reached with cost " << airports[i]->weight << endl;
    }

    for (int i = 0; i< airports.size(); i++){
        airports[i]->visited = false;
        airports[i]->weight = INT32_MAX;
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

airport* Graph::airportIsVisited(std::string name){
    for (int i = 0; i < airports.size(); i++) {
        if (airports[i]->name.substr(airports[i]->name.length()-4, 3) == name) {
            return airports[i];
        }
    }
    return NULL;
}

int Graph::foundFlightDistance(string start, string end){
    for (int i=0; i<airports.size(); i++){
        if (airports[i]->name.substr(airports[i]->name.length()-4, 3)== start){
            for (int j=0; i<airports[i]->departures.size(); j++){
                if (airports[i]->departures[j].a->name.substr(airports[i]->departures[j].a->name.length()-4, 3)==end){
                    return airports[i]->departures[j].distance;
                }
            }
        }
    }
    return -1;
}

void Graph::printAirportCodes(){
    for (int i=0;i<airports.size(); i++){
        cout<<airports[i]->name<<endl;
    }
}

void Graph::deleteFlight(airport *a, int index){
    cout<<"Removed flight from graph from "<< a->name<< " to "<< a->departures[index].a->name<< " at ";
    cout<<a->departures[index].time<<endl;
    a->departures.erase(a->departures.begin()+index);
}