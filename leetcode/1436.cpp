class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        for(int i = 0; i < paths.size(); i++) {
            vector<string> path = paths[i];
            mp[path[0]]++;
            if (mp.find(path[1]) == mp.end()) mp[path[1]] = 0;
        }
        for (auto [key, value] : mp) {
            if (value == 0) return key;
        }
        return "";

        
    }
};