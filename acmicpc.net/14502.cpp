#include<bits/stdc++.h>

using namespace std;

int chart[9][9];
int chartTmp[9][9];
int maxCleanArea = 0;

vector<pair<int, int>> dir = { {1,0},{-1,0},{0,1},{0,-1} };
vector<pair<int, int>> infected;
vector<pair<int, int>> clean;
vector<int> combinationTmp;
queue<vector<int>> combinations;

//조합 다 해보는거 말고 벽을 예쁘게 세울 방법이 없을까?
void makeCombinations(int place, int k) {
    if (k == 3) {
        combinations.push(combinationTmp);
        return;
    }
    for (int i = place; i < clean.size()-1; i++) {
        combinationTmp.push_back(i);
        makeCombinations(i + 1, k + 1);
        combinationTmp.pop_back();
    }
}
void copyChart() {
    for (int i = 0; i < 9; i++)for (int j = 0; j < 9; j++)chartTmp[i][j] = chart[i][j];
}
void spreadVirus(int x, int y) {
    if (chartTmp[x][y] == 2) {
        for (auto coor : dir) {
            if (x + coor.first >= 0 && x + coor.first < 9 && y + coor.second >= 0 && y + coor.second < 9) {
                if (chartTmp[x + coor.first][y + coor.second] == 0) {
                    chartTmp[x + coor.first][y + coor.second] = 2;
                    spreadVirus(x + coor.first, y + coor.second);
                }
            }
        }
    }
}
int cleanArea() {
    int res = 0;
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++)if(chartTmp[i][j] == 0)res++;
    }
    return res;
}
void spreadVirusUtil() {
    for (int i = 0; i < infected.size(); i++) {
        spreadVirus(infected[i].first, infected[i].second);
    }
}
void printChart(){
    for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){cout<<chartTmp[i][j]<<" ";}
    cout<<endl;
    }
}
int main() {
    int N, M;
    cin >> N >> M;//세로 N 가로 M
    for (int i = 0; i < 9; i++)for (int j = 0; j < 9; j++) { chart[i][j] = 1; }
    //1 부터 넣었음
    for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++) {
        cin >> chart[i][j];
        if (chart[i][j] == 2)infected.push_back({ i,j });
        if (chart[i][j] == 0)clean.push_back({ i,j });
    }
    copyChart();
    makeCombinations(0, 0);
    while (!combinations.empty()) {
        int x = combinations.front()[0];
        int y = combinations.front()[1];
        int z = combinations.front()[2];
        combinations.pop();
        //cout << "x,y,z: " << x << " " << y << " " << z << endl;
        //벽 세우기
        chartTmp[clean[x].first][clean[x].second] = 1;
        chartTmp[clean[y].first][clean[y].second] = 1;
        chartTmp[clean[z].first][clean[z].second] = 1;
        //전염
        spreadVirusUtil();
        //빈 칸 계산
        maxCleanArea = max(cleanArea(), maxCleanArea);
        //리셋
        copyChart();
    }
    cout << maxCleanArea;
    return 0;
}