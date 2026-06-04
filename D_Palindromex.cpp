#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

long long findMex(vector<long long>& v,long long idx1,long long idx2){

    unordered_map<long long,long long> mp;

    for(int i=idx1;i<=idx2;i++){
        mp[v[i]] = 1;
    }

    int mex = 0;

    while(mp.find(mex)!=mp.end()){
        mex++;
    }

    return mex;
}

pair<long long,long long> getPalindrome(
    vector<long long>& v,
    long long left,
    long long right
){

    int n = v.size();

    while(left>=0 && right<n){

        if(v[left]==v[right]){
            left--;
            right++;
        }
        else{
            break;
        }
    }

    return {left+1,right-1};
}

bool isPalindrome(vector<long long>& v,long long left,long long right){

    while(left<=right){

        if(v[left]!=v[right]){
            return false;
        }

        left++;
        right--;
    }

    return true;
}

long long ans(vector<long long>& v){

    int n = v.size();

    vector<int> zeroPos;

    for(int i=0;i<n;i++){

        if(v[i]==0){
            zeroPos.push_back(i);
        }
    }

    int firstZero = zeroPos[0];
    int secondZero = zeroPos[1];

    long long mx = 1;

    // palindrome around first zero
    pair<long long,long long> p1 =
        getPalindrome(v,firstZero-1,firstZero+1);

    mx = max(mx,findMex(v,p1.first,p1.second));

    // palindrome around second zero
    pair<long long,long long> p2 =
        getPalindrome(v,secondZero-1,secondZero+1);

    mx = max(mx,findMex(v,p2.first,p2.second));

    // palindrome between zeros
    if(isPalindrome(v,firstZero+1,secondZero-1)){
        pair<long long,long long> p =
        getPalindrome(v,firstZero-1,secondZero+1);
        mx = max(mx,findMex(v,p.first,p.second));
    }

    return mx;
}

int main(){

    long long t;
    cin>>t;

    while(t--){

        long long n;
        cin>>n;

        vector<long long> v(2*n);

        for(int i=0;i<2*n;i++){
            cin>>v[i];
        }

        cout<<ans(v)<<endl;
    }
}