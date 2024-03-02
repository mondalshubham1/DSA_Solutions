// Problem Link : https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        sort(arr, arr + n);                          // sort the array first
        int i=0;
        int j=n-1;
        int ans=0;
        
        while(i<j){
            if(arr[i]+arr[j] == k) {                   // Case 1 , where arr[i] + arr[j] = k
                int m=i+1;
                int n=j-1;

                /*
                  Here we have two cases,  
                  Case 1a : i---> x x x x z u n y y y <----j
                  Case 1b : i---> x x x x x x x <----j
                */
              
                while(m<=j && arr[m] == arr[m-1])      // find the right most value with the value arr[i]            
                    m++;
                m--;
                
                while(i<=n && arr[n] == arr[n+1])      // find the left most value with the value arr[j] 
                    n--;
                n++;
                
                if(m<n){
                    ans += (m-i+1)*(j-n+1);            // For Case 1a
                }
                else{                                  // For Case 1b
                    int fact = 1;
                    for(int k=1; k<=j-i ; k++)
                        fact *= k;
                    ans+=fact;
                }
              
                i = m+1;              // final update of new i & j which will hold true for any of the above two cases.
                j = n-1;
            }
            else if(arr[i]+arr[j] > k) {                // Case 2 , where arr[i] + arr[j] > k, means we need to reduce the sum of the pair  arr[i] + arr[j], as the array is sorted, I would reduce the pair sum by j--.
                j--;
            }
            else{                                       // Case 3 , where arr[i] + arr[j] < k, means we need to increase the sum of the pair  arr[i] + arr[j], as the array is sorted, I would increase the pair sum by i++.
                i++;
            }
        }
      
        return ans;
    }
};
