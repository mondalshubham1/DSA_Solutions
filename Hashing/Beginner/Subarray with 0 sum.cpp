// Problem Link : https://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> sum_set;
        int sum=0;
        sum_set.insert(0);
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum_set.find(sum) != sum_set.end()){
                return true;
            }
            else {
                sum_set.insert(sum);
            }
        }
        return false;
    }
};
