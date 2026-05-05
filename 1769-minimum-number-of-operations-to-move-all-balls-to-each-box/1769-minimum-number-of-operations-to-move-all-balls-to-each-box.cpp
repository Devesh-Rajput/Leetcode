class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int> answer(n, 0);

        int value = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            answer[i] = sum;
            value += boxes[i] == '0' ? 0 : 1;
            sum += value;
        }

        value = 0;
        sum = 0;

        for (int i = n - 1; i >= 0; i--) {
            answer[i] += sum;
            value += boxes[i] == '0' ? 0 : 1;
            sum += value;
        }
        return answer;
    }
};