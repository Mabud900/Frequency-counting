//write a program to count frequency of elements in a given array using basic hash
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<pair<int,int>>CountFreq_simpleHash(vector<int>&nums){
    unordered_map<int,int>mp;
    for(int x:nums)mp[x]++;
    vector<pair<int,int>>ans;
    ans.reserve(mp.size());
    for(auto &p:mp){
        ans.push_back(p);
    }
        return ans;
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<pair<int,int>>freq=CountFreq_simpleHash(nums);
    for(auto &s:freq){
        cout<<s.first<<"-> "<<s.second<<endl;
    }
    return 0;
}
/*
T(c)=O(n)
S(C)=O(k)
use when order is irrelevant
*/