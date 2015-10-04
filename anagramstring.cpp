nclude <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> allstrings;
        for (int i = 0; i != strs.size(); i++){
            string temp =  strs[i];
            sort(temp.begin(),temp.end());
            if (allstrings.find(temp) == allstrings.end()){
                vector<int> tempvector;
                tempvector.push_back(i);
                allstrings[temp] = tempvector;
            }
            else{
                allstrings[temp].push_back(i);
            }
        }
        vector<vector<string>> result;
        for (auto it = allstrings.begin(); it != allstrings.end(); it++){
            
            vector<string> tempresult;
            for (auto i = it->second.begin(); i != it->second.end(); i++){
                tempresult.push_back(strs[*i]);
            }
            
            sort(tempresult.begin(), tempresult.end());
            result.push_back(tempresult);
        }
        return result;
    }


int main(){
    vector<string> strs;
    strs.push_back("a");
    vector<vector<string>> result = groupAnagrams(strs);
    return 0;
}
