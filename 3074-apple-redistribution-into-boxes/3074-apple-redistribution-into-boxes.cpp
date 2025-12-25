class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(apple.begin(), apple.end(), 0);

        sort(capacity.begin(), capacity.end(), greater<int>());
        
        int ans = 0;
        for (int cap : capacity) {
            total -= cap;
            ans++;
            if (total <= 0) break;
        }
        return ans;
    }
};
