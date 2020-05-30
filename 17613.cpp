//#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<map>
using namespace std;

map<pair<long long, long long>, int> jump;

int dp(long long l, long long r){
	if(jump.find({l, r}) != jump.end()) return jump[{l, r}];

	int result=0;
    //30 까지 가면 10^9 넘어감
	for(int i=1; i<=30; i++){ //[l, r]을 나눔
		//i가 뛰는 횟수
        //이게 ll 쓰는 이유가 인풋은 int를 안넘는데 2^i+1 이 넘어서
        //0,1,3,7,15,31...
		long long closedLeft = (1ll << i) - 1; //2^i - 1
        if(closedLeft>r)break;
		long long closedRight = (1ll << (i+1)) - 2; //2^(i+1) - 2
		closedLeft = max(l, closedLeft);    //컷팅
        closedRight = min(r, closedRight);  //컷컷컷
        //점프해서 이동
        //구간 벗어나면 밑에꺼가 성립 안됌. min r로 인해서
		if(closedLeft <= closedRight) {
		long long nextLeft = closedLeft - (1ll << i) + 1; //2^i - 1만큼 점프를 하고 남은 길이
		long long nextRight = closedRight - (1ll << i) + 1;
        result = max(result, dp(nextLeft, nextRight) + i); //i 번 뛰어야 2^i -1 거리
		//cout<<"l: "<<l<<" r: "<<r<<endl<<" closedLeft: "<<closedLeft<<" closedRight: "<<nextRight<<endl<<"nextLeft: "<<nextLeft<<" nextRight: "<<nextRight<<endl;
        } //통째로 왼쪽으로 뛰면서 진행
	}

	return jump[{l, r}] = result;
}

int main(){
	jump[{0,0}]=0;
	jump[{0,1}]=1;
	jump[{1,1}]=1;
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
        cout << dp(x,y) << "\n";
    }
    return 0;
}