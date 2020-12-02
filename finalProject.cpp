#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>

#include "graph.h"
#include "queue.h"

using namespace std;

int main (int argc, const char * argv[]){
    Graph g;
    Queue q(300);

    string filename=argv[1];
    ifstream myFile(filename);
    string lineFromFile;
    string line;
    getline(myFile, line);
            while(getline(myFile, lineFromFile)) 
            {
                stringstream linestream(lineFromFile); //create a stringstream from the line
                string deparLoc;
                string arrLoc;
                string dist;
                string deparT;
                getline(linestream, deparLoc, ','); 
                getline(linestream, arrLoc, ',');
                getline(linestream, dist);
                getline(linestream, deparT);
                
                //addVertex will not add if already in airports vector
                g.addVertex(deparLoc);
                g.addVertex(arrLoc);

                g.addEdge(deparLoc, arrLoc, stoi(dist));

                q.enqueue(flightQ(deparLoc, arrLoc, deparT));
                
            }
}