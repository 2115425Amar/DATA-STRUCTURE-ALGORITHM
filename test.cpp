#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    //n=4
    for(int i=0; i<=n; i++){
       for(int j=0; j<i; j++){
        cout<<" ";
    }
    int k=1;
    for(int j=i; j<2*n - i-1; j++ ){
        cout<<k;
        k++;
    }
    cout<<endl;
    }
    return 0;
}