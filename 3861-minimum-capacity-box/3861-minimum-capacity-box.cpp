class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minIndex = -1;

        for(int i = 0; i < capacity.size(); i++){
            if(capacity[i] >= itemSize){
                if(minIndex == -1 || capacity[i] < capacity[minIndex]){
                    minIndex = i;
                }
            }
        }

        return minIndex;
    }
};