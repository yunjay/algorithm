#include<bits/stdc++.h>
using namespace std;


int main(){
    vector <pair<int,int>> lines; 
    int n;
    int length=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        lines.push_back({a,b});
    }
    sort(lines.begin(),lines.end());
    int beforeLeft=-1000000000;
    int beforeRight=-1000000000; //0,0 출발
    for(int i=0;i<lines.size(); i++){
		int curLeft = lines[i].first;
		int curRight = lines[i].second;
		if (beforeLeft<=curLeft && curRight<=beforeRight)continue;//안에있으면
		else{
            if (curLeft<beforeRight) //겹침
                length+=(curRight-beforeRight);
            else{length+=curRight-curLeft;}
            beforeLeft = curLeft;
            beforeRight = curRight;
        }
    }
    cout<<length;
    return 0;
}