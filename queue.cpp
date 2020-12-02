#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

bool Queue::enqueue(flightQ cp){
    // queqe full
    if ((queueHead==0 && queueTail==queueSize-1)|| (queueTail==(queueHead-1)%(queueSize-1)))
    {
        cout<< "Queue is full"<< endl;
        return true;
    }
    //first element
    else if (queueHead==-1){
        queueHead=0;
        queueTail=0;
        fQueue[queueTail]=cp;
        queueCount=1;
        return true;
    }
    //wrapping around
    else if(queueTail==queueSize-1 && queueHead!=0){
        queueTail=0;
        fQueue[queueTail]=cp;
        queueCount++;
        return true;
    }
    //normal case
    else{
        queueTail++;
        fQueue[queueTail]=cp;
        queueCount++;
        return true;
    }
    return false;
}


flightQ Queue::dequeue(){
    //assigns what is returned
    flightQ toRet=fQueue[queueHead];
    //if the head==-1 then queue is empty
    if (queueHead==-1){
        cout<< "Queue is empty"<<endl;
    }
    //if queue gets emptied, queue is reset to empty
    else if(queueHead==queueTail){
        queueHead=queueTail=-1;
    }
    //if head is at the end, it goes back to the beginning
    else if (queueHead==queueSize-1){
        queueHead=0;
    }
    else{
        queueHead++;
    }
    queueCount--;
    return toRet;
}




bool Queue::queueIsFull(){ //check when full
    return queueCount == queueSize;
}
bool Queue::queueIsEmpty(){ //check when empty
    return queueCount == 0;
}