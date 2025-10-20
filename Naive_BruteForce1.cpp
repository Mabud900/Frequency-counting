//Write a program to count frequency of element in a given array using double loop
#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>>CountNaive(const vector<int>&arr){
    int n=arr.size();
    vector<bool>seen(n,false);\
    vector<pair<int,int>>result;
    for(int i=0;i<n;i++){
        if(seen[i]==true){
            continue;//skip if already visited
        }
        
        int count=1;
        for(int j=i+1;j<n;j++){
            if(arr[j]==arr[i]){
                count++;
                seen[j]=true;
            }
        }result.push_back({arr[i],count});
    }
    return result;
}
int main(){
    int n;
    cout<<"enter the number of elements of arr: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<pair<int,int>>freq=CountNaive(arr);
    for(auto &f:freq){
        cout<<f.first<<"->"<<f.second<<endl;;
    }
}
/*
Time complexity=O(n^2)
space complexity=O(n)
Order= first occurence
*/