#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    
    int pos[N];
    map<int,vector<int>> colors;

    for(int i = 0; i < N; i++){
        int num, color;
        cin >> num >> color;
        colors[color].push_back(num);
        pos[i] = color;
    }

    for(auto& color: colors)
        sort(color.second.begin(), color.second.end());
    
    bool firstIt = true;
    bool isSorted = true;

    for(auto& color: colors){
        cout << color.first << endl;
        for(auto& c: color.second){
            cout << c << " ";
        }
        cout << endl;
    }
        

    for(int j = N-1; j >= 0 ; j--){
        pos[j] = *colors[pos[j]].end();
        if(!firstIt && pos[j] > pos[j+1]){
            isSorted = false;
            break;
        }
        firstIt = false;
        colors[pos[j]].pop_back();
    }

    if(isSorted)
        cout << 'Y' << endl;
    else
        cout << 'N' << endl;

}