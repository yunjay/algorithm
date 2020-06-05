#include<bits/stdc++.h>
using namespace std;

int lines[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 5}; //0~9
vector<pair<int,vector<int>>> numsWithSameLines=
    {{2,{1}},{3,{7}},{4,{4}},{5,{2,3,5,9}},{6,{0,6}},{7,{8}}};
/*
void getPartition(int n,int digits){//n을 digits 개로 분할
    int num=n;
    if(digits==1) partitions.push_back(n);
    else{
        for(int i=0;i<digits;i++){
        for(int j=0;j<6;j++){
        for(int k : numsWithSameLines[j].second){
            num-=numsWithSameLines[j].first;//2~7
            partitions.push_back(k);
            if(nums==0)return;
        }
        }
        }

    }
}*/
int partitionIndex=0;
vector<vector<int>> partitions;
// void twoPartition(int n){ //2~7만 쓸때
//     partitions.push_back({});
//     for(int i=2;i<=7;i++){
//         if(i==n)partitions[partitionIndex++].push_back(i);
//         for(int j=2;j<=7;j++){
//             if(i+j==n){
//                 partitions.push_back({});
//                 partitions[partitionIndex].push_back(i);
//                 partitions[partitionIndex++].push_back(j);
//             }
//         }
//     }
// }

vector<vector<int>> partition(int n,int digits){
    vector<vector<int>> res;
    vector<int> tmp;
    int sum = n;
    for(int i=1;i<=digits;i++){
        for(int j=0;j<i;j++){
            // while(1){
            // for(int k=2;k<=7;k++){
            //     tmp.push_back(k);
            //     sum-=k;
            //     if(sum<0){tmp.clear();break;}
            // }
            // }
        }
        if(sum==0){
            res.push_back(tmp);
        }
    }
    return res;
}
int getDigits(int n){//몇자리수인지
    int res=0;
    while(n>0){
        n/=10;
        res++;
    }
    return res;
}
int main(){
    string str;
    cin>>str;
    int linesNum=0; //총 선의 개수
    int *placeNums = new int[str.length()]; //각 자릿수
    long long strToI=stoi(str);
    int min=strToI+1;//출력
    for(int i=0;i<str.length();i++){
        linesNum+=lines[str[i]];
        placeNums[i]=str[i];
    }
    for(int i=1;i<=str.length();i++){
        partitions.clear();
        getPartition(linesNum,i);

    }

    return 0;
}

