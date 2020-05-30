#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    pair<int,int> dp = {0,1};
    cin>>n;
    for(int i=0;i<n;i++){
        dp={dp.first+dp.second,dp.first};
    }
    cout<<dp.first+dp.second;
}