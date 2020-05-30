#include<bits/stdc++.h>
#define sibgu 1000000001
using namespace std;

int main(){
    int cases;
    int jumpNum[sibgu]; //뛰는 범위가 너무 커서 배열로 못함
    // array -> map
    jumpNum[0]=0;
    jumpNum[1]=1;
    jumpNum[2]=2;
    jumpNum[3]=2;
    cin>>cases;
    for(int qwe=0;qwe<cases;qwe++){
        int x,y; //closed interval
        cin>>x>>y;
        for(int i=4;i<=y;i++){
            
            int two=1;
            int minJumpNum=INT_MAX;
            while(i-two>0){
                minJumpNum=min(minJumpNum,jumpNum[i-two]+1);
                two*=2;
            }
            jumpNum[i]=minJumpNum;
        }
        int max=0;
        for(int i=x;i<=y;i++){
            if(jumpNum[i]>max)max=jumpNum[i];
        }
        cout<<max<<"\n";
    }
    return 0;
}