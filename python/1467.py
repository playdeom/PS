n=list(map(int,input()))
t=list(map(int,input()))
nc,ec,ans=[0]*10,[0]*10,[]
for i in n:nc[i]+=1
for i in t:ec[i]+=1
for i in n:
    if ec[i] and ec[i]==nc[i]:
        nc[i]-=1
        ec[i]-=1
    else:
        while len(ans):
            if ans[-1]>=i or not ec[ans[-1]]:
                break
            ec[ans[-1]]-=1
            del ans[-1]
        nc[i]-=1
        ans.append(i)
for i in ans:print(i,end='')