#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n, m;
    cin >> n >> m;
    
    map<string, int> dic; //시간초과 문제 해결 위해 hash map 사용, 포켓몬 이름에 맞는 인덱스를 저장하기 위한 배열
    vector<string> name; //인덱스에 맞는 포켓몬 이름을 저장하기 위한 배열
    
    for (int i = 1; i <= n; i++){
        string tmpName;
        cin >> tmpName;
        
        dic.insert(make_pair(tmpName, i));
        name.push_back(tmpName);
    }
    
    vector<string> ans;
    
    for (int i = 0; i < m; i++){
        string temp;
        cin >> temp;
        
        if (temp[0] >= 65 && temp[0] <= 90){
            ans.push_back(to_string(dic[temp]));
        }
        else{
            int index = stoi(temp) - 1;
            ans.push_back(name[index]);
        }
    }
    
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }
    
    return 0;
}
