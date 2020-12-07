#ifndef QUEUE_H
#define QUEUE_H
#include<vector>
#include <iostream>
#include <vector>

using namespace std;

struct flightQ{
    string depart;
    string arrive;
    string time;
    bool infected;

    flightQ(){};
    flightQ(string d, string a, string t){
        depart=d;
        arrive=a;
        time=t;
    }

};


class Queue{
public:
    Queue(){};
    Queue(int max){
            queueHead = queueTail = -1;
            queueSize = max;
            queueCount = 0;
            fQueue = new flightQ[max];
    };
    //circular queue methods
    bool enqueue(flightQ f);
    flightQ dequeue();
    void printQueue();
    bool queueIsFull(); //check when full
    bool queueIsEmpty(); //check when empty
    int getTail();
    flightQ *getfQueue();
    void deleteFlight(string s, string e);
    int generateRandNum();
    void infectAndTrace(int i);
    bool searchVector(vector<string> a, string b);
    
protected:
private:
    int queueSize;
    int queueHead=-1;
    int queueTail;
    int queueCount;
    flightQ *fQueue;

};




#endif