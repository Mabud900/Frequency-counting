//write a program to find frequenciy of elements in a given array using stable order hash map
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<pair<int,int>>CountFreq_Stable_order(vector<int>&nums){
    unordered_map<int,int>mp;
    vector<int>order;
    for(int x:nums){
        if(mp.find(x)==mp.end())order.push_back(x);
        mp[x]++;
    }
    vector<pair<int,int>>ans;
    for(int x:order){
        ans.push_back({x,mp[x]});
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
    vector<pair<int,int>>achha=CountFreq_Stable_order(nums);
    for(auto &p:achha){
        cout<<p.first<<"->"<<p.second<<endl;
    }
    return 0;
}