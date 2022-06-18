#include <iostream>
int a[8];
int L[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6} };
using namespace std;
bool line(int k){
    for(int i = 0; i<8; i++){
        bool all = 1;
        for(int j = 0; j<3; j++){
            if(a[L[i][j]] != k) all = 0;
        }
        if (all == 1) return 1;
    }
    return 0;
}
int main(){
    while(true){
    fill(a,a+8,0);
    string s;
    int O = 0;
    int X = 0;
    bool space=0;
    for(int i = 0; i < 3; i++){
        if(cin>>s){
        for(int j = 0; j < 3; j++){
            if(s[j] == 'O'){ 
                a[3*i+j] = 1;
                O++;
            }
            else if(s[j] == 'X'){
                a[3*i+j] = -1;
                X++;
            }
            else if(s[j] == '.'){
                 a[3*i+j] = 0;
                 space=1;
            }
        }
        }else{
            return 0;
        }
    }
    if((X == O && !line(-1)) || (X-O==1 && !line(1) )){
        if(line(1)){
            cout<<"O win\n";
        }else if(line(-1)){
            cout<<"X win\n";
        }else if(!space){
            cout<<"Tie\n";
        }else{
            cout<<"Not yet\n";
        }

    }else{
        cout<<"Cheating!\n";
    }
    }
    return 0;
}