class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                if (!five)
                    return 0;
                else {
                    ten++;
                    five--;
                }
            } else {
                if (five && ten) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else
                    return 0;
            }
        }
        return 1;
    }
};