a = input()
b = input()
l=len(a)
if len(a)==1:
    if a==b:
        print(1)
    else:
        print(0)
    quit()
i=0
for _ in range(0,len(a)):
    if a[_]!=b[_]:
        break
    i+=1
    l-=1
for _ in range(0,len(a)):                                                               
    if a[len(a)-_-1]!=b[len(a)-_-1]:                                                
        break                                                    
    l-=1
fit=1
total=0
for _ in range(0,l):
    if a[i+_]!=b[i+l-1-_]:
        fit=0;
        break;
if fit:
    total+=1
    _=0
    while _<i and i+l+_<len(a):
        if a[i-1-_]!=a[i+l+_]:
            break
        total+=1
        _+=1
print(total)
