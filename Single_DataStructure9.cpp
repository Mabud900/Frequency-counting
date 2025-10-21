#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// Function to count frequencies of elements in a given array,
// returning them in the order of their first appearance.
vector<pair<int,int>> CountFreq_Single_DataStructure(vector<int>&nums) {
    vector<pair<int,int>> result; // Stores {element, count} in first-appearance order
    unordered_map<int,int> pos;    // Maps element -> its index in the 'result' vector

    for (int x : nums) {
        // Try to find the element 'x' in the 'pos' map
        auto it = pos.find(x);

        if (it == pos.end()) {
            // If 'x' is not found (first occurrence):
            // 1. Store its current position (index) in 'result' map
            pos[x] = result.size();
            // 2. Add the element to 'result' with an initial count of 1
            result.emplace_back(x, 1);
        } else {
            // If 'x' is found (subsequent occurrence):
            // Increment the count of the pair at the stored index in 'result'
            result[it->second].second++;
        }
    }
    return result;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<pair<int,int>>ans = CountFreq_Single_DataStructure(nums);
    cout << "Frequencies in order of first appearance:" << endl;
    for(auto &[key,value]: ans){
        cout<<key<<" -> "<<value<<endl;
    }
    return 0;
}

/*
T(C)=O(n) - Average time complexity, as hash map operations are O(1) on average.
S(C)=O(k) - Space complexity, where 'k' is the number of unique elements.
Order: first occurence - The 'result' vector maintains this.
Benefit: Minimal data structure usage - Achieves both counting and ordering with a map and a vector where the map stores indices into the vector.
*/