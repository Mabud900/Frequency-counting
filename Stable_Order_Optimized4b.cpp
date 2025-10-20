//write a program to count frequency of elements in a given array using stable order hash map
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<pair<int,int>>CountFreq_StableOrder_Optimized(vector<int>&nums){
    unordered_map<int,int>mp;
    vector<int>order;
    order.reserve(nums.size());
    for(int x:nums){
        if(mp.find(x)==mp.end()){
            order.push_back(x);
        }mp[x]++;
    }
    vector<pair<int,int>>ans;
    for(int x:order){
        ans.emplace_back(x,mp[x]);
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
    vector<pair<int,int>>freq=CountFreq_StableOrder_Optimized(nums);
    for(auto &[key,value]:freq){
        cout<<key<<"->"<<value<<endl;
    }
    return 0;
}
/*
Time complexity= O(n)
S(c)=O(k)
*/