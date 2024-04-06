// Problem Link : https://www.interviewbit.com/problems/seats/

int Solution::seats(string A) {
    vector<int> index_vector;
    int total_x = 0;
    for(int i=0; i<A.length(); i++) { 
        if(A[i]=='x'){
            index_vector.push_back(i);
            total_x++;
        }      
    }
    
    int n = index_vector.size();
    if(n==0)
        return 0;
    int median;
    
    median = (index_vector[n/2]+index_vector[(n-1)/2])/2;                              // Find the median of all the positions where people are seated, all people should moved towards that median index.
    
    int ans=0;
    int left_x=0;
    for(int i=0; i<A.length(); i++) {                       
        if(A[i] == 'x')
            left_x++;
        else {                                                                         
            if(i<=median)
                ans=(ans+left_x)%10000003;         // For each vacant seat, if that vacant seat index is less than median then we'll have to take all the people from left to one place right.                                       
            else{
                ans=(ans+total_x-left_x)%10000003; // For each vacant seat, if that vacant seat index is greater than median then we'll have to take all the people from right to one place left.
            }
                
        }
    }
    return ans;
}
 
