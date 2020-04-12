#include<bits/stdc++.h>
using namespace std;

string str;
int alphabet[26]={0};
int result=0;
void bt(int l, char b4){
    if(l==str.size())result++;
    else{
        for(int i=0;i<26;i++){
            if(alphabet[i]==0||i+'a'==b4)continue;
            alphabet[i]--;
            bt(l+1,'a'+i);
            //백트래킹
            alphabet[i]++;
        }
    }
}
int main(){
    cin>>str;
    for(int i=0;i<str.size();i++){
        alphabet[str[i]-'a']++;
    }
    bt(0,str.size());
    cout<<result;
    return 0;
}