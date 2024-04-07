// Problem Link : https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.

    // Greedy approach is to do the most valuable job as close as possible to the deadline. This way, for any deadline we'll be able to do the most profitable job possible.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        Job job;
        int deadline, profit, max_deadline;
        vector<pair<int, int>> profit_deadline;
        
        for(int i=0; i<n; i++) {
            job = arr[i];
            deadline = job.dead; profit = job.profit;
            profit_deadline.push_back(make_pair(profit, deadline));
            max_deadline = max(max_deadline, deadline);
        }
        
        sort(profit_deadline.rbegin(), profit_deadline.rend());
 
        int num_jobs=0;
        int total_profit=0;
        vector<int> assigned(max_deadline+1, 0);
        
        for(auto x: profit_deadline) {
            deadline = x.second; profit = x.first;
            
            for(int d=deadline; d>0 ; d--){
                if(assigned[d]==0){
                    assigned[d] = 1;
                    num_jobs++;
                    total_profit+=profit;
                    break;
                }    
            }
        }
    
        vector<int> ans;
        ans.push_back(num_jobs);
        ans.push_back(total_profit);
        
        return ans;
    } 
};
