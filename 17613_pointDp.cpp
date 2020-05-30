//#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<map>
using namespace std;

map<int, int> jumpNum; //배열로 하면 메모리 터짐, 어차피 중간 중간 빌 자리 많음
int getMaxSeriesSum(int n, int* k) {
    //n 이하 최대 2^n -1 구하기
    int x;
    for (int i = 0;; i++) {
        if (((1 << i) - 1) <= n) {
            x = (1 << i) - 1;
        }
        else {
            *k = i-1;
            break;
        }
    }
    return x;
}
int dp(int x) {
    int maxJump;
    int k;
    if (jumpNum.find(x) != jumpNum.end())return jumpNum[x];//이미 구했으면
    else {
        maxJump = getMaxSeriesSum(x, &k);
        jumpNum.insert(pair<int, int>(x, dp(x - maxJump) + k));
    }
    return jumpNum[x];
}
int main() {
    jumpNum.insert(pair<int, int>(0, 0));//첫위치
    jumpNum.insert(pair<int, int>(1, 1));

    int cases;
    cin >> cases;
    for (int qwe = 0; qwe < cases; qwe++) {
        int x, y; //closed interval
        cin >> x >> y;
        //생각해보니까 2의 승수로 커지기 때문에
        //무조건 최대로 뛰는게 이득으로 하는 그리디로 구해진다.
        //중간에 끊어서 두번 뛰는게 이득일 수 가 없다.
        //2^n-1 = 2^i 의 합공식.
        //2의 승수가 나타나면 비트연산자 용이
        //10^9<INT_MAX 라서 int 써도될듯
        int maxi = 0;
        for (int i = x; i <= y; i++) {
            int tmp = dp(i);
            maxi = max(tmp, maxi);
        }
        
        cout << maxi << "\n";
    }
    return 0;
}