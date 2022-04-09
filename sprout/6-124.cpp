#include <bits/stdc++.h>
using namespace std;

bool inbound(short xtr,short ytr,short xbl,short ybl,short X,short Y){
    if(xtr<=X && xbl>=X){
        if(ytr<=Y && ybl>=Y){
            return true;
        }
    }
    return false;
}

short dx[4]={0,1,0,1};
short dy[4]={0,0,1,1};

pair<pair<short,short>,pair<short,short> > newxy(short xtr,short ytr,short xbl,short ybl,short type){
    if(type==0){
        pair<short,short> tr = make_pair(xtr,ytr);
        pair<short,short> bl = make_pair((xtr+xbl-1)/2,(ytr+ybl-1)/2);
        return make_pair(tr,bl);
    }
    if(type==1){
        pair<short,short> tr = make_pair(((xtr+xbl-1)/2)+1,ytr);
        pair<short,short> bl = make_pair(xbl,(ytr+ybl-1)/2);
        return make_pair(tr,bl);
    }
    if(type==2){
        pair<short,short> tr = make_pair(xtr,((ytr+ybl-1)/2)+1);
        pair<short,short> bl = make_pair((xtr+xbl-1)/2,ybl);
        return make_pair(tr,bl);
    }
    if(type==3){
        pair<short,short> tr = make_pair(((xtr+xbl-1)/2)+1,((ytr+ybl-1)/2)+1);
        pair<short,short> bl = make_pair(xbl,ybl);
        return make_pair(tr,bl);
    }
}

void split(short xtr,short ytr,short xbl,short ybl,short X,short Y){
    short splitx = (xtr+xbl-1)>>1;
    short splity = (ytr+ybl-1)>>1;
    vector<short> rex;
    vector<short> rey;
    for(short i=0;i<4;i++){
        auto newcor = newxy(xtr,ytr,xbl,ybl,i);
        if(!inbound(newcor.first.first,newcor.first.second,newcor.second.first,newcor.second.second,X,Y)){
            rex.push_back(splitx+dx[i]);
            rey.push_back(splity+dy[i]);
            split(newcor.first.first,newcor.first.second,newcor.second.first,newcor.second.second,splitx+dx[i],splity+dy[i]);
        }else{
            split(newcor.first.first,newcor.first.second,newcor.second.first,newcor.second.second,X,Y);
        }
    }
    Report(rex[0],rey[0],rex[1],rey[1],rex[2],rey[2]);
}
void solve(int N,int X,int Y){
    split(1,1,N,N,X,Y);
}