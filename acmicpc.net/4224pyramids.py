def high(i):
    return i*(i+1)*(2*i+1)/6
def low(i):
    return i*(i+1)*(i+2)/6
i=1
while low(i) <1000000:
    print(str(i)+"th low pyramid : "+str(low(i)))
    i+=1
   
j=1
while high(j)<1000000:    
    print(str(j)+"th high pyramid : "+str(high(j)))
    j+=1
    
print("total pyramids possible : "+str(i+j-2-3))
