// Problem Link : https://codeforces.com/problemset/problem/1972/A

#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t>0) {
        int n;
        cin >> n;
        vector<int> a(n,0);
        vector<int> b(n,0);

        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<n; i++)
            cin >> b[i];

        int i=0;
        while(i<n) {
            bool isAns = true;
            for(int k=i; k<n; k++){
                if(a[k-i]>b[k])
                    isAns = false;
            }
            if(isAns) 
                break;

            i++;   
        }
        cout << i << endl;
        t--;
    }
}