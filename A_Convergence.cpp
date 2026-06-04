#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n,0);
        
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = n-1;
        int mid = n/2;
        int ans = 0;
        while(left<=right){
            if(nums[left]!=nums[mid]||nums[right]!= nums[mid]) ans++;
            left++;
            right--;
        }
        cout<<ans<<endl;


    }
}