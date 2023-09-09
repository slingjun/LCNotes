// Date: September 9, 2023
class Solution {
public:
    bool isMatched(unordered_map<char, int>& need) {
        for(auto it = need.begin(); it!=need.end(); ++it) {
            if(it->second > 0) return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        for(char ch: t) need[ch]++;
        int left = 0, min_len = s.size()+1, min_left = 0;
        for(int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if(need.count(ch)) need[ch]--;
            if(!isMatched(need)) continue;
            while(left <= i) {
                if(i-left+1 < min_len) {
                    min_len = i-left+1;
                    min_left = left;
                }
                char left_ch = s[left];
                if(!need.count(left_ch)) left++;
                else {
                    if(need[left_ch] < 0) {
                        need[left_ch]++;
                        left++;
                    } else {
                        break;
                    }
                }
                
            }
        }
        return min_len > s.size() ? "" : s.substr(min_left, min_len);
    }
};
