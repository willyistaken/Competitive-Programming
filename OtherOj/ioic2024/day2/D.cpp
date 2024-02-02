#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    int cnt[3]= {0};
    vector<bool> pn(s.size());
    int k = 0;
    for(int i=0; i<s.size(); i++) {
        cnt[(s[i]-'0')%3]++;
        k+=(s[i]-'0')%3;
        pn[i]=1;
        k%=3;
    }
    if(k==1) {
        if(cnt[2]) {
            for(int i=0; i<s.size(); i++) {
                if((s[i]-'0')%3==2) {
                    pn[i]=0;
                    break;
                }
            }
        } else {
            if(cnt[1]>=2) {
                int cc = 0;
                for(int i=0; i<s.size(); i++) {
                    if((s[i]-'0')%3==1) {
                        pn[i]=0;
                        cc++;
                        if(cc==2) break;
                    }
                }
            } else {
                cout<<"NO\n";
                return 0;
            }
        }

    } else if(k==2) {
        if(cnt[1]) {
            for(int i=0; i<s.size(); i++) {
                if((s[i]-'0')%3==1) {
                    pn[i]=0;
                    break;
                }
            }
        } else {
            if(cnt[2]>=2) {
                int cc = 0;
                for(int i=0; i<s.size(); i++) {
                    if((s[i]-'0')%3==2) {
                        pn[i]=0;
                        cc++;
                        if(cc==2) break;
                    }
                }
            } else {
                cout<<"NO\n";
                return 0;
            }

        }
    
} else {

}
for(int i=0; i<s.size(); i++) {
    if(pn[i]==1 && i!=0) {
        cout<<"+";
    } else if(pn[i]==0) {
        cout<<"-";
    }
    cout<<s[i];
}
cout<<"\n"	;

return 0;
}
