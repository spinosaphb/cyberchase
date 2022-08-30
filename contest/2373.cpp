#include <iostream>
#include <vector>

using namespace std;


int getMaxOfSubMatrix(vector<vector<int>>& grid, int i, int j){
    int max = -1;
    for (int sub_i = 0; sub_i < 3;sub_i++)
        for (int sub_j = 0; sub_j < 3;sub_j++)
            if(grid[sub_i+i][sub_j+j] > max)
                max = grid[sub_i+i][sub_j+j];
    return max;
}

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int N = grid.size() -2;
    vector<vector<int>> maxLocal;
    for(int i = 0; i < N; i++){
        vector<int> row;
        for(int j = 0; j < N; j++)
            row.push_back(getMaxOfSubMatrix(grid, i , j));
        maxLocal.push_back(row);
    }
            
            

    return maxLocal;
}



int main(){
    vector<vector<int>> grid = {
        {9,9,8,1},
        {5,6,2,6},
        {8,2,6,4},
        {6,2,2,2}
    };

    int N = grid.size() -2;

    vector<vector<int>> maxLocal = largestLocal(grid);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << maxLocal[i][j] << " ";
        cout << endl;
    }



    
}