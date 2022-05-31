n = int(input())

a={}

for i in range (n):
    s = input()
    a[s.split()[0]]=s.split()[1];
    a[s.split()[1]]=s.split()[0];

s=input()
print(a[s]);