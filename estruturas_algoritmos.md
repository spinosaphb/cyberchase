# Structures

## Union-find
```c++
// definindo os conjuntos -> cada elemento pertence a um conjunto diferente
for (int i = 1; i <= n; i++) link[i] = i;
for (int i = 1; i <= n; i++) size[i] = 1;

// a func find o elemento representativo do elemento x
// O(logn)
int find(int x) {
    while (x != link[x]) x = link[x];
        return x;
}

// a func same checa se os elementos a e b pertencem ao mesmo conjunto
// O(logn)
bool same(int a, int b) {
    return find(a) == find(b);
}

// a func unite junta os conjuntos que contem os elementos a e b
// O(logn)
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (size[a] < size[b]) swap(a,b);
        size[a] += size[b];
        link[b] = a;
}
```

# Algorithms

## Tree

- DFS
```c++
vector<int> adj[N];
bool visited[N];

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    // process node s
    for (auto u: adj[s]) {
        dfs(u);
    }
}
```

- BFS
```c++
queue<int> q;
bool visited[N];
int distance[N];

visited[x] = true;
distance[x] = 0;
q.push(x);
while (!q.empty()) {
    int s = q.front(); q.pop();
    // process node s
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        distance[u] = distance[s]+1;
        q.push(u);
    }
}
```

- Djikstra
```c++
for (int i = 1; i <= n; i++) distance[i] = INF;
distance[x] = 0;
q.push({0,x});

while (!q.empty()) {
    int a = q.top().second; q.pop();
    if (processed[a]) continue;
    processed[a] = true;
    for (auto u : adj[a]) {
        int b = u.first, w = u.second;
        if (distance[a]+w < distance[b]) {
            distance[b] = distance[a]+w;
            q.push({-distance[b],b});
        }
    }
}
```