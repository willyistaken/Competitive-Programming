import sys
for line in sys.stdin:
    s=line.split()
    a=int(s[0])
    b=int(s[2])
    if(a==0 and b==0):
        break
    if(s[1].find('+')!=-1):
        print(a+b)
        continue
    if(s[1].find('-')!=-1):
        print(a-b)
        continue
    if(s[1].find('*')!=-1):
        print(a*b)
        continue
    if(s[1].find('/')!=-1):
        print("{}...{}".format(int((a-a%b)/(b)),a%b))
        continue