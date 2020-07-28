#include<bits/stdc++.h>
using namespace std;
vector<int> a[51]; 
struct shark {
    int size, vel , intel;
        //크기  속도   지능
};
shark sharks[51];
int N;
int eaten[51];
int visited[51];
int dfs(int x)
{
    int i ;
    for( i = 0 ; i < a[x].size() ; i++  ) {
        int y = a[x][i]; //방문
        if(visited[y] ) continue;
        visited[y] = 1 ;
        if(eaten[y] == 0 || dfs(eaten[y])) { //비켜주기 or 비어있기
            eaten[y] = x; // 이건 비우지 않음 (두번씀)
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,j;
    cin >> N;  
    for(i=1; i<= N ; i++) {
        cin >> sharks[i].size >> sharks[i].vel >> sharks[i].intel ;
    }
    for(i=1; i<=N-1 ;i++) {
                for(j=i+1;j<=N; j++) {
                    //다 같으면
                    if(sharks[i].size == sharks[j].size && sharks[i].vel == sharks[j].vel && sharks[i].intel == sharks[j].intel  )
                        a[i].push_back(j);
                    //i가 이기면
                    else if(sharks[i].size >= sharks[j].size && sharks[i].vel >= sharks[j].vel && sharks[i].intel >= sharks[j].intel  )
                        a[i].push_back(j);
                    //j 가 이기면
                    else if(sharks[i].size <= sharks[j].size && sharks[i].vel <= sharks[j].vel && sharks[i].intel <= sharks[j].intel  )
                        a[j].push_back(i);
                }
    }
    int ans = 0 ;
    for(int j=0;j<2;j++)
        for( i=1 ; i<=N ;i++){
            memset(visited,0,sizeof(visited));
            if(dfs(i)) ans++;
        }
    cout << N-ans;
    return 0;
}