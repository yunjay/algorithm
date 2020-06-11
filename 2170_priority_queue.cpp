#include<bits/stdc++.h>
using namespace std;

priority_queue <pair<int,int>> lines; 

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    int length=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        lines.push({-a,-b});
    }
    while(!lines.empty()){
        //끝에 도달했으면
        int curLeft=-lines.top().first;
        int curRight=-lines.top().second;
        lines.pop();
        if(lines.empty()){length+=curRight-curLeft;break;}
        else{
            if(-lines.top().first<curRight){//이러면 겹치는거임
                //top().first 는 항상 curLeft 보다 크다 (prio queue)
                if(-lines.top().second>curRight)length+=-lines.top().first-curLeft;
                else {lines.pop();lines.push({-curLeft,-curRight});
                }
            }
            else{
                length+=curRight-curLeft;
            }
        }
    }
    cout<<length;
    return 0;
}