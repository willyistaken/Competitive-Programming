#include <iostream>

using namespace std;


void merge(int *p, int mfront, int mend)

{
	int mid=(mfront+mend)/2;
	int temp[mend-mfront+1];
	int fhead=mfront;
	int ehead=mid+1;
	for(int i=0;i<mend-mfront+1;i++){
		if(fhead>mid){
			temp[i]=p[ehead];
			ehead++;
			continue;
		}
		if(ehead>mend){
			temp[i]=p[fhead];
			fhead++;
			continue;
		}
		if(p[fhead]>p[ehead]){
			temp[i]=p[ehead];
			ehead++;
		}else{
			temp[i]=p[fhead];
			fhead++;
		}
	}
	for(int i=0;i<mend-mfront+1;i++){
		p[i+mfront] = temp[i];
	}
	return;
}

void MergeSort(int *p, int mfront, int mend)

{
	if(mfront==mend) return;
	if(mend-mfront==1){
		if(p[mfront]>p[mend]){
			swap(p[mfront],p[mend]);
			}
			return ;
	}
	int mid=(mfront+mend)/2;
	MergeSort(p,mfront,mid);
	MergeSort(p,mid+1,mend);
	merge(p,mfront,mend);
}
int main()

{

	int scores[7] = {9, 7, 31, 4, 1, 3, 2};

	cout << "before sort" << endl;

	for (int i = 0; i < 7; i++)

	{

		cout << scores[i] << " ";
	}

	cout << endl;

	MergeSort(scores, 0, 6);

	cout << "after sort" << endl;

	for (int i = 0; i < 7; i++)

	{

		cout << scores[i] << " ";
	}

	cout << endl;

	return 0;
}
