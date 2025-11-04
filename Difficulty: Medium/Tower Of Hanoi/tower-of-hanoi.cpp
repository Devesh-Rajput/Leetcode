class Solution {
  public:
    long long towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 0)
            return 0;

        long long moves = towerOfHanoi(n - 1, from, aux, to);

        moves++;

        moves += towerOfHanoi(n - 1, aux, to, from);

        return moves;
    }
};
