#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> createPermutation(string A, char pivo){
    vector<string> vec;
    for(int i = 0; i < A.length(); i++){
        if(A[i] != pivo)
            continue;
        string permut;
        for(int k = i; k < A.length(); k++){
            permut += A[k];
        }
        for(int j = 0; j < i; j++){
            permut += A[j];
        }
        vec.push_back(permut);
    }
    return vec;
}

bool findSubstring(string perm, string si){
    for(int i = 0; i < si.length(); i++){
        if(si.at(i) != perm.at(i))
            return false;
    }
    return true;
}

int main() {
    int N, M, bestPunct = 0;
    string A;
    vector<string> S;
    vector<string> B;
    map<char,vector<string>> init;
    
    // init['A'] = S;
    // if(init.find('A') == init.end()) cout << 1 << endl;

    cin >> N >> M;
    cin >> A;

    for(int i = 0; i < M; i++){
        string str;
        cin >> str;
        S.push_back(str);
    }

    for(auto i: S){
        if( (bestPunct && i.length() > bestPunct) || i.length() > A.length() ){
            continue;
        }
        if( init.find(i.at(0)) == init.end() ){
            init[i.at(0)] = createPermutation(A, i.at(0));
        }
        for(auto perm: init.at(i[0])){
            if( findSubstring(perm, i) ){
                bestPunct = i.size();
            }
        }
    }

    cout << bestPunct << endl;

    // pegar o primeiro char da string i
    // procurar as ocorrencias de i em A
    // gerar as Bis, fatiar e armazenar em B
    // armazenar a menor na variável "pont"
    

    return 0;
}