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
int main() {
    vector<Dvec> processes;

    getAlg();
    getInput(processes);



    return 0;
}
