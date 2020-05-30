#include<bits/stdc++.h>
using namespace std;

vector<int> result;
int *arr,*visited;
void dfs(int start, int current){
    if(visited[current])
        if(current==start)result.push_back(start);//cycle
    else{
        visited[current]=1;
        dfs(start,arr[current]); //타고 들어가기
    }
}
int main(){
    int n;
    cin>>n;
    arr = new int[n+1];
    visited = new int[n+1];
    arr[0]=0;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        arr[i]=a;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)visited[j]=0;
        //if(i==arr[arr[i]])ans.push_back(arr[i]);
        dfs(i,i);
    }
    //sort(result);
    cout<<result.size()<<"\n";
    for(int i=0;i<result.size();i++)cout<<result[i]<<"\n";
    return 0;
}