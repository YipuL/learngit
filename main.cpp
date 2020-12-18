//
// Created by piao on 2020/12/17.
//
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string s, char sep)
{
    istringstream iss(s);
    vector<string> res;
    string buffer;
    while(getline(iss, buffer, sep)){
        res.push_back(buffer);
    }
    return res;
}

//int main(){
//    string s = "123 456 789";
//    vector<string> res = split(s, ' ');
//    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";
//    return 0;
//}