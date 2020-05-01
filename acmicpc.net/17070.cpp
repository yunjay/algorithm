#include<bits/stdc++.h>
using namespace std;

// struct pipe{
//     pair<int,int> back;
//     pair<int,int> front;
//     int state;
// };

int main(){
    int n;
    int house[16][16];
    int dp[16][16][3]={0};//0 -- 1 \ 2 l
    
    for(int i=0;i<16;i++)for(int j=0;j<16;j++)house[i][j]=1;
    
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>house[i][j];
    
    //환경 설정
    dp[0][1][0]=1;

    /*
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"("<<dp[i][j][0]<<","<<dp[i][j][1]<<","<<dp[i][j][2]<<") ";
        }
        cout<<endl;
    }
    */

    for(int i=0;i<n;i++){ //i 가 행, j 가 열, k 가 state
        for(int j=0;j<n;j++){//두번째칸부터?
                if(i<1&&j<2)continue;
            for(int k=0;k<3;k++){
                if(house[i][j]==0){
                    switch(k){
                        case 0://가로
                            if(j==0){}else{
                                dp[i][j][k]+=dp[i][j-1][0];
                                dp[i][j][k]+=dp[i][j-1][1];
                            }
                            break;
                        case 1://대각선
                            if(i==0||j==0){}
                            else if(house[i-1][j]==0&&house[i][j-1]==0){
                                dp[i][j][k]+=dp[i-1][j-1][0];
                                dp[i][j][k]+=dp[i-1][j-1][1];
                                dp[i][j][k]+=dp[i-1][j-1][2];
                            }
                            break;
                        case 2://새로
                            if(i==0){}
                            else{
                            dp[i][j][k]+=dp[i-1][j][1];
                            dp[i][j][k]+=dp[i-1][j][2];
                            }
                            break;
                    }
                }
            }
        }
    }

    /*
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"("<<dp[i][j][0]<<","<<dp[i][j][1]<<","<<dp[i][j][2]<<") ";
        }
        cout<<endl;
    }
    */

    int sum=0;
    sum+=dp[n-1][n-1][0];
    sum+=dp[n-1][n-1][1];
    sum+=dp[n-1][n-1][2];
    cout<<sum;
    return 0;
}