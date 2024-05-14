// Problem Link : https://codeforces.com/problemset/problem/1972/B

#include<bits/stdc++.h>

using namespace std;

bool solve(int n, string input) {
    int countU = 0;
    for(auto x : input) {
        if(x == 'U')
            countU++;
    }
    if(countU%2)
        return true;
        
    return false;
}

int main() {
    int t;
    cin >> t;

    while(t>0){
        int n;
        string input;
        cin >> n;
        cin >> input;
        if (solve(n, input))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        t--;
    }
}