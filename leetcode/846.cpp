class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        /*
        put in a minheap ---- card no., freq
        pop from heap.. and get the car no..., subtract the freq
        for (card...groupSiz(by doing + 1)) [
        sutract the freq from the freq map..if it turns negative return false]
        push to the heap if it still remains

        //problem how do i recocile updaes
        pop the smallest no...
        */
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int,int> mp;
        for (int num: hand) {
            mp[num]++;
        }
        for (auto [key, value] : mp) {
            pq.push(key);
        }

        while (!pq.empty()) {
            int current = pq.top(); pq.pop();
            if (mp.find(current) == mp.end()) continue;
            if (mp[current] > 1) pq.push(current);
            for (int i = 0; i < groupSize; i++) {
                if (mp.find(current + i) != mp.end()) {
                    mp[current + i]--;
                    if (mp[current + i] == 0) mp.erase(current + i);
                } else {
                    return false;
                }
            }


        }
        return true;
 
        
    }
};