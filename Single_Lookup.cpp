/*
Write a program to find frequency of elements in a given array using single lookup hash
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<pair<int, int>> CountFreq_SingleLookup(const vector<int>&nums) {
    
    // 1. Data Structures
    unordered_map<int, int> mp; // Map: stores {element: count}
    vector<int> order;          // Vector: stores unique elements in order of first appearance
    
    // 2. Process the Array and Count Frequencies
    for (int x :nums) {
        
        // mp.insert() returns a pair: {iterator to element, bool indicating if insertion happened}
        // Structured binding unpacks it into named variables:
        auto [it,inserted] = mp.insert({x, 0});
        
        // PART A: Handle Ordering (Use the clear boolean flag)
        if (inserted) {
            // If the element was new (i.e., this is the first time we've seen 'x'), record it.
            order.push_back(x);
        }
        
        // PART B: Handle Counting (Use the iterator to access the value)
        // 'it' points to the key-value pair {x, count} in the map.
        // '->second' accesses the VALUE (the count) of that pair.
        it->second++;
    }
    
    // 3. Assemble the Final Result
    std::vector<std::pair<int, int>> ans;
    for (int x : order) {
        // Look up the final count using the stored unique elements in order.
        ans.emplace_back(x, mp[x]); 
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
    vector<pair<int,int>>result=CountFreq_SingleLookup(nums);
    for(auto &[key,value]:result){
        cout<<key<<"->"<<value<<endl;
    }
    return 0;
}
/*
T(c)=O(n)
S(c)=O(K)
order:first occurence
use: single lookup per element
*/