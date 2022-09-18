#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

vector<string> readBinaryWatch(int turnedOn) {

    vector<string> bin;
    string str;

    array<int, 10> arr{1, 2, 4, 8, 1, 2, 4, 8, 16, 32};

    // 1, 2, 4, 8, 1, 2, 4, 8, 16, 32
    // 1, 1, 0, 0, 0, 0, 0, 0, 0, 0

    string bitmask(turnedOn, 1);
    bitmask.resize(arr.size(), 0);

    int min = 0, hours = 0;
 
    do {
        for (int i = 0; i < arr.size(); ++i) {
            if(bitmask[i] && i <= 3) hours += arr[i];
            if(bitmask[i] && i > 3) min += arr[i];
            cout << bitmask[i] << " " << endl;
        }
        if(hours < 12 && min < 60){
            str = to_string(hours) + ":" + (to_string(min).size() == 1 ? "0" + to_string(min) : to_string(min));
            bin.push_back(str);
        }
        min = 0, hours = 0;

    } while(prev_permutation(bitmask.begin(), bitmask.end()));

    return bin;
}
 
int main()
{
    vector<string> vec = readBinaryWatch(1);

    for(auto & i : vec){
        cout << " " << i;
    }
    return 0;
}
