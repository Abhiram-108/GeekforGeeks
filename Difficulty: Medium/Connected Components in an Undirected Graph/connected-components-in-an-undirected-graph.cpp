class Solution {
private:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent); // Path compression
        return parent[x];
    }

public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<int> parent(V);
        for (int i = 0; i < V; i++)
            parent[i] = i;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int x = find(u, parent);
            int y = find(v, parent);
            if (x != y)
                parent[y] = x;  // Union
        }

        // Group nodes by root parent
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < V; i++) {
            int root = find(i, parent);
            components[root].push_back(i);
        }

        vector<vector<int>> result;
        for (auto& comp : components)
            result.push_back(comp.second);

        return result;
    }
};
