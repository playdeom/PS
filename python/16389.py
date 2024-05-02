from heapq import*
a,b,h=[],[],0
p,q=int,input
for i in' '*p(q()):y,x=map(p,q().split());a+=(x,y),
a.sort()
for i,v in a:
 heappush(b,-v);h+=v
 if i<h:h+=heappop(b)
print(len(b))