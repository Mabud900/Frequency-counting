#include <bits/stdc++.h>
using namespace std;

/*
 Returns a vector of pairs (value, count).
 If preserveOrder == true, the pairs are in the order of first occurrence in `arr`.
 If preserveOrder == false, the pairs follow the (unspecified) iteration order of unordered_map
   unless sortByKey == true, in which case the result is sorted by key.
 If sortByKey == true, the result is sorted by the key (ascending).
*/
vector<pair<int,int>> frequencyCount(const vector<int>& arr,bool preserveOrder = true,bool sortByKey = false) {                                
    unordered_map<int,int> mp;
    vector<int> order;
    order.reserve(arr.size());

    // Count frequencies and record first-seen order
    for (int x : arr) {
        if (mp.find(x) == mp.end()) {
            order.push_back(x);      // record first occurrence
            mp[x] = 1;
        } else {
            ++mp[x];
        }
    }

    // Build answer
    vector<pair<int,int>> ans;
    ans.reserve(mp.size());

    if (preserveOrder) {
        for (int x : order) ans.emplace_back(x, mp[x]);
    } else {
        for (auto &p : mp) ans.emplace_back(p.first, p.second);
    }

    if (sortByKey) sort(ans.begin(), ans.end(),
                        [](const pair<int,int>& a, const pair<int,int>& b){
                            return a.first < b.first;
                        });

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin>>n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "\nOptional output format flags:" << endl;
    cout << "1. Preserve order (1 for yes, 0 for no): ";
    int presFlag;
    cin >> presFlag;
    
    cout << "2. Sort by key (1 for yes, 0 for no): ";
    int sortFlag;
    cin >> sortFlag;
    
    cout << "\nCalculating frequencies..." << endl;
    auto result = frequencyCount(arr, presFlag != 0, sortFlag != 0);

    cout << "\nFrequency results (value count):" << endl;
    for (auto &[key,value] : result) {
        cout << key <<"->"<< value << '\n';
    }

    return 0;
}
/*
T(C)=O(n)+O(k logk)
S(C)=O(k)
*/