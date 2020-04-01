#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    long long arr[101] = { 1, 1, 1, 1, 2, 2, };
    vector<int> inputs;
    cin>>n; 
    for(int i=0;i<n;i++){
        cin>>m;
        inputs.push_back(m);
    }
    for (int i = 6; i <= 100; i++){
        arr[i] = arr[i - 1] + arr[i - 5];
    }
    for(int i=0;i<n;i++){
        cout<<arr[inputs[i]]<<"\n";
    }
    return 0;
}
