#include <bits/stdc++.h>
using namespace std;
struct day{
    int a;
    int b;
    int price;
};

int main() {
    int n;
    vector<day> schedule;
    int distance[22]={0};   
    cin>>n;
    for(int i=1;i<=n;i++){
        int t,p;
        cin>>t>>p;
        schedule.push_back({i,i+t,p});
    }  
    //0짜리 길 만들기 (다음날 넘어가기)
    for(int i=1;i<n+1;i++){
        schedule.push_back({i,i+1,0});
    }
    //최적 경로
    for(int i=0;i<n;i++){
        for(int j=0;j<schedule.size();j++){
            int ja,jb,jprice;
            ja=schedule[j].a;
            jb=schedule[j].b;
            jprice=schedule[j].price;
            distance[jb]=max(distance[jb],distance[ja]+jprice);
        }   
    }
    cout<<distance[n+1];
    return 0;
}
