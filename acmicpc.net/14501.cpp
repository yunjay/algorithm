#include <bits/stdc++.h>
using namespace std;
struct day{
    int a;
    int b;
    int price;
};

//마지막날에 1일짜리 상담을 할수있는거냐?
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
    for(int i=1;i<n+1;i++){
        schedule.push_back({i,i+1,0});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<schedule.size();j++){
            int ja,jb,jprice;
            ja=schedule[j].a;
            jb=schedule[j].b;
            jprice=schedule[j].price;
            //for(int k=0;k<=n;k++){cout<<distance[k+1]<<" ";}
            //cout<<endl;
            distance[jb]=max(distance[jb],distance[ja]+jprice);
        }
        
    }
    
    cout<<distance[n+1];
    return 0;
}

