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

    flightQ(){};
    flightQ(string d, string a, string t){
        depart=d;
        arrive=a;
        time=t;
    }

};


class Queue{
public:
    Queue(int max){
            queueHead = queueTail = -1;
            queueSize = max;
            queueCount = 0;
            fQueue = new flight[max];
    }
    //circular queue methods
    bool enqueue(flightQ f);
    flightQ dequeue();
    void printQueue(); //probably good for debug
    bool queueIsFull(); //check when full
    bool queueIsEmpty(); //check when empty
    
protected:
private:
    int queueSize;
    int queueHead=-1;
    int queueTail;
    int queueCount;
    flightQ *fQueue;




};




#endif