from decimal import *

getcontext().prec = 5
a1 = float(input())
a1 = Decimal(a1)
a2 = float(input())
a2 = Decimal(a2)
b1 = float(input())
b1 = Decimal(b1)
b2 = float(input())
b2 = Decimal(b2)
if(b1==0 and b2==0):
    print("0.00")
    print("0.00")
else:
    print(round((b1-b2)/(a2-a1),2))
    print(round((((b1-b2)*a1)/(a2-a1))+b1,2))