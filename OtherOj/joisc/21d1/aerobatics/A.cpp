#include<bits/stdc++.h>
#include "aerobatics.h"
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct point {
    int x,y;
};
vector<point> arr;

double calc(vector<int> &p) {
    double Minn = 500;
    for(int i=0; i<p.size()-2; i++) {
        Minn = min(Minn,GetAngle(arr[p[i+1]].x,arr[p[i+1]].y,arr[p[i]].x,arr[p[i]].y,arr[p[i+2]].x,arr[p[i+2]].y));
    }
    return Minn;
}
double getA(int a,int b,int c) {
    return GetAngle(arr[b].x,arr[b].y,arr[a].x,arr[a].y,arr[c].x,arr[c].y);
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int z0;
    cin>>z0;
    arr.resize(n+1);
    for(int i=1; i<=n; i++) {
        cin>>arr[i].x>>arr[i].y;
    }
    vector<bool> in(n,0);
    srand(time(0));
    //int cur = (rand()%n)+1;
	vector<int> realp;
   	double Minn = 0;
    for(int i = 1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) continue;;
            for(int g=1; g<=n; g++) in[g]=0;
            in[i]=1;
            in[j]=1;
            vector<int> p;
            p.push_back(i);
            p.push_back(j);
            for(int ii=2; ii<n; ii++) {
                double minn = 0;
                int k = 0;
                for(int h=1; h<=n; h++) {
                    if(in[h]) continue;
                    if(getA(p[ii-2],p[ii-1],h)>minn) {
                        k = h;
                        minn = getA(p[ii-2],p[ii-1],h);
                    }
                }
                in[k]=1;
                p.push_back(k);
            }
			double ff = calc(p);
			if(ff>Minn){
				realp = p;
				Minn = ff;
			}
        }
    }
    double maxnn = calc(realp);
	int cnt = 0;
	while(cnt<1e4){
        int l = rand()%n;
        int r = rand()%n;
        swap(realp[l],realp[r]);
        if(calc(realp)>maxnn) {
            maxnn = calc(realp);
			cnt=0;
        } else {
            swap(realp[l],realp[r]);
			cnt++;
        }
	}
    cout<<calc(realp)<<"\n";
    for(auto i : realp) cout<<i<<"\n";
    return 0;
}
