// C++ implementation to generate
// test-case for the Tree

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define fast ios_base::sync_with_stdio(false);
#define MOD 1000000007

// Maximum Number Of Nodes
#define MAXNODE 100;

// Maximum Number Of testCases
#define MAXT 10;

// Maximum weight
#define MAXWEIGHT 100;

#define MAXEDGE 10001;
// Function for the path
// compression technique
ll find(ll parent[], ll x)
{
	// If parent found
	if (parent[x] == x)
		return x;

	// Find parent recursively
	parent[x] = find(parent, parent[x]);

	// Return the parent node of x
	return parent[x];
}

// Function to compute the union
// by rank
void merge(ll parent[], ll size[],
		ll x, ll y)
{
	ll r1 = find(parent, x);
	ll r2 = find(parent, y);

	if (size[r1] < size[r2]) {
		parent[r1] = r2;
		size[r2] += size[r1];
	}
	else {
		parent[r2] = r1;
		size[r1] += size[r2];
	}
}

// Function to generate the
// test-cases for the tree
void generate()
{
		
		int n = 5+rand()%MAXNODE;
		int m  = 5+rand()%MAXEDGE;
		int a[n+1][n+1] = {{0}};
		cout<<n<<" ";
		int s=0;
		for(int i=0;i<m;i++){
				int x = rand()%n+1;
				int y = rand()%n+1;
				int w = rand()%MAXWEIGHT;
				a[x][y] = w;
		}
		for(int i=1;i<=n;i++){
				for(int j=1;j<=i;j++){
					if(i==j) continue;
					if(a[i][j]) {
						s++;
					}
				}
		}
		cout<<s<<"\n";
		for(int i=1;i<=n;i++){
				for(int j=1;j<=i;j++){
					if(i==j) continue;
					if(a[i][j]) {
						cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
					}
				}
		}
		/*
		int q =  5+rand()%10;
		cout<<q<<"\n";
		while(q--){
			int a = rand()%n+1;
			int b = rand()%n+1;
			cout<<a<<" "<<b<<"\n";
		}
		*/
}

// Driver Code
int main()
{
	// Uncomment the below line to store
	// the test data in a file
	// freopen ("output.txt", "w", stdout);

	// For random values every time
	srand(time(NULL));

	fast;

	generate();
}

