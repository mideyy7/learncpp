class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        /*
        uterate throhj the enitre array
        update the max if it is less than or equal to tarket else leace it
        at the end it shoyld be less than ior wqual to target

        */
        vector<int> temp(3, INT_MIN);
        for (int i = 0; i < triplets.size(); i++) {
            vector<int> curr = triplets[i];
            if (curr[0] > target[0] || curr[1] > target[1] || curr[2] > target[2]) continue;
            for (int j = 0; j < 3; j++) {
                temp[j] = max(temp[j], curr[j]);  
            }
        }
        return (temp == target);
        
    }
};