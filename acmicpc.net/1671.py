def dfs(x,v):
    v[x]=1
    for t in a[x]:
        if eaten[t]<0 or not v[eaten[t]] and dfs(eaten[t],v):
            eaten[t]=x
            return 1
    return 0

n = int(input())
s = sorted([tuple(map(int,input().split())) for i in range(n)])
a=[[j for j in range(i) if all(p>=q for p,q in zip(s[i],s[j]))] for i in range(n)]
eaten=[-1]*51

print(n-sum(dfs(i,[0]*n)) for i in range(n) for j in range(2))