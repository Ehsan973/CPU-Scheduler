#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include "head.h"
using namespace std;

Algorithm alg;

void getAlg(){
    string temp;
    cout<<"Enter Algorithm. options are :\n1):RR\n2):FCFS\n3):SJF"<<endl;
    scanf("%u",&alg);
}

void getInput(vector<Dvec> &ps){
    cout<<"Enter List of Tasks. format: processBurstTime-processID\ntype \"end-end\" to end entering"<<endl;
    bool even=false;
    string temp;
    Dvec temp_;

    while (true){

        if(even)
            getline(cin, temp);
        else
            getline(cin, temp,DLM);

        if(temp=="end")break;

        temp_.push_back(stod(temp));

        if(even){
            ps.push_back(Dvec(temp_)) ;
            temp_.clear();
        }
        even=!even;
    }
}
void RoundRobin(const char quantum, const vector<Dvec>& pses){
    queue<Dvec> q;
    for (const auto& e: pses)
        q.push(e);

    auto oneRound=[&](){
        Dvec process= q.front();
        process[0]-=quantum;
        q.pop();
        if(process[0]>0)
            q.push(process);

    };

    while (!q.empty()){
        cout<< "process with id="<<q.front()[1]<<" running "<<endl;
        oneRound();
    }

}
void sjf(const vector<Dvec>& pses){
    queue<Dvec> q;
    for (const auto& e: pses)
        q.push(e);

    auto oneCycle=[&](){
        Dvec &process= q.front();
        process[0]--;
        if(process[0]==0)
            q.pop();
    };

    while (!q.empty()){
        cout<< "process with id="<<q.front()[1]<<" running " <<endl;
        oneCycle();
    }
}
int main() {
    vector<Dvec> processes;

    getAlg();
    getInput(processes);

    if(alg==SJF){
        sort(processes.begin(),processes.end(),[](Dvec a, Dvec b){
            return(a[0]<b[0]);
        });
        sjf(processes);
    }

    if(alg==RR){
        sort(processes.begin(),processes.end(),[](Dvec a, Dvec b){
            return(a[1]<b[1]);
        });
        RoundRobin(1,processes);
    }

    return 0;
}
