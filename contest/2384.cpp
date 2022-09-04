#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string largestPalindromic(string num) {

    vector<int> numbers;
    for(auto number: num)
        numbers.push_back(int(number)-48);

    sort(numbers.begin(), numbers.end());

    string strLeft = "";
    string strRight = "";
    int strCenter = -1;

    for(int i = 0; i < numbers.size(); i++){
        cout << "i = " << i << endl;
        cout << "number[i] = " << numbers[i] << "   number[i+1] = " << numbers[i+1] << endl;
        cout << strLeft << " " << strCenter << " " << strRight << endl;

        if((i+1 >= numbers.size() || numbers[i] != numbers[i+1] ) && numbers[i] > strCenter){
            strCenter = numbers[i];
            continue;
        }

        strLeft = to_string(numbers[i]) + strLeft;
        strRight += to_string(numbers[i+1]);
        i++;
    }

    int j = 0;
    while(strLeft[j] == '0'){
        j++;
    }

    string str = "";
    string newLeft = "";
    string newRight = "";
    for(; j < strLeft.size(); j++){
        newLeft += strLeft[j];
        newRight = strRight[strRight.size()-j-1] + newRight;
    }

    string resposta = newLeft + (strCenter != -1 ? to_string(strCenter) : "") + newRight;
    return resposta=="" ? "0" : resposta;
}

int main(){
    num = "4846375"
    cout << largestPalindromic(num) << endl;
    return 0;
}