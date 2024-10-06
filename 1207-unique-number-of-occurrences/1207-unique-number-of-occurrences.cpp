class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
     
        unordered_map<int,int>m;
       for (int num : arr) {
            m[num]++;
        }

        unordered_set<int> s;

        // Check if frequencies are unique
        for (const auto& it : m) {
            int freq = it.second;
            // If the frequency is already in the set, return false
            if (s.find(freq) != s.end()) {
                return false;
            }
            s.insert(freq); // Add frequency to the set
        }

        return true; // 
    }
};