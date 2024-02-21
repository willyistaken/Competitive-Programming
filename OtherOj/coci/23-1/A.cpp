#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int arr[9][9];
bitset<10>  exist;
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int c = 0;
    for(int i=0; i<13; i++)	{
        string s;
        cin>>s;
        if(i%4==0) continue;
        int t = 0;
        for(int j=0; j<13; j++) {
            if(j%4==0) continue;
            if(s[j]=='.') arr[c][t]=0;
            else arr[c][t] = (s[j]-'0');
            t++;
        }
        c++;
    }
    for(int i=0; i<9; i++) {
        exist.reset();
        for(int j=0; j<9; j++) {
            if(exist[arr[i][j]] && arr[i][j]) {
                cout<<"GRESKA\n";
                return 0;
            }
            exist[arr[i][j]]=1;
        }
    }
    for(int j=0; j<9; j++) {
        exist.reset();
        for(int i=0; i<9; i++) {
            if(exist[arr[i][j]] && arr[i][j]) {
                cout<<"GRESKA\n";
                return 0;
            }
            exist[arr[i][j]]=1;
        }
    }
	int dx[9]={0,1,2,0,1,2,0,1,2};
	int dy[9]={0,0,0,1,1,1,2,2,2};
	for(int i=0;i<9;i+=3){
		for(int j=0;j<9;j+=3){
			exist.reset();
			for(int k=0;k<9;k++)	{
				if(exist[arr[i+dx[k]][j+dy[k]]] && arr[i+dx[k]][j+dy[k]]){
                	cout<<"GRESKA\n";
                	return 0;
				}
           		exist[arr[i+dx[k]][j+dy[k]]]=1;
			}
		}
	}
	cout<<"OK\n";
    return 0;
}
