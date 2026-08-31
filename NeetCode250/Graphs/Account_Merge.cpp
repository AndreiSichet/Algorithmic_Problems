/*
Accounts Merge:

The important thing is that accounts are connected
through emails.

If two accounts share an email, they belong to
the same person.

Example:

    Account 1:
    john, a, b

    Account 2:
    john, b, c

Because they share b, they must be merged.

The connection can also be indirect:

    Account 1: a, b
    Account 2: b, c
    Account 3: c, d

All three accounts belong to the same person.

Use Union-Find.

Give every unique email an integer ID.

For every account:

    Connect the first email to every other email
    in that account.

Example:

    a, b, c

Create:

    a -- b
    a -- c

After processing all accounts, emails belonging
to the same person will have the same Union-Find root.

Then group emails by their root.

Finally:

    1. Sort the emails in every group.
    2. Put the person's name at the beginning.
    3. Add the sorted emails.

Important:

We use the name from the account while processing
the emails.

The name itself is not used to determine whether
accounts should be merged.

Two people can have the same name.

Time:
    O(N log N)

The sorting of emails dominates the work.

Space:
    O(N)

N = total number of emails.
*/

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) {
            return;
        }
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        }
        else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        }
        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailId;
        unordered_map<string, string> emailName;
        int id = 0;
        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                if (!emailId.count(email)) {
                    emailId[email] = id;
                    emailName[email] = name;
                    id++;
                }
            }
        }
        parent.resize(id);
        rank.resize(id, 0);
        for (int i = 0; i < id; i++) {
            parent[i] = i;
        }
        for (auto& account : accounts) {
            int first = emailId[account[1]];
            for (int i = 2; i < account.size(); i++) {
                int current = emailId[account[i]];
                unite(first, current);
            }
        }
        unordered_map<int, vector<string>> groups;
        for (auto& [email, emailIndex] : emailId) {
            int root = find(emailIndex);
            groups[root].push_back(email);
        }
        vector<vector<string>> result;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.push_back(emailName[emails[0]]);
            for (string email : emails) {
                account.push_back(email);
            }
            result.push_back(account);
        }
        return result;
    }
};