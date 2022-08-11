#include <iostream>
#include <math.h>
using namespace std;

int n, r, c;
int ans;

void divide(int size, int y, int x){
    if (y == r && x == c){
        cout << ans << "\n";
        return;
    }
    else if (y <= r && r < y + size && x <= c && c < x + size){
        divide(size/2, y, x);
        divide(size/2, y, x + size/2);
        divide(size/2, y + size/2, x);
        divide(size/2, y + size/2, x + size/2);
    }
    else{
        ans += size * size;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    cin >> n >> r >> c;
    
    divide(pow(2, n), 0, 0);
    
    return 0;
}
