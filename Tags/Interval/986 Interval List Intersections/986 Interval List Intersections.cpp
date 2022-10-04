// Date: October 4, 2022
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& l1, vector<vector<int>>& l2) {
        int left = 0, right = 0;
        vector<vector<int>> res;
        while (left < l1.size() && right < l2.size()) {
            auto e1 = l1[left], e2 = l2[right];
            if (e2[0] <= e1[1] && e2[1] >= e1[0]) {  // overlap
                res.push_back({max(e1[0], e2[0]), min(e1[1], e2[1])});
            }
            if (e1[1] <= e2[1]) left++;
            else right++;
        }
        return res;
    }
};
