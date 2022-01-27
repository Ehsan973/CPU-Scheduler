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

int main() {
    vector<Dvec> processes;

    getAlg();

    return 0;
}
