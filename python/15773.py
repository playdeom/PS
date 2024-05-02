from heapq import*;p,q=input,int
b,h=[],0;a=[]
for i in' '*q(p()):x,y=map(q,p().split());a+=(x+y,y),
a.sort()
for u,v in a:
 heappush(b,-v);h+=v
 if u<h:h+=heappop(b)
print(len(b))