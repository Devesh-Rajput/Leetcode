class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1)
            return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    int reverseNumber(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    int sumOfPrimesInRange(int n) {
        int temp = n;
        int r = reverseNumber(temp);
        int start = min(temp, r);
        int end = max(temp, r);
        int sum = 0;

        for (int i = start; i <= end; i++) {
            if (isPrime(i))
                sum += i;
        }

        return sum;
    }
};