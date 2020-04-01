#include <bits/stdc++.h>
using namespace std;

bool compareX(pair<long,long> &a, pair<long,long> &b) { return a.first < b.first; }
bool compareY(pair<long,long> &a, pair<long,long> &b) { return a.second < b.second; }

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        long N, x, y;
        long long ret = 0;
        bool distinct = false;
        cin >> N;
        pair
        pair<long,long> p[N];
        point p[N];
        for(long i=0; i<N; i++){
                cin >> x >> y;
                p[i].x = x;
                p[i].y = y;
        }

        //! 세로선 검출.
        sort(p, p+N, compareX);
        distinct = true;
        for(long i=1; i<N; i++){
                if(p[i-1].x == p[i].x) {
                        if(distinct){
                                distinct = false;
                                ret++;
                        }
                }
                else {
                        distinct = true;
                }
        }

        //! 가로선 검출.
        sort(p, p+N, compareY);
        distinct = true;
        for(long i=1; i<N; i++){
                if(p[i-1].y == p[i].y) {
                        if(distinct){
                                distinct = false;
                                ret++;
                        }
                }
                else {
                        distinct = true;
                }
        }

        cout << ret;
}