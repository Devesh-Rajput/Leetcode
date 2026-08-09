class Solution {
public:
    int maximumSum(vector<int>& a) {
        int noDel = a[0];
        int oneDel = INT_MIN;
        int ans = a[0];

        for (int i = 1; i < a.size(); i++) {
            int prevNoDel = noDel;
            int prevOneDel = oneDel;

            noDel = max(a[i], prevNoDel + a[i]);

            oneDel = max(prevNoDel, prevOneDel == INT_MIN
                                      ? a[i]
                                      : prevOneDel + a[i]);

            ans = max(ans, max(noDel, oneDel));
        }

        return ans;
    }
};