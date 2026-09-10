#include <bits/stdc++.h>
using namespace std;

// Calculates the distance/depth of every node from the root node
void fun(int node, vector<vector<int>>& adj, vector<int>& dist) {

    // {distance from root, node}
    queue<pair<int,int>> q;

    // Start BFS from 'node' (root = 1)
    // Distance of root from itself = 0
    q.push({0, node});

    while(!q.empty()) {

        auto [dis, node] = q.front();
        q.pop();

        // If we already found a shorter distance to this node,
        // ignore this entry.
        if(dist[node] < dis) continue;

        // Visit all neighbours
        for(auto it : adj[node]) {

            int newdis = dis + 1;

            // If this path gives a shorter distance to neighbour
            if(dist[it] > newdis) {

                // Add neighbour to queue with its new distance
                q.push({newdis, it});

                // Update distance
                dist[it] = newdis;
            }
        }
    }

    return;
}

int main() {

    int n, q;
    cin >> n >> q;

    // Adjacency list of the tree
    vector<vector<int>> adj(n + 1);

    // dp[i][j] = 2^j-th ancestor of node i
    //
    // dp[i][0] = immediate parent
    // dp[i][1] = 2nd ancestor
    // dp[i][2] = 4th ancestor
    // dp[i][3] = 8th ancestor
    // ...
    vector<vector<int>> dp(n + 1, vector<int>(20, -1));

    // dept[i] = depth/distance of node i from root (node 1)
    vector<int> dept(n + 1, 1e9);

    // Root node is 1, so its depth is 0
    dept[1] = 0;

    // Input describes the parent of every node.
    // Node i+1 has parent b.
    for(int i = 1; i < n; i++) {

        int a = i + 1;
        int b;

        cin >> b;

        // Create edge a <-> b
        adj[a].push_back(b);
        adj[b].push_back(a);

        // Immediate parent of a is b
        dp[a][0] = b;
    }

    // Build the binary lifting table
    //
    // If dp[i][j-1] is the 2^(j-1)-th ancestor,
    // then its 2^(j-1)-th ancestor gives
    // the 2^j-th ancestor.
    for(int j = 1; j < 20; j++) {

        for(int i = 1; i <= n; i++) {

            if(dp[i][j-1] != -1) {

                dp[i][j] =
                    dp[dp[i][j-1]][j-1];
            }
        }
    }

    // Find depth of every node from node 1
    fun(1, adj, dept);

    // Process queries
    while(q--) {

        int a, b;
        cin >> a >> b;

        int d1 = dept[a];
        int d2 = dept[b];

        // If the nodes have different depths,
        // move the deeper node upward until
        // both nodes have the same depth.
        if(d1 != d2) {

            int diff = abs(d1 - d2);

            // a is deeper
            if(d1 > d2) {

                // Move a upward by 'diff'
                for(int i = 0; i < 20; i++) {

                    // If bit i of diff is set,
                    // move a upward by 2^i.
                    if(diff & (1 << i)) {
                        a = dp[a][i];
                    }
                }
            }

            // b is deeper
            else {

                // Move b upward by 'diff'
                for(int i = 0; i < 20; i++) {

                    if(diff & (1 << i)) {
                        b = dp[b][i];
                    }
                }
            }
        }

        // If both nodes became the same,
        // that node itself is the LCA.
        if(a == b) {
            cout << a << ' ';
            continue;
        }

        // Try to move both nodes upward.
        // Start from the largest jump (2^19)
        // and go down to 2^0.
        for(int j = 19; j >= 0; j--) {

            int u = dp[a][j];
            int v = dp[b][j];

            // If their 2^j-th ancestors are different,
            // we can safely move both nodes upward.
            if(u != v) {
                a = u;
                b = v;
            }
        }

        // At this point, a and b are directly below
        // their LCA, so their immediate parent is the LCA.
        cout << dp[a][0] << ' ';
    }
    return 0;
}