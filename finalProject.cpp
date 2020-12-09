#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "queue.h"

using namespace std;

int main (int argc, const char * argv[]){
    Graph g;
    Queue q(310);

    string filename=argv[1];
    ifstream myFile(filename);

    if(myFile.fail()) {
        cout<<"error opening file"<<endl;
        abort();
    }

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
                getline(linestream, dist, ',');
                getline(linestream, deparT);
                
                //addVertex will not add if already in airports vector
                g.addVertex(deparLoc);
                g.addVertex(arrLoc);

                g.addEdge(deparLoc, arrLoc, stoi(dist), deparT);

                q.enqueue(flightQ(deparLoc, arrLoc, deparT));
            }


    //change what the menu does
    string dmenu =  "======Main Menu======\n"
                    "1. Print airports and departures (print the graph)\n"
                    "2. Print the Queue\n"
                    "3. Add flight to queue and graph\n"
                    "4. Cancel a flight\n"
                    "5. Infect a random flight and display infected airports\n"
                    "6. Search for scheduled flights\n"
                    "7. Have a flight take off\n"
                    "8. Calculate the shortest distance to all airports from airport of you choosing\n"
                    "9. See if an Airport is one that Southwest visits\n"
                    "10. Print list of Airport codes\n"
                    "11. Quit\n";
    
    int choice = 0;
    bool done = false;
    
    do {
        cout << dmenu;
        cin >> choice;
        
        cin.clear();
        cin.ignore();
        
        switch (choice) {
            case 1:
            {
                //Print airports and departures
                g.displayEdges();
                break;
            }
            case 2:
            {
                //Print the Queue
                q.printQueue();
                break;
            } 
            case 3:
            {
                //Add flight to queue and graph
                string start, end, dist, T;
                cout<<"Enter departure location (enter the 3 character IATA airport code, Use all caps)"<<endl;
                cin>>start;
                cout<<"Enter arrival location (enter the 3 character IATA airport code, Use all caps)"<<endl;
                cin>>end;
                cout<<"Enter a time (military notation) after "<< q.getfQueue()[q.getTail()].time<<endl;
                cin>>T;

                int distance=g.foundFlightDistance(start, end);
                if (distance!=-1){
                    dist=to_string(distance);
                }
                else{
                    cout<<"Distance not found in database: Enter the distance between the two airports."<<endl;
                    cin>>dist;
                }

                q.enqueue(flightQ(start, end, T));
                if (!q.queueIsFull()){
                    cout<<"Successfully added to queue "<< start<<" to "<< end<< " at "<< T<<endl;
                }
                
                if (!g.airportIsVisited(start)){
                    g.addVertex(start);
                }
                if (!g.airportIsVisited(end)){
                    g.addVertex(end);
                }
                
                g.addEdge(start, end, stoi (dist), T);
                cout<<"Successfully added to graph "<< start<<" to "<< end<< " at "<< T<<". Distance: "<<dist<<" miles."<<endl;
                break;
            }
            case 4:
            {
                //Cancel a flight
                string start, end;
                cout<<"Enter departure location (enter the 3 character IATA airport code, Use all caps)"<<endl;
                cin>>start;
                cout<<"Enter arrival location (enter the 3 character IATA airport code, Use all caps)"<<endl;
                cin>>end;
                
                //deletes flight in the graph
                bool found=false;
                airport *a=g.airportIsVisited(start);
                for (int i=0; i<a->departures.size(); i++){
                    if (a->departures[i].a->name.substr(a->departures[i].a->name.length()-4, 3)==end){
                        g.deleteFlight(a, i);
                        found=true;
                    }
                }
                if (!found){
                    cout<<"No flight from "<< start<< " to " << end<< " found in the graph."<<endl;
                }

                //deletes flight in the queue
                q.deleteFlight(start, end);
                break;
            }
            case 5:
            {
                //Infect a random flight and display infected airports
                int a=q.generateRandNum();
                q.infectAndTrace(a);


                break;
            }
            case 6:
            {
                string start, end;
                cout<<"Enter departure location (enter the 3 character IATA airport code, Use all caps)"<<endl;
                cin>>start;
                cout<<"Enter arrival location (enter the 3 character IATA airport code, Use all caps)"<<endl;
                cin>>end;
                
                bool found=false;
                airport *a=g.airportIsVisited(start);
                for (int i=0; i<a->departures.size(); i++){
                    if (end==a->departures[i].a->name.substr(a->departures[i].a->name.length()-4, 3)){
                        cout<<"Flight from "<< start <<" to " << end<< " is at " ;
                        cout<<a->departures[i].time<<endl;
                        found=true;
                    }
                }
                if (!found){
                    cout<<"There is no flight from "<< start<< " to " <<end<< endl;
                }

                break;
            }
            case 7:
            {
                flightQ a=q.dequeue();
                cout<<"Flight took off from " <<a.depart<< " to "<< a.arrive << " at ";
                cout<<a.time <<endl;
                break;
            }
            case 8:
            {
                string start;
                cout<<"Enter departure location (enter the 3 character IATA airport code, Use all caps)"<<endl;
                cin>>start;
                // cout<<"Enter arrival location (enter the 3 character IATA airport code, Use all caps)"<<endl;
                // cin>>end;

                if (!g.airportIsVisited(start))// || !g.airportIsVisited(end))
                {
                    cout<<"One or more of the airports is not serviced"<<endl;
                    break;
                }

                g.findShortestDistance(start);

                break;
            }
            case 9:
            {
                string s;
                cout<<"Enter either the name of the city or the IATA airport code(3 letter unique airport code, Use all caps)"<<endl;
                cin>>s;
                if (g.airportIsVisited(s)){
                    cout<<s<< " was visited"<<endl;
                }
                else cout<<s<< " was not visited"<<endl;
                break;
            }
            case 10:
            {
                g.printAirportCodes();
                break;
            }
            case 11:
            default:
            {
                done = true;
                break;
            }
        }
        
    } while(!done);
    
    cout << "Thanks for flying with us!" << endl;
    return 0;
}