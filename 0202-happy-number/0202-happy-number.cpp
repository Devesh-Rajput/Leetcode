class Solution {
    int square(int x) {
        int sum = 0;
        while (x > 0) {
            int digit = x % 10;
            x /= 10;
            sum += (digit * digit);
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            slow = square(slow);
            fast = square(square(fast));
            if (fast == 1)
                return 1;
            if (slow == fast)
                return 0;
        }
        return 1;
    }
};