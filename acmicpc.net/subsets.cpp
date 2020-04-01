#include <bits/stdc++.h> 
using namespace std; 

int subsets(vector<int>& A, vector<vector<int>>& save, 
                 vector<int>& currentSet, int k) 
{ 
    save.push_back(currentSet); 
    for (int i = k; i < A.size(); i++) { 
        currentSet.push_back(A[i]); // 원소 포함 
        subsets(A, save, currentSet, i+1); 
        currentSet.pop_back(); // 원소 제외
    } 
  
    return 0; 
} 

int main(){
    vector<int> input =  {1,2,3,4,5};
    vector<vector<int>> save;
    vector<int> subset;
    subsets(input,save,subset,0);
    for (int i = 0; i < save.size(); i++) { 
        for (int j = 0; j < save[i].size(); j++) 
            cout << save[i][j] << " "; 
        cout << endl; 
    } 
}