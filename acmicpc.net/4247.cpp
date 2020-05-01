#include<bits/stdc++.h>
using namespace std;

bool hasWon(char grid[][3], char X){
    for(int i=0;i<3;i++){
        if(grid[i][0]==X&&grid[i][1]==X&&grid[i][2]==X)
            return true;
    }
    for(int i=0;i<3;i++){
        if(grid[0][i]==X&&grid[1][i]==X&&grid[2][i]==X)
            return true;
    }
    if(grid[0][0]==X&&grid[1][1]==X&&grid[2][2]==X)
        return true;
    if(grid[0][2]==X&&grid[1][1]==X&&grid[2][0]==X)
        return true;
    return false;
}
void printGrid(char grid[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int O=0,X=0;
        char grid[3][3]={0};
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                char c;
                cin>>c;
                if(c=='O')O++;
                else if(c=='X')X++;
                grid[j][k]=c;
            }
        }
        //printGrid(grid);
        if(O>X || X>O+1)cout<<"no\n"; //X가 선공
        else if(hasWon(grid,'O')&&hasWon(grid,'X')
                ||hasWon(grid,'O') && X!=O
                ||hasWon(grid,'X') && X!=O+1
                ){
                    cout<<"no\n";
                }
        else cout<<"yes\n";        
    }
    return 0;
}