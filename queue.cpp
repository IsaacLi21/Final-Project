#include <iostream>
#include <string>
#include "queue.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>

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

void Queue::printQueue(){
        if (queueHead == -1) {
        cout << "Queue empty D:" << endl;
        return;
    }
    
    cout << "\nPrinting (circular) queue: " << endl;
    if (queueTail >= queueHead) {
        for (int i = queueHead; i <= queueTail; i++) {
            cout << "q[" << i << "]: " << fQueue[i].depart << " to " << fQueue[i].arrive<<" at ";
            cout<<fQueue[i].time<<endl;
        }
    } else {
        for (int i = queueHead; i < queueSize; i++) {
            cout << "q[" << i << "]: " << fQueue[i].depart << " to " << fQueue[i].arrive<< " at ";
            cout<<fQueue[i].time<<endl;
        }
        for (int i = 0; i <= queueTail; i++) {
            cout << "q[" << i << "]: " << fQueue[i].depart << " to " << fQueue[i].arrive<< " at ";
            cout<<fQueue[i].time<<endl;
        }
    }
    cout << endl;
} 

int Queue::getTail(){
    return queueTail;
}

flightQ *Queue::getfQueue(){
    return fQueue;
}

bool Queue::queueIsFull(){ //check when full
    return queueCount == queueSize;
}
bool Queue::queueIsEmpty(){ //check when empty
    return queueCount == 0;
}

void Queue::deleteFlight(string s, string e){
    bool found=false;
    if (queueHead==-1){
        cout<< "Queue is empty"<<endl;
    }
    else if(queueHead==queueTail){
        queueHead=queueTail=-1;
    }

    for (int i=queueHead; i<queueTail; i++){
        if (fQueue[i].depart.substr(fQueue[i].depart.length()-4, 3)==s){
            if (fQueue[i].arrive.substr(fQueue[i].arrive.length()-4, 3)==e){
                cout<<"Removed flight from queue from "<< fQueue[i].depart<< " to "<< fQueue[i].arrive<< " at ";
                cout<< fQueue[i].time<< endl;
                found=true;

                for (int j=i; j<queueTail; j++){
                    fQueue[j]=fQueue[j+1];
                }
                queueTail--;
            }
        }
    }
    if (found==true){
        queueCount--;
    }
    else cout<< s<< " to "<< e<< " was not found in the queue"<< endl;
}

int Queue::generateRandNum(){
    time_t t;
    srand((unsigned) time(&t));
    int a=queueHead+rand() % queueTail;
    return a;
}

bool Queue::searchVector(vector<string> a, string b){
    for (int i=0; i<a.size(); i++){
        if (a[i]==b){
            return true;
        }
    }
    return false;
}

void Queue::infectAndTrace(int start){
    vector <string> infectedAirports;
    infectedAirports.push_back(fQueue[start].depart);
    
    for (int i=start+1; i<queueTail; i++){
        for (int j=0; j<infectedAirports.size(); j++){
            if (fQueue[i].depart==infectedAirports[j]){

                if (!searchVector(infectedAirports, fQueue[i].arrive)){
                    infectedAirports.push_back(fQueue[i].arrive);
                }
            }
        }
    }
    for (int i=0; i<infectedAirports.size(); i++){
        cout<< infectedAirports[i]<<" was infected"<<endl;
    }
}