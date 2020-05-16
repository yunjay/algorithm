#include<bits/stdc++.h>
#define MIL 1000000
using namespace std;

struct pyramid{
    int height;
    int volume;
    int lobby;
    bool isHigh;
};

pyramid pyramids[320];//4224pyramids.py 참고

bool cmpVolume(pyramid a, pyramid b){
    return (a.volume<b.volume);
}

int high(int n){
    return n*(n+1)*(2*n+1)/6;
}
int low(int n){
    return n*(n+1)*(n+2)/6;
}

string pyramidToString(pyramid p){
    return to_string(p.lobby)+(p.isHigh?"H":"L");
}
void addtoString(String s, pyramid p){
    s.append(" ");
    s.append(pyramidToString(p));
    return;
}
void pyramidLister(){
    int index=0;
    //H 피라미드
    for(int i=2;high(i)<MIL;i++){
        pyramids[index++]={i,high(i),i,true};
    }
    //L 피라미드
    for(int i=3;low(i)<MIL;i++){
        pyramids[index++]={(i+1)/2,low(i),i,false};
    }
    sort(pyramids,&pyramids[320],cmpVolume);
}
void solve(int n){
    for(int i=n;i>0;i--){
        
    }
}
int main(){
    int case_=1,n;
    pyramidLister();
    while(){
        cin>>n;
        if(n<=0)break;
        String result="";

        cout<<"Case "<<case_<<":";
        cout<<result;
        cout<<"\n";
        solve(n);

        case_++;
    }
    // for (int i=0;i<320;i++){
    //     cout<<pyramids[i].volume<<endl;
    // }
    return 0;
}