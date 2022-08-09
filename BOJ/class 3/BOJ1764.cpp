#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, range = 0;
    cin >> n >> m;
    range = n + m;
    
    vector<string> list;
    
    for (int i = 0; i < range; i++){
        string temp;
        cin >> temp;
        list.push_back(temp);
    }
    
    sort(list.begin(), list.end());
    
    int cnt = 0;
    vector<string> ans;
    
    for (int i = 0; i < range - 1; i++){
        if (list[i] == list[i+1]){
            ++cnt;
            ans.push_back(list[i]);
        }
    }
    
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++){
        cout << ans[i] << "\n";
    }
    
    return 0;
}
