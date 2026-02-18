class disJointSet {
    vector<int> rank, parent;

public:
    disJointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUP(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findUP(parent[x]);
    }

    void unionByRank(int u, int v) {
        int up_u = findUP(u);
        int up_v = findUP(v);
        if (up_u == up_v)
            return;

        if (rank[up_u] < rank[up_v]) {
            parent[up_u] = up_v;
        } else if (rank[up_v] < rank[up_u]) {
            parent[up_v] = up_u;
        } else {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        disJointSet ds(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (ds.findUP(u) == ds.findUP(v)) {
                return e;
            }
            ds.unionByRank(u, v);
        }
        return {};
    }
};
