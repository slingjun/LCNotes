# 1535. Find the Winner of an Array Game

Careful: No
Date: January 31, 2024
Difficulty: Medium
Index: 1535
Programming Language: C++
Tags: Queue
Link: https://leetcode.com/problems/find-the-winner-of-an-array-game/

```cpp
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int top = arr[0], max_v = top;
        deque<int> dq;
        for(int i = 1; i < arr.size(); ++i) {
            dq.push_back(arr[i]);
            max_v = max(max_v, arr[i]);
        }
        
        unordered_map<int, int> win_count;
        bool end = false;
        while(!end) {
            int next = dq.front();
            if(top > next) {
                win_count[top]++;
                dq.pop_front();
                dq.push_back(next);
            } else {
                win_count[next]++;
                dq.pop_front();
                dq.push_back(top);
                top = next;
            }
            // pruning
            if(win_count[top] >= k || top == max_v) end=true;
        }
        return top;
    }
};
```