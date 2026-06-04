#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long solve1(vector<long long>& v){
    int n = v.size();
    vector<long long> arr(v.begin(),v.end());
    sort(arr.begin(),arr.end());
    long long ans = 0;
    long long carry = 0;
    for(int i=0;i<n;i++){
        long long diff = carry + v[i]-arr[i];
        ans += diff;
        carry = diff;
    }

    long long mx = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>=v[i]){
            long long x = lower_bound(arr.begin(),arr.end(),v[i])-arr.begin();
            long long cnt = i-x;
            mx = max(mx,cnt);
        }
    }
    ans += mx;
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