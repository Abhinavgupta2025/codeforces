#include<iostream>
#include<vector>
using namespace std;
void solve(vector<long long>& a,vector<long long>& ans){
        for(auto it : a){
            ans.push_back(it);
        }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> six;
        vector<long long> twos;
        vector<long long> threes;
        vector<long long> others;
        vector<long long> ans;
        vector<long long> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]%6==0) six.push_back(v[i]);
            else if(v[i]%2==0) twos.push_back(v[i]);
            else if(v[i]%3==0) threes.push_back(v[i]);
            else others.push_back(v[i]);
        }
        solve(six,ans);
        solve(twos,ans);
        solve(others,ans);
        solve(threes,ans);
        for(auto it : ans){
            cout<<it<<" ";
    }
        cout<<endl;
    }
}