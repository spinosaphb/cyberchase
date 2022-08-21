#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional> 
using namespace std;


string smallestNumber(string pattern) {
    int vet[pattern.length()+1];
    string res="";
    for(int i=0; i<pattern.length()+1; i++)
        vet[i]=i+1;

    std::priority_queue<int, std::vector<int>, std::greater<int> > nums(vet,vet+pattern.length()+1);
    
    for(int i=0; i<pattern.length(); i++){
        
        if(pattern[i]=='I'){
            res+=to_string(nums.top());
            nums.pop();
        }
        if(pattern[i]=='D'){
            int j=i;
            int cont=0;
            while (pattern[j]=='D'){
                cont+=1;
                j+=1;
            }
            //auto copia = nums;
            vector<int> aux;
            for(int k=0; k<cont; k++){
                aux.push_back(nums.top());
                
                nums.pop();
            }
               
            res+=to_string(nums.top());
            nums.pop();

            for(int k=0; k<cont; k++){
                nums.emplace(aux[k]);
            }  
        }       
        
    }
    res+=to_string(nums.top());
    
    return res;
}
int main(){
    string a="IIIDIDDD";
    cout << smallestNumber(a);
}
