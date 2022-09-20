#pragma GCC optimize("Ofast")
#include <cstdio>
using namespace std;
typedef long long ll;
struct pt{
    double x;
    double y;
};
pt operator+(const pt &a,const pt &b){
    return {a.x+b.x,a.y+b.y};
}

pt operator-(const pt &a,const pt &b){
    return {a.x-b.x,a.y-b.y};
}
void swap(pt *a,pt *b){
    pt g = *a;
    *a = *b;
    *b = g;
}
const double sq32 = 0.86602540378;
const double half = 0.5;
int main(){
    pt a,b;
    while(scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y)!=EOF){   
    pt v = b-a;
    pt f,s;
    f= {half*v.x-sq32*v.y,sq32*v.x+half*v.y};
    s= {half*v.x+sq32*v.y,-1*sq32*v.x+half*v.y};
   f = a+f;
   s = a+s;  
   if(f.x>s.x ||(f.x==s.x && f.y>s.y)) swap(&f,&s);
    printf("%.3lf %.3lf %.3lf %.3lf\n",f.x,f.y,s.x,s.y);
    }
    return 0;
}

// rotation matrix


