from​ ​decimal​ ​import​ ​Decimal​, ​getcontext
getcontext​().​prec​ ​=​ ​1000 
a​ ​=​ ​Decimal​(​input​()).​sqrt​() 
print​(​'{:.50f}'​.​format​(​a​))