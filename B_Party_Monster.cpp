#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int count = 0;
        for(int i=0;i<x;i++){
            char ch;
            cin>>ch;
            if(ch=='(')count++;
            else count--;
        }
        if(count==0)  cout<<"YES"<<endl;
        else  cout<<"NO"<<endl;
    }
    return 0;
}