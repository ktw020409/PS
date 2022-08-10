#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> meeting;
    for (int i = 0; i < n; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        
        meeting.push_back(make_pair(temp2, temp1));
    }
    
    sort(meeting.begin(), meeting.end());
    
    int ans = 1;
    int end = meeting[0].first;
    
    for (int i = 1; i < n; i++){
        if (end <= meeting[i].second){
            ++ans;
            end = meeting[i].first;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
