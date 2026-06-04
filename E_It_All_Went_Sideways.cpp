#include<iostream>
#include<vector>
using namespace std;
long long solve1(vector<long long>& v){
    int n = v.size();
    vector<long long> suff(n,0);
    suff[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--){
        suff[i] = min(suff[i+1],v[i]);
    }
    long long ans = 0;
    for(int i=0;i<n;i++){//agla vala chota hoga tabhi movement hoga
        ans += (v[i] - suff[i]);
    }
    long long curr = 1;
    long long mx  = 1;
    for(int i=1;i<n;i++){
        if(suff[i]==suff[i-1]){
            curr++;
            mx = max(curr,mx);
        }
        else curr = 1;
    }
    ans += (mx-1);
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cout<<solve1(v)<<endl;
    }
}