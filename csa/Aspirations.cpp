    #include <iostream>
    
    using namespace std;
    
    int main() {
        int l,r;cin>>l>>r;
        int d;cin>>d;
        int al = 0;
        while(al<l){
            al+=d;
        }
		if(al>r) {
			cout<<"impossible\n";
			return 0;
		}
        int k  = (r-al)/d;
        if(k==0 && al!=d){
            cout<<"impossible\n";
            return 0;
        }
        cout<<k+1<<"\n";
        for(int i=0;i<=k;i++){
            cout<<al<<" ";
            al+=d;
        }
        return 0;
    }
