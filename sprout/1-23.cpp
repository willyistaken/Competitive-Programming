#include <bits/stdc++.h>
using namespace std;
int hello=0;
void solve(int N,int order[]){
    int loc[N+1]={0};
    stack<int> ogplace;
    for(int i=N;i>=1;i--){
        ogplace.push(i);
    }
    stack<int> fstation;
    stack<int> sstation;
    for(int i=0;i<N;i++){
        if(loc[order[i]]==0){
            while(ogplace.top()!=order[i]){
                loc[ogplace.top()]=1;
                int temp=ogplace.top();
                fstation.push(temp);
                ogplace.pop();
                push_train();
            }
            ogplace.pop();
            loc[order[i]]=3;
            push_train();
            move_station_1_to_2();
            pop_train();
        }else if(loc[order[i]]==1){
            while(fstation.top()!=order[i]){
                loc[fstation.top()]=2;
                int temp=fstation.top();
                sstation.push(temp);
                fstation.pop();
                move_station_1_to_2();
            }
            fstation.pop();
            loc[order[i]]=3;
            move_station_1_to_2();
            pop_train();
        }else if(loc[order[i]]==2){
            while(sstation.top()!=order[i]){
                loc[sstation.top()]=1;
                int temp=sstation.top();
                fstation.push(temp);
                sstation.pop();
                move_station_2_to_1();
            }
            sstation.pop();
            loc[order[i]]=3;
            pop_train();
        }
    }

}

