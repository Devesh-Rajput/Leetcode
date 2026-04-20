class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i=0,j=colors.size()-1;
        int ans=INT_MIN;
        while(colors[i]==colors[j]){
            i++;
        }
        ans=max(ans,abs(j-i));
        i=0, j=colors.size()-1;
        while(colors[i]==colors[j]){
            j--;
        }
        ans=max(ans,abs(j-i));
        return ans;
    }
};