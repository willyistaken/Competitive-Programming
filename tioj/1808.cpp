#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a[170]={"0", "1", "5", "6", "25", "76", "376", "625", "9376", "90625", "109376", "890625", "2890625", "7109376", "12890625", "87109376", "212890625", "787109376", "1787109376", "8212890625", "18212890625", "81787109376", "918212890625", "9918212890625", "40081787109376", "59918212890625", "259918212890625", "740081787109376", "3740081787109376", "6259918212890625", "43740081787109376", "56259918212890625", "256259918212890625", "743740081787109376", "2256259918212890625", "7743740081787109376", "92256259918212890625", "392256259918212890625", "607743740081787109376", "2607743740081787109376", "7392256259918212890625", "22607743740081787109376", "77392256259918212890625", "977392256259918212890625", "9977392256259918212890625", "19977392256259918212890625", "80022607743740081787109376", "380022607743740081787109376", "619977392256259918212890625", "3380022607743740081787109376", "6619977392256259918212890625", "93380022607743740081787109376", "106619977392256259918212890625", "893380022607743740081787109376", "4106619977392256259918212890625", "5893380022607743740081787109376", "95893380022607743740081787109376", "995893380022607743740081787109376", "9004106619977392256259918212890625", "90995893380022607743740081787109376", "109004106619977392256259918212890625", "890995893380022607743740081787109376", "3890995893380022607743740081787109376", "6109004106619977392256259918212890625", "96109004106619977392256259918212890625", "103890995893380022607743740081787109376", "896109004106619977392256259918212890625", "9103890995893380022607743740081787109376", "30896109004106619977392256259918212890625", "69103890995893380022607743740081787109376", "230896109004106619977392256259918212890625", "769103890995893380022607743740081787109376", "3230896109004106619977392256259918212890625", "6769103890995893380022607743740081787109376", "23230896109004106619977392256259918212890625", "76769103890995893380022607743740081787109376", "423230896109004106619977392256259918212890625", "576769103890995893380022607743740081787109376", "3423230896109004106619977392256259918212890625", "6576769103890995893380022607743740081787109376", "23423230896109004106619977392256259918212890625", "76576769103890995893380022607743740081787109376", "423423230896109004106619977392256259918212890625", "576576769103890995893380022607743740081787109376", "2576576769103890995893380022607743740081787109376", "7423423230896109004106619977392256259918212890625", "42576576769103890995893380022607743740081787109376", "57423423230896109004106619977392256259918212890625", "442576576769103890995893380022607743740081787109376", "557423423230896109004106619977392256259918212890625", "9442576576769103890995893380022607743740081787109376", "99442576576769103890995893380022607743740081787109376", "999442576576769103890995893380022607743740081787109376", "1000557423423230896109004106619977392256259918212890625", "8999442576576769103890995893380022607743740081787109376", "11000557423423230896109004106619977392256259918212890625", "88999442576576769103890995893380022607743740081787109376", "188999442576576769103890995893380022607743740081787109376", "811000557423423230896109004106619977392256259918212890625", "3811000557423423230896109004106619977392256259918212890625", "6188999442576576769103890995893380022607743740081787109376", "36188999442576576769103890995893380022607743740081787109376", "63811000557423423230896109004106619977392256259918212890625", "136188999442576576769103890995893380022607743740081787109376", "863811000557423423230896109004106619977392256259918212890625", "9136188999442576576769103890995893380022607743740081787109376", "19136188999442576576769103890995893380022607743740081787109376", "80863811000557423423230896109004106619977392256259918212890625", "419136188999442576576769103890995893380022607743740081787109376", "580863811000557423423230896109004106619977392256259918212890625", "9580863811000557423423230896109004106619977392256259918212890625", "90419136188999442576576769103890995893380022607743740081787109376", "490419136188999442576576769103890995893380022607743740081787109376", "509580863811000557423423230896109004106619977392256259918212890625", "3490419136188999442576576769103890995893380022607743740081787109376", "6509580863811000557423423230896109004106619977392256259918212890625", "33490419136188999442576576769103890995893380022607743740081787109376", "66509580863811000557423423230896109004106619977392256259918212890625", "166509580863811000557423423230896109004106619977392256259918212890625", "833490419136188999442576576769103890995893380022607743740081787109376", "2166509580863811000557423423230896109004106619977392256259918212890625", "7833490419136188999442576576769103890995893380022607743740081787109376", "37833490419136188999442576576769103890995893380022607743740081787109376", "62166509580863811000557423423230896109004106619977392256259918212890625", "937833490419136188999442576576769103890995893380022607743740081787109376", "9937833490419136188999442576576769103890995893380022607743740081787109376", "90062166509580863811000557423423230896109004106619977392256259918212890625", "109937833490419136188999442576576769103890995893380022607743740081787109376", "890062166509580863811000557423423230896109004106619977392256259918212890625", "9890062166509580863811000557423423230896109004106619977392256259918212890625", "90109937833490419136188999442576576769103890995893380022607743740081787109376", "490109937833490419136188999442576576769103890995893380022607743740081787109376", "509890062166509580863811000557423423230896109004106619977392256259918212890625", "1490109937833490419136188999442576576769103890995893380022607743740081787109376", "8509890062166509580863811000557423423230896109004106619977392256259918212890625", "38509890062166509580863811000557423423230896109004106619977392256259918212890625", "61490109937833490419136188999442576576769103890995893380022607743740081787109376", "938509890062166509580863811000557423423230896109004106619977392256259918212890625", "2938509890062166509580863811000557423423230896109004106619977392256259918212890625", "7061490109937833490419136188999442576576769103890995893380022607743740081787109376", "97061490109937833490419136188999442576576769103890995893380022607743740081787109376", "197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "9802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "30197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "69802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "169802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "830197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "1830197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "8169802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "91830197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "108169802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "891830197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "9108169802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "19108169802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "80891830197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "319108169802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "680891830197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "2680891830197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "7319108169802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "92680891830197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "992680891830197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "3007319108169802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "6992680891830197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "46992680891830197061490109937833490419136188999442576576769103890995893380022607743740081787109376", "53007319108169802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "953007319108169802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "3953007319108169802938509890062166509580863811000557423423230896109004106619977392256259918212890625", "6046992680891830197061490109937833490419136188999442576576769103890995893380022607743740081787109376"};

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<170;i++){
		if(a[i].size()==n) cout<<a[i]<<"\n";
	}
	return 0;
}

/*stuck no pattern detected*/
