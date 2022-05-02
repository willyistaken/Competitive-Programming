from decimal import *

getcontext().prec = 100
a = int(input())
a = Decimal(a)
b = Decimal(a/2)
for i in range(20):
    b=Decimal(0.5)*(b+(a/b))
print(round(b,50))