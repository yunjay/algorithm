#include<bits/stdc++.h>
using namespace std;

string str;
vector<string> v;
int result=0;
bool isLucky(void){
    for(int i=1;i<str.length()-1;i++){
        if(str[i]==str[i-1]||str[i]==str[i+1]) return false;
    }
    return true;
}
void bt(int l,int r){
    if(l==r){
        if(isLucky()){
            //이미 있는지 확인
            if(!count(v.begin(),v.end(),str)){
            v.push_back(str);
            result++;
            }
        }
    }
    else{
        for(int i=l;i<str.length();i++){
            swap(str[l],str[i]);
            bt(l+1,r);
            //백트랙킹
            swap(str[i],str[l]);
        }
    }
}

int main(){
    cin>>str;
    bt(0,str.length()-1);
    cout<<result;
    return 0;
}