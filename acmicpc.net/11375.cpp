#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> *edges;
int *visited;
int *taken;
int dfs(int x)
{
    int i;
    for(i=0; i<edges[x].size(); i++) {
        int y = edges[x][i]; //방문
        if(visited[y] ) continue;
        visited[y] = 1 ;
        if(taken[y] == 0 || dfs(taken[y])) { //비켜주기 or 비어있기
            taken[y] = x; // 이건 비우지 않음 (두번씀)
            return 1;
        }
    }
    return 0;
}
int main(){
    int ans=0;
    cin>>n>>m;
    // n 이 사람 m 이 작업
    edges=new vector<int>[n];
    visited=new int[n];
    visited=new int[n];
    for(int i=0;i<n;i++){
        int o,p;
        cin>>o;
        for(int j=0;j<o;j++){
            cin>>p;
            edges[i].push_back(p);
        }
    }
    for(int i=0 ; i<n ;i++){
        memset(visited,0,sizeof(visited));
        if(dfs(i)) ans++;
    }
    cout<<ans;
    return 0;
}
