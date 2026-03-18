#include <bits/stdc++.h>
using namespace std;

int solve(){
    int arr[]={1,6,11,5};
    int n=4;
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0) t[i][j]=false;
            if(j==0) t[i][j]=true;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    int m=INT_MAX;
    {
        for(int j=0;j<sum+1;j++){
            if(t[n][j]==1)
            m=min(m,abs(sum-2*j));
        }
    }
    return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    {
       cout<<solve()<<endl;
    }
    return 0;
}