/*
Write a program to count the frequencies of characters of a string using hash table
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<pair<char,int>>Count_String_Freq(const string &str){
    unordered_map<char,int>mp;
    for(char c:str)mp[c]++;
    vector<pair<char,int>>ans;
    ans.reserve(mp.size());
    for(auto &p:mp)ans.emplace_back(p);
    return ans;
}
int main(){
    string str;
    cout<<"Enter string: ";
    cin>>str;
    auto ans=Count_String_Freq(str);
    for(auto &[key,value]:ans){
        cout<<key<<"->"<<value<<endl;
    }

}
/*
T(c)=O(n)
S(c)=O(K)
Order: arbitrary(random)
Use: when character counting
*/