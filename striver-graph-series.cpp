/* Strivers Graph series */
    /*  1. Introduction to Graphs
        2. Graph representation in C++
        3. Grpah representation in Java
        4. What are connected components
        5. BFS
        6. DFS
        7. Number of Provinces - connected components
        8. Number of Islands - connected components
        9. Flood Fill Algorithm
        10. Rotten Oranges
        11. Detect a cycle in an undirected graph - BFS
        12. Detect a cycle in an undirected graph - DFS
        13. Distance of nearest cell having 1 - 0/1 matrix
        14. Surrounded Regions - replace 0's with X's
        15. Number of Enclaves - Multi-source BFS
        16. Number of distinct Islands
        17. Bipartite Graph - BFS
        18. Bipartite Graph - DFS
        19. Detect cycles in a directed graph using DFS
        20. Find eventual safe states - DFS
        21. Topological sort - DFS
        22. Kahn's algorithm
        23. Detect a cycle in directed graph
        24. Course schedule - I, II - topological sort
        25. Find eventual safe state - BFS - topological sort
        26. Alien dictionary - topological sort
        27. Shortest part in directed cyclic graph - topological sort
        28. Shortest part in undirected graph 
        29. Word ladder - 1 - shortest paths
        30. Word ladder - 2 - shortest paths
        31. Word ladder - 2 - optimised approach 
    */
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

class BinaryTreeSeries{
    
};

/*  1. Introdcution to Grpah

    - directed graph
    - undirected graph 
    - vertex or number of nodes
    - edges - (undirected edge in case of undirected graph)
    - bi-direction edge (directed graph)
    - A ghaph is a set of edges and vertexes
    - cycles in a graph (start and end in the same node) 
    - if there is a cycle in a graph - undirected/directed cyclic graph
    - acyclic grpah (if there are no cycles in the graph)
    - path in a graph (a node can't appear twice in a graph)
    - degrees in a graph 
        undirected graph    - degress of a vertex is the number of edges attached to it 
                            - total degree of the grpah is twice the number of edge.
        directed grpah  - it can have indegree (incoming edges) or outdegree (outgoing edges)
        edge weight     - each edge can have weight (default can be considered as 1 )  
*/

/*  2. Grpah presentation
    - Input
        - need to know if directed or undirected graph
        - number of nodes and number of edges (n,m)
        - set of edges connecting vertices
        - 0 Based or 1 based vertices (generally 0 based)
    - Store
        - adjecency graph (matrix way)
        -   1 based matrix - adj[n+1][m+1] 
        -   edge between two nodes is set, all other cells are not-set
        -   in case of wighted graph - in stead of setting the cell place the wight
        -   space needed is O(nxn)
        - adjacency list (vector way)
        -   vector<int>adj[n+1]
        -   each index in the vector will contain all the neighbor nodes
        -   in case of weighted graph   -   in stead of storing only the neighbor node
                                        -   store the node with weight in a pair
        -   O(2E) in case of undirected and O(E) in case of directed
*/

/*
    3. Grpah representation in Java
*/

/*  4. Connected components
        - different coponents of single graph
        - traversal algorithm can traverse only one coponent
        - can't traverse from one component to other so need to use a visited array
        - visited array to make sure that all the coponents (nodes) are traversed
        - so in summary, starting from one node, we can't make sure all the nodes will get traverse
    for(i -> 1 to 10)
        if(!vis[i])
            traverse(i)    
*/

/*  5. Breadth-First-Search(BFS) 
    - can also be called as level wise traversal
    - need a starting node (from where the traversal starts)
    - a queue data structure (starting node will be in queue to start with)
    - a visited array (starting node mark as visited)
    - while queue is not empty - (take the element taken out from the queue)   
        - push all the neighbors into queue (if it's not visited)
        - mark the nodes as visited (visited arrat)
    - based on starting node - the result traversal will be different
    space complexity - O(3N) ~ O(N)
    time complexity - O(N) + O(2E)
*/
vector<int> bfsOfGraph(int v, vector<int> adj[]) {
    int vis[v] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]) {
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

/* 5. Depth First Search (DFS)
    - before traversing all neighbor(libe BFS) - traversal one node in depth first
    - goes in depth before going to next neighbor
    - based on the starting node - traversal will be different
    - start with the root 
        - recurssively call the node
        - mark them visited for the recurssive visited nodes
        - once return from above recurssive call the same for next node
    space complexity - O(3N) ~ O(N)
    time complexity - O(N) + O(2E) 
                    - calling recurssion once + degree of graph (number of times each node will be called)
*/
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    //traverse all its neighbor
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsOfGraph(int v, vector<int> adj[]){
    int vis[v] = {0};
    int start = 0;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
}

/* 7. Number of Provinces - connected components
    - find out number of connected components
    - any traversal can be used - BFS or DFS
    - traverse till the nodes are not visited 
    space complexity - O(N) for visited array - O(N) recurssion stack space
    time complexity - O(N) + O(v + 2E)
*/
void dfs1(int node, vector<int> adj[], int vis[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs1(it, adj, vis);
        }
    }
}

int numProvinces(int v, vector<int> adj[]){
    int vis[v] = {0};
    int cnt = 0;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            cnt++;
            dfs1(i, adj, vis);
        }
    }
    return cnt;
}

/*  8. Number of Islands
    - same as above, here instead of adj list - this is a matrix
    - space complex - O(N*N) - visiting the matrix
    - time complex - O(N*N) + 9 rows - O(N*N)
*/
void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vis[i][j] = 1;
    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;

        //traverse its neighbors and mark them as visited
        for(int row=-1; row<=1; row++){
            for(int col=-1; col<=1; col++){
                int nrow = i + row;
                int ncol = i + col;
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m 
                    && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
            }
        }
    }
    
}

int numsIslands(vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    int cnt = 0;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(!vis[row][col] && grid[row][col]=='1'){
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;
}


int main(){
    cout<<"Graph Series - 11/09/2022"<<endl;

    return 0;
}