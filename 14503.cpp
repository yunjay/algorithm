#include<bits/stdc++.h>
using namespace std;

int cnt=0;
int grid[52][52]={0};//패딩
int robot[3];//0,1 위치 2 방향 up 0 right 1 down 2 left 3
int dx[4] = {-1,0,1,0}; //유클리드 좌표계와 반대로 됨
int dy[4] = {0,1,0,-1};
void printGrid(int N,int M){
    for(int i=0;i<N+1;i++){
        for(int j=0;j<M+1;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
int clean(){
    int nextDir;
    if(grid[robot[0]][robot[1]]==1)return 0;
    else if(grid[robot[0]][robot[1]]==0){
    grid[robot[0]][robot[1]]=2;cnt++;//2는 청소된곳
    }

    for(int i=0;i<4;i++){
        nextDir=(robot[2]+3)%4;//좌향좌
        //a.
        if((grid[robot[0]+dx[nextDir]][robot[1]+dy[nextDir]])==0){
            robot[2]=nextDir;
            robot[0]=robot[0]+dx[nextDir];robot[1]=robot[1]+dy[nextDir];
            clean();
            return 0;
        }else{
            robot[2]=nextDir;
        }
    }
    if(grid[robot[0]-dx[robot[2]]][robot[1]-dy[robot[2]]]==1){
        return 0;
    } else{
        robot[0]=robot[0]-dx[robot[2]];robot[1]=robot[1]-dy[robot[2]];
        clean();
        return 0;
    }
}
int main(){
    for(int i=0;i<52;i++){
        grid[0][i]=1;
        grid[51][i]=1;
        grid[i][0]=1;
        grid[i][51]=1;
    }
    int N,M;
    cin>>N>>M;
    cin>>robot[0]>>robot[1]>>robot[2];
    for(int i=0;i<2;i++)robot[i]++;
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)cin>>grid[i][j];
    printGrid(N,M);
    cout<<endl;
    clean();
    printGrid(N,M);
    cout<<endl;

    cout<<cnt;
    return 0;
}
