// Problem Link : https://leetcode.com/problems/check-if-it-is-a-straight-line/description/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int old_num = coordinates[1][1]-coordinates[0][1];
        int old_den = coordinates[1][0]-coordinates[0][0];
        for(int i=1; i<coordinates.size()-1; i++) {
            int new_num = coordinates[i+1][1]-coordinates[i][1];
            int new_den = coordinates[i+1][0]-coordinates[i][0];

            if(old_num*new_den != old_den*new_num)       // We won't be directly comparing the slopes as float comparisons can give to erroneous results
                return false;
        }
        return true;
    }
};