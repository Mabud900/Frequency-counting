//Write a program count frequency of element in a given array using sorting
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int>>Count_sort(vector<int>&nums){
    vector<pair<int,int>>ans;
    if(nums.empty()){
        return ans;
    }
    sort(nums.begin(),nums.end());
    int curr=nums[0],cnt=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==curr){
            cnt++;
        }else{
            ans.push_back({curr,cnt});
            curr=nums[i],cnt=1;
        }
    }
    ans.push_back({curr,cnt});
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number of elements of array: ";
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<pair<int,int>>freq=Count_sort(nums);
    cout<<"frequencies are: "<<endl;
    for(auto &p:freq){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}
/*
Time complexity=O(n*logn)
Space complexity=O(1)
*/