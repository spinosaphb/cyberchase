#include <iostream>
#include <map>
#include <vector>

using namespace std;

int edgeScore(vector<int>& edges) {
    map<int, long int> score;

    for(int i=0; i<edges.size(); i++){
        if(score[edges[i]]==NULL)
            score[edges[i]]=0;
        score[edges[i]]+=i;
    }
    int node_max;
    int max = -1;
    for(auto s : score){
        if(s.second > max){
            max = s.second;
            node_max = s.first;
        }
    }
    return node_max;
}

int main(){
    vector<int> edges = {1,0,0,0,0,7,7,5};

    int res = edgeScore(edges);

    cout << res;
}