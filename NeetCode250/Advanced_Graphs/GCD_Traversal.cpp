
/*
Problem:

Determine whether every index in nums can reach every other index.

Two numbers are directly connected if their gcd is greater than 1.

Key idea:

Two numbers have gcd > 1 exactly when they share
at least one prime factor.

Instead of checking every pair of numbers, connect
indices that share a prime factor using DSU.

For each prime factor:
    - Remember the first index containing that factor.
    - If another number contains the same factor,
      unite the two indices.

Example:

nums = [6, 35, 10]

6  = 2 * 3
35 = 5 * 7
10 = 2 * 5

Connections:

6 and 10 share factor 2.
35 and 10 share factor 5.

So:

0 ---- 2 ---- 1

All indices belong to one component.

Special case:

1 has no prime factor and gcd(1, x) = 1 for every x.

Therefore, if nums contains 1 and has more than one element,
the answer is false.

Time:
    O(n * sqrt(max(nums)))

Space:
    O(n + max(nums))
*/

class Solution {
public:
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }

            return parent[x];
        }
        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return;
            }
            if (rank[a] < rank[b]) {
                swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    };
    vector<int> getFactors(int x) {
        vector<int> factors;
        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                factors.push_back(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (x > 1) {
            factors.push_back(x);
        }
        return factors;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return true;
        }
        for (int num : nums) {
            if (num == 1) {
                return false;
            }
        }
        DSU dsu(n);
        unordered_map<int, int> factorOwner;
        for (int i = 0; i < n; i++) {
            vector<int> factors = getFactors(nums[i]);
            for (int factor : factors) {
                if (factorOwner.count(factor)) {
                    dsu.unite(i, factorOwner[factor]);
                }
                else {
                    factorOwner[factor] = i;
                }
            }
        }
        int root = dsu.find(0);
        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root) {
                return false;
            }
        }
        return true;
    }
};
