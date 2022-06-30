#include<stdio.h>
/*
0 1 2
3 4 5
6 7 8
*/
int dir[9][4]={
	1,3,10,10,
	0,2,4,10,
	1,5,10,10,
	0,4,6,10,
	1,3,5,7,
	2,4,8,10,
	3,7,10,10,
	4,6,8,10,
	5,7,10,10,
};
inline void sw(int &a,int &b){
	a^=b^=a^=b;
}
inline int abs(int a){
	return a>0?a:-a;
}
int puz[10],ans[10],dmax,z;
int h(){
	int sum=0;
	for(int i=0;i<9;i++){
		if(puz[i]){
			sum+=abs((ans[puz[i]])%3-i%3)+abs((ans[puz[i]])/3-i/3);
		}
	}
	return sum;
}
int dfsid(int depth,int pre){
	int hv=h(),rp;
	if(depth+hv>dmax)return -1;
	if(hv==0)return depth;
	for(int i=0;i<9;i++){
		if(puz[i]==0){
			//printf("puz %d\n",i);
			for(int j=0;j<4;j++){
				if(dir[i][j]!=10 && dir[i][j]!=pre){
					sw(puz[dir[i][j]],puz[i]);
					rp=dfsid(depth+1,i);
					sw(puz[dir[i][j]],puz[i]);
					if(~rp)return rp;
				}
			}
			return -1;
		}
	}
}
main(){
	for(int i=0;i<9;i++)scanf("%d",puz+i);
	for(int i=0;i<9;i++){
		scanf("%d",&z);
		ans[z]=i;
	}
	int way;
	for(dmax=0;;dmax+=2){
		way=dfsid(0,-1);
		if(~way)break;
	}
	printf("%d\n",way);
}
