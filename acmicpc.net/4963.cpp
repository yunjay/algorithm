#include <bits/stdc++.h>
using namespace std;

int r,c;

int DFS(int x, int y){
    visited[x][y]=1;    
    
}

int main() {
    int is;
    int map[50][50];
    int visited[50][50]={0};
    pair<int,int> dir[8]={{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1}};
    
    do{
        is=0;
        cin>>r;
        cin>>c;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>map[i][j];
            }
        }
        
    
    
        cout<<is;
    }while(r&&c); 

   
    return 0;
}

