/*
write a program to count frequency of elements in a given array using counting arrray range
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>>CountArray(vector<int>&nums){
    int minVal=*min_element(nums.begin(),nums.end());
    int maxVal=*max_element(nums.begin(),nums.end());
    int range=maxVal-minVal+1;
    vector<int>freq(range,0);
    for(int x:nums){
        freq[x-minVal]++;
    }
    vector<pair<int,int>>ans;
    for(int x=0;x<range;x++){
        if(freq[x]>0)ans.push_back({x+minVal,freq[x]});
    }
    return ans;
}
int main(){
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<pair<int,int>>answer=CountArray(nums);
    for(auto &[key,value]:answer){
        cout<<key<<"->"<<value<<endl;
    }
}
/*
T(c)=O(n+range)
S(c)=O(range)
order:natuarally sorted
use: when small range integers
*/