g=input()
n=int(g.split()[0])
m = int(g.split()[1])
a = [[0]*m]*4
for i in range(n):
    s=input()
    a[i]=s.split()
c = int(input())
for i in range(0,n):
    for j in range(0,m):
        print(int(a[i][j])*c,end=' ')
    print()