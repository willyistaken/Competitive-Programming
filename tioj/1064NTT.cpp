#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<long double> cn;
int n;
const int unitsize = 1e9;
const int unitsizep = 9;
int savemeprecision;
struct bigint{
	int size;
	vector<ll> arr;
	void init(int _n){
		arr.resize(_n);
		size = _n;
		fill(arr.begin(),arr.end(),0);
	}
	void add(ll v,int i){
		arr[i]+=v;
		if(arr[i]>=unitsize){
			add((arr[i]/unitsize),i+1);
			arr[i]%=unitsize;
		}
	}
	void print(){
		bool start=0;
		for(int i=size-1;i>=1;i--){
			if(start){
				cout<<setw(unitsizep)<<setfill('0')<<arr[i];	
			}
			if(arr[i] && !start){
				cout<<arr[i];
				start=1;
			}
		}
		if(size!=2){
			if(start) cout<<setw(unitsizep-1)<<setfill('0')<<(arr[0]-arr[0]%10)/10;
			else cout<<(arr[0]-arr[0]%10)/10;
			cout<<savemeprecision;
		}else{
			if(arr[0]-arr[0]%10){
				cout<<(arr[0]-arr[0]%10)/10;
			}
			cout<<savemeprecision;
		}
		cout<<"\n";
	}
};
cn cexp(long double x){
	return {cos(x),sin(x)};
}


struct valuels{
	vector<cn> arr;
	int size;
	void init(int _n){
		arr.resize(_n);
		fill(arr.begin(),arr.end(),0);
		size = _n;
	}
	cn eval(cn v){
		cn r(0,0);
		for(int i=size-1;i>=0;i--){
			r*=v;
			r+=arr[i];
		}
		return r;
	}
};
valuels operator+(const valuels &a,const valuels &b){
	assert(a.size==b.size);
	valuels r;
	r.init(a.size);
	for(int i=0;i<a.size;i++){
		r.arr[i] = a.arr[i]+b.arr[i];
	}
	return r;
}
valuels operator*(const valuels &a,const valuels &b){
	assert(a.size==b.size);
	valuels r;
	r.init(a.size);
	for(int i=0;i<a.size;i++){
		r.arr[i] = a.arr[i]*b.arr[i];
	}
	return r;
}

struct vset{
	vector<cn> s;
	int size;
	void init(int _n){
		s.resize(_n);
		fill(s.begin(),s.end(),0);
		size = _n;
	}
	
};

vset collapse(vset a){
	vset r;
	r.init(a.size/2);
	for(int i=0;i < r.size;i++){
		r.s[i] = a.s[2*i];
	}
	return r;
}
struct coeffls{
	vector<cn> arr;
	int size;
	void init(int _n){
		arr.resize(_n);
		size=_n;
	}
	void convert(string s){
		int number=0;
		int tenp=1;
		for(unsigned i=1;i<=s.size();i++){
			number+=(s[s.size()-i]-'0')*tenp;
			tenp*=10;
			if(i%unitsizep==0){
				arr.push_back(number);
				number=0;
				tenp=1;	
			}
		}
		arr.push_back(number);
	}
	cn eval(cn v){
		cn r(0,0);
		for(int i=size-1;i>=0;i--){
			r*=v;
			r+=arr[i];
		}
		return r;
	}
};



valuels fft(coeffls a,vset s){
	valuels r;
	r.init(s.size);
	if(a.size==1){
		for(int i=0;i<s.size;i++){
			r.arr[i] = a.eval(s.s[i]);
		}
		return r;
	}
	coeffls pe;
	coeffls po;
	pe.init(a.size/2);po.init(a.size/2);
	for(int i=0;i<a.size;i++){
		if(i&1) po.arr[i/2] = a.arr[i];
		else pe.arr[i/2]  = a.arr[i];
	}
	vset ns = collapse(s);
	valuels pev = fft(pe,ns);
	valuels pov = fft(po,ns);
	for(int i=0;i<s.size/2;i++){
			r.arr[i]=pev.arr[i]+(s.s[i]*pov.arr[i]);
			r.arr[i+s.size/2] = pev.arr[i]-(s.s[i]*pov.arr[i]);;
	}
	return r;
}

coeffls ifft(valuels a,vset s){
	coeffls r;
	r.init(s.size);
	if(a.size==1){
		for(int i=0;i<s.size;i++){
			r.arr[i] = a.eval(s.s[i]);
		}
		return r;
	}
	valuels pe;
	valuels po;
	pe.init(a.size/2);po.init(a.size/2);
	for(int i=0;i<a.size;i++){
		if(i&1) po.arr[i/2] = a.arr[i];
		else pe.arr[i/2]  = a.arr[i];
	}
	vset ns = collapse(s);
	coeffls pev = ifft(pe,ns);
	coeffls pov = ifft(po,ns);
	for(int i=0;i<s.size/2;i++){
			r.arr[i]=pev.arr[i]+(s.s[i]*pov.arr[i]);
			r.arr[i+s.size/2] = pev.arr[i]-(s.s[i]*pov.arr[i]);;
	}
	return r;
}

int np2(int _n);

int main(){
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a,b;cin>>a>>b;
	coeffls ap;coeffls bp;
	savemeprecision = (a[a.size()-1]-'0')*(b[b.size()-1]-'0');
	savemeprecision%=10;
	ap.convert(a);bp.convert(b);
	n = max((ap.arr).size(),(bp.arr).size());
	n = np2(n);	
	bigint realans;
	realans.init(2*n);
	ap.init(n);bp.init(n);
	vset fftcof;
	fftcof.init(2*n);
	for(int i=0;i<2*n;i++) fftcof.s[i] = cexp((2*M_PI*i)/(2*n));
	vset ifftcof;
	ifftcof.init(2*n);
	cn overn((long double)(1/(2*n)),0.0);
	for(int i=0;i<2*n;i++) ifftcof.s[i] = (cexp((-2*M_PI*i)/(2*n)));
	valuels av = fft(ap,fftcof);
	valuels	bv = fft(bp,fftcof);
	av = av*bv; 
	coeffls ans = ifft(av,ifftcof);
	for(int i=0;i<ans.size;i++) realans.add((ll)(ans.arr[i].real()+0.5)/(2*n),i);
	realans.print();
	return 0;
	
}

int np2(int _n){
	_n--;
	_n|=_n>>1;
	_n|=_n>>2;
	_n|=_n>>4;
	_n|=_n>>8;
	_n|=_n>>16;
	_n++;
	return _n;
}