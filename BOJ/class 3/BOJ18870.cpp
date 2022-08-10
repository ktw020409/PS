#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    int n;
    cin >> n;
    
    vector<int> num;
    vector<int> sorted;
    
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
        sorted.push_back(temp);
    }
    
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    for (int i = 0; i < n; i++){
        cout << lower_bound(sorted.begin(), sorted.end(), num[i]) - sorted.begin() << " ";
    }
    
    return 0;
}
