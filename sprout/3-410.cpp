#include <bits/stdc++.h>
using namespace std;

int already[1505];
int ng;
void initialize(int n){
    ng=n;
    for(int i=0;i<n;i++)
        already[i]=0;
}
int hasEdge(int a, int b){
    if(already[a]==ng-1 || already[b]==ng-1){
        already[a]+=1; already[b]+=1;
        return 1;
    }
    already[a]+=1; already[b]+=1;
    return 0;
}