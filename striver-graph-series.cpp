/* Strivers Graph series */
//GRAPH - BFS - DFS - TOPOSORT - BIPARTITE - SHORTEST PATH - MST -  
    /*  1. Introduction to Graphs
        2. Graph representation in C++
        3. Grpah representation in Java
        4. What are connected components
        5. BFS
        6. DFS
        7. Number of Provinces - connected components
        8. Number of Islands - connected components - BFS or DFS
        9. Flood Fill Algorithm - DFS or BFS
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
	32. Dijkstra's algorithm - using priority queue
	33. Dijkstra's algorithm - using set
	34. Dijkstra's algorithm - using set not PQ
	35. Dijkstra's algorithm - print shortest path
	36. Shortest distance in a binary maze
	37. Path with minimum effort
	38. Cheapest flight within K stops
	39. Minimum multiplication to reach end
	40. Number of ways to arrive at destination
	41. Bellman Ford algorithm
	42. Flyod warshall algorithm
	43. Find the city with smallest number of neighbors
	44. Minimum spanning tree - theory
	45. Prim's algorithm - MST
	46. Disjoint set
	47. Kruskal's algorithm
	48. Number of operations to make network connected 
	49. Accounts Merge - DSU
	50. Number of Islands - II
	51. Number of Islands - II DSU
	52. Making a larget islan - DSU
	53. Most stones removed with same row and col - DSU
	54. Strongly connected components
	55. Bridges in graph - using trajan's algorithm
	56. Articaulation point in a graph
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
    - acyclic graph (if there are no cycles in the graph)
    - path in a graph (a node can't appear twice in a graph)
    - degree's in a graph 
        un-directed graph    - degress of a vertex is the number of edges attached to it 
                            - total degree of the graph is twice the number of edge.
        directed grpah  - it can have in-degree (incoming edges) or out-degree (outgoing edges)
        edge weight     - each edge can have weight (default can be considered as 1 )  
*/

/*  2. Grpah presentation
    - Input
        - need to know if directed or undirected graph
        - number of nodes and number of edges (n,m)
        - set of edges connecting vertices
        - 0 Based or 1 based vertices (generally 0 based)
    - Store
        - adjacency graph (matrix way)
        -   1 based matrix - adj[n+1][m+1] 
        -   edge between two nodes is set, all other cells are not-set
        -   in case of wighted graph - in-stead-of setting the cell, place the weight
        -   space needed is O(n*n)
        - adjacency list (vector way)
        -   vector<int>adj[n+1]
        -   each index in the vector will contain all the neighbor nodes
        -   in case of weighted graph   -   in stead of storing only the neighbor node
                                        -   store the node with weight in a pair
        -   O(2E) in case of un-directed and O(E) in case of directed
*/

/*
    3. Grpah representation in Java
*/

/*  4. Connected components
        - different components of a single graph
        - traversal algorithm can traverse only one component
        - can't traverse from one component to other so need to use a visited array
        - visited array to make sure that all the components (nodes) are traversed
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
    - while queue is not empty - (take the element out from the queue)   
        - push all the neighbors into queue (if it's not visited)
        - mark the nodes as visited (visited array)
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
    - before traversing all neighbor(like BFS) - traversal one node in depth first
    - goes in depth before going to next neighbor
    - based on the starting node - traversal will be different
    - start with the root 
        - recurssively call the node
        - mark them visited for the recurssive visited nodes
        - once return from above recurssive, call the same for next node
    space complexity - O(3N) ~ O(N)
    time complexity - O(N) + O(2E) 
                    - calling recurssion once + degree of graph (number of times each node will be called)
*/
void dfs1(int node, vector<int> adj[], int vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    //traverse all its neighbor
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs1(it, adj, vis, ls);
        }
    }
}

vector<int> dfsOfGraph(int v, vector<int> adj[]){
    int vis[v] = {0};
    int start = 0;
    vector<int> ls;
    dfs1(start, adj, vis, ls);
    return ls;
}

/* 7. Number of Provinces - connected components
    - find out, number of connected components
    - any traversal can be used - BFS or DFS
    - traverse till all the nodes are not visited 
    space complexity - O(N) for visited array - O(N) recurssion stack space
    time complexity - O(N) + O(v + 2E)
*/
void dfs2(int node, vector<int> adj[], int vis[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs2(it, adj, vis);
        }
    }
}

int numProvinces(int v, vector<int> adj[]){
    int vis[v] = {0};
    int cnt = 0;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            cnt++;
            dfs2(i, adj, vis);
        }
    }
    return cnt;
}

/*  8. Number of Islands
    - same as above, here instead of adj list - this is a matrix
    - space complex - O(N*N) - visiting the matrix
    - time complex - O(N*N) + 9 rows - O(N*N)
*/
void bfs3(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vis[i][j] = 1;
    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        //traverse its neighbors and mark them as visited
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
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
                bfs3(row, col, vis, grid);
            }
        }
    }
    return cnt;
}

/* 9. Floodfill algorithm
    - can be done in DFS or BFS
    - BFS is more optimised, with minimum steps
    - however here we just need to fill so any traversal is fine
    space complexity - O(n*m) + O(n*m)
    time complexity - every node traverse in 4 directions
                    -   x nodes with 4 direction - O(x) + 4 * O(x) = O(x)
                    - O(n*m)
*/
void dfs4(int row, int col, 
        vector<vector<int>>&dimage, 
        vector<vector<int>>&simage, 
        int initColor, int newColor){
    dimage[row][col] = newColor;
    int n = simage.size();
    int m = simage[0].size();
    vector<vector<int>> dir({{-1,0},{0,1},{1,0},{0,-1}});
    for(int i=0; i<4; i++){
        int nrow = row + dir[i][0];
        int ncol = col + dir[i][1];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            simage[nrow][ncol] == initColor && dimage[nrow][ncol] != newColor){
                dfs4(nrow, ncol, dimage, simage, initColor, newColor);
            }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, 
                                int sr, int sc, int newColor ){
    int initColor = image[sr][sc];
    vector<vector<int>> ans = image;
    dfs4(sr,sc,ans,image, initColor, newColor);
    return ans;
}

/* 10. Rotten Oranges 
    - each orange rottens all it's neighbor 
    - all fresh oranges in the same level - BFS
    - if we would have taken DFS - it will take more time to reach all it's neighbors
    - since we want to rotten then simultaniously (with minimum time) so BFS
*/
int orangeRotting(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    //{{r,c},t}
    queue<pair<pair<int,int>,int>> q;
    int vis[n][m]={{0}};
    int cntFresh = 0;
    //find all rotten oranges
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            } else {
                vis[i][j] = 0; //this is not needed if we have initialized to 0
            }
            if(grid[i][j]==1)
                cntFresh++;
        }
    }

    int tm = 0;
    int cnt = 0;
    vector<vector<int>> dir({{-1,0},{0,1},{1,0},{0,1}});
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();
        for(int i=0; i<4; i++){
            int nrow = r + dir[i][0];
            int ncol = c + dir[i][1];
            if(nrow>=0 && nrow<n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){//a fresh orange and not visited
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol}, t+1});
                    cnt++;
                }
        }
    }

    /* check all orange are rotten, 
    //if the cntFresh is not at the beginning
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]!=2 && grid[i][j]==1)
                return -1;
        }
    } 
    */
    if(cnt != cntFresh)
        return -1;

    return tm;
}

/* 11. Detect a cycle in an undirected graph using BFS
   - cycle - start from a node and visit all nodes and come back to the same node
   - cycle - start from a node in different direction and collide in a single node
   - For connected components - we need to call this algorithm on each component
   - to check if the graph having cycle mean - any of its components is having a cycle
   time : O(N+2E) same as BFS + O(N) for for loop
   space : O(N)
*/

bool detect(int src, vector<int> adj[], int vis[]){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});  //{current node, parent node (node visisted, previous to this node)}
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]){
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            //this node is visited and it is not parent
            else if(parent != adjacentNode) {
		        return true;
	        }
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]){
    int vis[v] = {0};
    for(int i=0; i<v; i++){
        if(!vis[i]){
            if(detect(i, adj, vis))
     		return true;
        }
    }
}

/* 12. Detect a cycle in an undirected graph using DFS
   space: O(N)
   time: O(N+2E) + O(E) for the for loop
*/

bool detect1(int node, int parent, int vis[], vector<int> adj[]){
    vis[node] = 1;
    for(auto adjacentNode: adj[node]){
        if(!vis[adjacentNode]){
            if(detect1(adjacentNode, node, vis, adj) == true)
                return true;
        }
        else if(adjacentNode != parent) return true;
    }
    return false;
}

bool isCycle1(int V, vector<int> adj[]){
    int vis[V] = {0};
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(detect1(i, -1, vis, adj) == true)
                return true;
        }
    }
}

/* 13. Distance of nearest cell having 1, 0/1 matrix
    - 0/1 matrix is given, find the matrix is having nearest one of each cell
    - distance is calculated only the row and col distance (not diagonally)
    - nearest distance, so think about BFS
    - with 1 step - reach all 0 at a distance 1, with step 2, each all 0 at distance 2
    - multi source BFS, put all source at queue and start BFS
    time : O(n*m)
    space : O(n*m)
*/
vector<vector<int>> nearest(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<int>> dist(n, vector<int>(m,0));
    queue<pair<pair<int,int>, int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 1) {
                q.push({{i,j},0});
                vis[i][j] = 1;
            } else {
                vis[i][j] = 0;
            }
        }
    }
    
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;

        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m
                && vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                q.push({{nrow,ncol}, steps+1});
            }
        }
    }
    return dist;
}

/* 14. Surrounded Regions
    - Every element is either O or X, replace all O with X that are surrounded by X.
    - A 'O' or a set of O is is considered to be surrounded by X if there are X
    at location, just below, above, left and just right to it.
    - that means - boundary O can be ignored - not surrounded by X
    - if a O is not connected to a boundary, that means it can be converted to X
    - so find out all the boundary O and it's connected which can't be converted 
    space: O(N*M)
    time: O(N*M)
*/

void dfs5(int row, int col, vector<vector<int>>& vis,
    vector<vector<char>>& mat){

    int n = mat.size();
    int m = mat[0].size();
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
   
    vis[row][col] = 1;
    for(int i=0; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
        && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
            dfs5(nrow, col, vis, mat);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
    vector<vector<int>> vis(n, vector<int>(m,0));
    //traverse first and last row
    for(int j=0; j<m; j++){
        //first row
        if(!vis[0][j] && mat[0][j] == 'O')
            dfs5(0, j, vis, mat);
        //last row
        if(!vis[n-1][j] && mat[n-1][j]== 'O')
            dfs5(n-1, j, vis, mat);
    }

    //traverse first and last column
    for(int i=0; i<n; i++){
        //first column
        if(!vis[i][0] && mat[i][0]=='O')
           dfs5(i, 0, vis, mat);
        if(!vis[i][m-1] && mat[i][m-1]=='O')
           dfs5(i, m-1, vis, mat);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && mat[i][j] == 'O')
                mat[i][j] = 'X';
        }
    }
    return mat;
}

/* 15. Number of Enclaves
   - 0 represents a sea, 1 represents a land cell, can move in 4 directions
   - find number of land cells in grid for which we can't walk off the boundary 
   of the grid in any number of moves.
   - something connected to bundary never be a naswer and all those connected to them as well
   space: O(n*m)
   time: O(n*m) * 4 for 4 directions
*/


int numberOfEnclaves(vector<vector<int>> &grid){
    queue<pair<int,int>> q;
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //first row, first col, last row, last col
            if(i == 0 || j == 0 || i == n-1 || j == m-1){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        //traverse all four directions
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && (vis[nrow][ncol] == 0) && (grid[nrow][ncol] == 1)){
                q.push({nrow,ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
       for(int j=0; j<m; j++) {
           if(grid[i][j] == 1 && vis[i][j]==0)
               cnt++;
       }
    }
}

/* 16. Number of distinct Islands
   - Given a boolean 2D matrix grid of size n * m. 
   You have to find the number of distinct islands where a group of connected 1's 
   (horizontally or vertically) forms an island. Two islands are considered to be 
   distinct if and only if one island is not equal to another (not rotated or reflected)
   space: O(n*m)
   time: O(n*m)
*/

void dfs6(int row, int col, vector<vector<int>>& vis,
     vector<vector<int>>& grid, vector<pair<int,int>>& vec, 
     int row0, int col0){
    int n = grid.size();
    int m = grid[0].size();
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};

    vis[row][col] = 1;
    vec.push_back({row-row0, col-col0});
    for(int i=0; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
        && !vis[nrow][ncol] && (grid[nrow][ncol] == 1)){
            dfs6(nrow, ncol, vis, grid, vec, row0, col0);
        }
    }        
} 

int countDistinctIslands(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(n,0));
    set<vector<pair<int,int>>> st;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){
                vector<pair<int,int>> vec;
                dfs6(i, j, grid, vis, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

/* 17. Bipartite Graph - BFS
   - color the graph with two colors such that no two adjacent nodes have same color.
   - Any graph with even cycle length can also be bipartite
   - Any graph with odd cycle length can NEVER be bipartite
   space, time is same as BFS   
*/
bool checkBipartite(int start, int V, vector<int>adj[], int col[]){
    queue<int> q;
    q.push(start);
    int color[V];
    color[start] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
 
        for(auto it: adj[node]){
            //if the adjacent node is not colored
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }
            //if the adjacent node having same color
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    int color[V];
    for(int i=0; i<V; i++)
        color[i]=-1;

    for(int i=0; i<V; i++){
        if(color[i] == -1){
            if(checkBipartite(i, V, adj, color) == false){
                return false;
            }
        }
    }   
    return true;
}

/* 18. Bipartite Graph - DFS
   space and time is same as DFS
*/
bool checkBipartiteDfs(int node, int col, vector<int>adj[], int col[]){
    color[node] = col;

    for(auto it: adj[node]){
        //if the adjacent node is not colored
        if(color[it] == -1){
            if(checkBipartiteDfs(it, !col, adj, color)==false)
                return false;
        }
        //if the adjacent node having same color
        else if(color[it] == col){
            return false;
        }
    }
    return true;
}

bool isBipartiteDfs(int V, vector<int>adj[]){
    int color[V];
    for(int i=0; i<V; i++)
        color[i]=-1;

    for(int i=0; i<V; i++){
        if(color[i] == -1){
            if(checkBipartiteDfs(i, 0, adj, color) == false){
                return false;
            }
        }
    }   
    return true;
}

/* 19. Detect cycle in a directed graph
   - This is a not a cycle if the neighbor is already visited - it's true for undirected
   - In case of directed, on the same path, the node has to be visited again to be a cycle.
   space and time: same as DFS
*/
bool dfsCheck(int node, vector<int> adj[], int vis[], 
    int pathVis[]){
    vis[node] = 1;
    pathVis[node]=1;
    
    //traverse for adjacent nodes
    for(auto it: adj[node]){
        //node is not visited
        if(!vis[it]){
            if(dfsCheck(it, adj, vis, pathVis) == true){
                return true;
            }
        }
        //when node has been previously visited
        // but it has to be visited on the same path
        else if(pathVis[it]){
            return true;
        }
    }
    pathVis[node]=0;
    return false;
}

vector<int> isCycleDirected(int V, vector<int> adj[]){
    int vis[V] = {0};
    int pathVis[V] = {0};
    
    for(int i=0; i<V; i++){
        if(!vis[i]){
           if(dfsCheck(i, adj, vis, pathVis)==true)
               return true;     
        }
    }
    return false;
}

/* 20. Eventual free states
   - A node is a termina node if there are no outgoing edges.
   - A node is a safe node if every possible path starting from that node 
   leads to a terminal node.
   - You have to return an array containing all the safe nodes of the graph
   - the answer should be sorted in asending order.
   == A node ending somewhere is a safe node.
   == If a a node is part of a cycle, it can't be a safe node.
   space: three arrays
   time : DFS
*/
bool dfsCheck1(int node, vector<int> adj[], int vis[], 
    int pathVis[], int check[]){
    vis[node] = 1;
    pathVis[node]=1;
    check[node]=0;
    //traverse for adjacent nodes
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfsCheck(it, adj, vis, pathVis, check) == true){
                check[node] = 0;
                return true;
            }
        }
        //when node has been previously visited
        // but it has to be visited on the same path
        else if(pathVis[it]){
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node]=0;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]){
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0};
    vector<int> safeNodes;
    for(int i=0; i<V; i++){
        if(!vis[i]){
           dfsCheck1(i, adj, vis, pathVis, check);     
        }
    }
    for(int i=0; i<V; i++){
        if(check[i] == 1)
            safeNodes.push_back(i);
    }
    return safeNodes;
}

/* 21. Topological sorting - DFS
   - it only exist on DAG (directed acyclic graph - directed graph with no cycles)
   - Any linear ordering of vertices such that if there is an edge between u and v than
    'u' always appear before 'v' in that ordering.
   - ordering - reverse of dfs
   - space and time as as DFS
*/
bool dfsTopo(int node, int vis[], stack<int> &st, vector<int> adj[]){
    vis[node] = 1;
 
    //traverse for adjacent nodes
    for(auto it: adj[node]){
        //node is not visited
        if(!vis[it]){
            dfsTopo(it, vis, st, adj);
        }
    }
    st.push(node);
}

//function to return list containing vertices in topological order
vector<int> topoSort(int V, vector<int> adj[]){
    int vis[V] = {0};
    stack<int> st;
    
    for(int i=0; i<V; i++){
        if(!vis[i]){
           dfsTopo(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

/* 22. Topological sorting - DFS - Kahn's algorithm
   - time O(V+E)
*/
//function to return list containing vertices in topological order
vector<int> topoSortBFS(int V, vector<int> adj[]){
    int indegree[V]={0};

    //calculate indegree
    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
           indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<V; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        //node is in topo sort
        //remove it from indegree
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
    return topo;
}

/* 23. Detect a cycle in a directed graph
   - BFS / topological sort / Kahn's algo
   - toposort is a linear order of a DAG
   - if there is a cycle then we can't have toposort
   - so if topo sort don't have all the nodes so there is a cycle
   space and time as as topo sort
*/
bool isCyclic(int V, vector<int> adj[]){
    int indegree[V]={0};

    //calculate indegree
    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
           indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<V; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int cnt=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        //node is in topo sort
        //remove it from indegree
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }

    if(cnt == V) 
	    return false;
    return true;
}

/* 24. Course schedule - I and II
   - something before something, thing about topo sort
*/
bool isPossible(int V, vector<pair<int,int>> &prereq){
    vector<int> adj[V];
    for(auto it: prereq){
        adj[it.first].push_back(it.second);
    }

    int indegree[V]={0};
    for(int i=0; i<V; i++){
        for(auto it: adj[i])
            indegree[it]++;
    }

    queue<int> q;
    for(int i=0; i<V; i++){
        if(indegree[i]==0)
            q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        //node is in your topo sort
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }

    //if order is asked, return topo array.
    if(topo.size() == V)
        return true;
    return false;
}

/* 25. Find eventual safe states - BFS - toposort
   - already served with DFS, this is with BFS
   - toposort of reverse direction will be eventual nodes
   - reverse all the edges 
   - get all the nodes with indegree zero
   - do the removal of edges on adjacent nodes 
*/
vector<int> eventualFafeNodes1(int V, vector<int> adj[]){
    vector<int> adjRev[V];
    int indegree[V] = {0};
    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> safeNodes;
    for(int i=0; i<V; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for(auto it: adjRev[node]){
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

/* 26. Alien Dictionary
- find the first differential factor between two strings
- find the edge for the first two different chars
- create a direct acyclic graph
- do the topo sort to get the order
- ORDER IS NOT POSSIBLE
    - sorted string should be always before larger string when everyone matches
    - if sorter string is after larger string in above case then it's possible
    - e.g - abcd, abc 
    - if there is a cyclic dependency, then it's not possible
    - abc, bat, ade  - a < b < a
- add above check to make sure to check if ans is not possible
*/

/* answer is always possible */
string findOrder(string dict[], int N, int K){
    vector<int> adj[K];
    for(int i=0; i<N-1; i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(), s2.size());
        for(int ptr=0; ptr < len; ptr++){
            if(s1[ptr] != s2[ptr]){
                adj[s1[ptr] - 'a'].push_back(s2[ptr]-'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(K, adj);
    string ans = "";
    for(auto it: topo){
        ans = ans + char(it + 'a');
    }
    return ans;
}

/*
    27. Shortest path in DAG - toposort
    - this a directed acyclic weighed graph
- distance of all nodes from source node
- topo sort with relaxation
- take the node out of stack and relax the edges
- for each node in stack, calculate the shortest distance
- why topo sort? we can use some standart algoithm as well
Find the shortest path to the vertex is easy if you already know 
the shortest paths to all the vertices that can preceed it
Find the longest path in DAG is easy if you already know
the longest path to all the vertices that preceed it.

Processing the vertices in topological order ensures that by the time
you get to the vertex, you have already processed all the vertices 
that can preceed it.

Dijkstra's algo is not necessary for the graph that can contain cycles,
because they can't be topological sorted.
*/

void topoSort(int node, vector<pair<int,int>> adj[],
            int vis[]. stacl<int>&st){
    vis[node]=1;
    for(auto it: adj[node]){
        int v = it.first;
        if(!vis[v])
            topoSort(v, adj, vis, st);
    }
    st.push(node);
}
vector<int> shortestPath(int N, int M, vector<int> edges[]){
    for(pair<int,int>> adj[];
    for(int i=0; i<M; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
    }

    //find the topo sort
    int vis[N] = {0};
    stack<int> st;
    //DFS O(N+M)
    for(int i=0; i<N; i++){
        if(!vis[i]){
            topoSort(i, adj, vis, st);
        }
    }

    vector<int> dist(N);
    for(int i=0;i<N; i++) dist[i] = INT_MAX;
    dist[0] = 0;
    //O(N+M)
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it: adj[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }
    return dist;
}

/* 28. Shortest path in undirected graph having unit distance
 - Given a undirected graph, having unit weight, find the shortest distance
 - from src to all the points, if path is not possible then put -1.
 - kind of BFS but why it works ? as each vertex at distance 1 and queue sorts it already
*/
vector<int> shortestPath(vector<vector<int>>&edges, int N, int M, int src){
    vector<int> adj[N];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    it dist[N];
    for(int i=0; i<N; i++)
        dist[i] = 1e9;
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }
    
    vector<int> ans(N, -1);
    for(int i=0; i<M; i++){
        if(dist[i] != 1e9){
            ans[i] = dist[i];
        }
    }
    return ans;
}

/* G-29 Word Ladder - I
   https://practice.geeksforgeeks.org/problems/word-ladder/1
  - shortest path from a starting word to ending work for a given dict
  - shortest means BFS
  - N * word length * 26 * log N (for set)
*/
int wordLadderLength(string startWord, string targetWord,
                      vector<string>& wordList){
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == targetWord)
            return steps;
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(int ch='a'; ch<='z'; ch++){
                word[i] = ch;
                //if exist in set
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps+1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}
	
/* G-30: Word Ladder - 2
   - in the above problem - return all possible word orders
   
https://practice.geeksforgeeks.org/problems/word-ladder-ii/1
*/
	
vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList){
	
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
    vector<vector<string>> ans;

    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        //erase all words that has been 
        //used in the previous levels to transform
        if(vec.size() > level){
            level++;
            for(auto it: usedOnLevel){
                st.erase(it);
            }
            usedOnLevel.clear();
        }

        string word = vec.back();
        //store the answer
        if(word == endWord){
            if(ans.size()==0)
                ans.push_back(vec);
            else if(ans[0].size() == vec.size())
                ans.push_back(vec);
        }

        //wordlength * 26
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(int ch='a'; ch<='z'; ch++){
                word[i] = ch;
                //if exist in set
                if(st.find(word) != st.end()){
                    vec.push_back(word);
                    q.push_back(vec);
                    //mark as visited on the level
                    usedOnLevel.push_back(word);
                    vec.pop_bcak();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}

/* 31 Word Ladder -2 

*/	
	
/* 32. Dijkstra's algorithm - using priority queue
 Function to find the shortest distance of all the 
 vertices from the source vertex S.

 - earier we have see with DAG - no need of dijkstra
 - it is needed when we have edges with weight
 - it is not applicable for edges with negative weight 
 - since negative weight can create a infinite loop.
 
 time: O(E log V) - E is number is edges and V is the number of vertices
*/
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist<V);
    for(int i=0; i<V; i++)
        dist[i] = 1e9;
    dist[S] = 0;
    pq.push({0,S});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjNode = it[0];
            int edgeWeight = it[1];

            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

/* 33. Dijkstra's algorithm - using set
  - always want the minimum distance first (that why we were using priority queue)
  - set stores in ascending order so kind of same as priority queue
  - set over priority
  - erase on set is logn time
  - so based on the graph, we can choose pq or set
  COMPARISION
  -  time of the priority queue method be O(ElogE) instead of O(ElogV) 
     as there can be more than one instance of a node in the priority queue 
     whereas in the treeset method it will be O(ElogV) 
  - set is better as it saves the number of iterations when E > V
  - however set takes a logn extra because of extra erase
*/
vector<int> dijkstra1(int V, vector<vector<int>> adj[], int S){
    set<pair<int,int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0, S});
    dist[S] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dist = it.first;
        st.erase(it);

        for(auto it: adj[node]){
            int adjNode = it[0];
            int edgW = it[1];

            if(dis + edgW < dist[adjNode]){
                //erase if it existed
		// as we have a better distance now to same vertex
                if(dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode});

                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
} 

/* 34.
1. why PQ or set not a Queue ?
with Queue need to check through all the paths to find the optimize path - a lot of paths to travel
  - un-necessary explorations paths 
with PQ, once we traverse the minimum distance first - optimize path - the non-optimise will get ignored so less paths to travel
  - explore minimum 
2.
Time - O(ElogV)
*/

/* 35. Print shortest path
   - where are you coming from with dijkstra
   time: dijkstra + O(N) = O(ElogV) + O(N)
*/

vector<int> shortestPath(int n, int m,
   vector<vector<int>>&edges){
    // 1 based index
    vector<pair<int,int>> adj[n+1];
    for(auto it: edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1, 1e9), parent(n+1);
    for(int i=1; i<=n; i++)
        parent[i] = i;
    dist[1] = 0;
    while(!pq.empty()){
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edW = it.second;
            if(dis + edW < dist[adjNode]){
                dist[adjNode] = dis + edW;
                pq.push({dist+edW, adjNode});
                parent[adjNode] = node;
            }
        }
    }
    if(dist[n] == 1e9) return {-1};
    vector<int> path;
    int node = n;
    // O(N)
    while(parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}
	
/* 36. Shortest distance in binary maze
https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
- all the cell are with distance 1 so no need of priority queue - just a queue enough
*/

int shortestPath(vector<vector<int>> &grid,
                 pair<int, int> source,
                 pair<int, int> dest) {

    queue<pair<int, pair<int,int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    //we can check if src == dest then return
    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;
        for(int i=0; i<4; i++){
            int newr = r + dr[i];
            int newc = c + dc[i];
            if(newr >= 0 && newr < n && newc >= 0 && newc < m
            && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]){
                dist[newr][newc] = 1 + dist;
                if(newr == dest.first && newc == dest.second)
                    return dis + 1;
                q.push({1+dis, {newr, newc}});
            }
        }
    }
    return -1;
}

/* 37. Path with minimum effort
   https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1
    A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
*/
int MinimumEffort(vector<vector<int>>&heights){
    // {diff, {row, col}}
    priority_queue<pair<int, pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int, pair<int,int>>>> pq;

    int n = heights.size();
    int m = heights.size();
  
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;
    pq.push({0, {0,0}});
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    //E log V
    // n x m x 4 x log(nxm)
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        for(int i=0; i<4; i++){
            int newr = row + dr[i];
            int newc = col + dc[i];
            if(newr >= 0 && newc >=0 && newr < n && newc < m){
                int newEffort = max(abs(heights[row][col] - heights[newr][newc], diff));
                if(newEffort < dist[newr][newc]){
                    dist[newr][newc] = newEffort;
                    pq.push({newEffort, {newr,newc}});
                }
            }
        }
    }
    return 0; //unreachable
}

/* 38. Cheapest Flights within K stops (IMP-IMP)
https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

https://leetcode.com/problems/cheapest-flights-within-k-stops/

- can't do based on weight - but based on number of stops
- if based on weight - we will miss same stops with minimum distance
- PQ not needed as the stop increment by 1
- once reach dest - don't stop - check for optimise path
*/

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
    
        queue<pair<int, pair<int,int>>> q;
        // {stops, {node, dist}}
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        // E log V is for dijkstra
        // since no PQ so E = flights.size()
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;
            for(auto iter: adj[node]){
                int adjNode = iter.first;
                int edW = iter.second;
                if(cost+edW < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + edW;
                    q.push({stops+1, {adjNode, cost+edW}});
                }
            }
        }
        if(dist[dst] == 1e9) 
            return -1;
        return dist[dst];    
    }
	
/* 39. Minimum multiplication to reach end

*/

		       
/* 40. Number of ways to Arrive at destination

https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
  - time same as dijkstra
*/
int countPaths(int n, vector<vector<int>>& roads){
    vector<pair<int,int>> adj[n];
    for(auto it: roads){
         adj[it[0]].push_back({it[1], it[2]});
         adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int> dist(n, 1e9), ways(n,0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0,0});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
 
        for(auto it: adj[node]){
           int adjNode = it.first;
           int adW = it.second;
           if(dis + adW < dist[adjNode]){
               dist[adjNode] = dis + adW;
               pq.push({dis+adW, adjNode});
               ways[adjNode] = ways[node];
           }else if(dis+adW == dist[adjNode]){
	       //number of ways to its parent + this
               ways[adjNode] = ways[adjNode] + ways[node];
           }
        }
   }
   return ways[n-1];
}
		       

		       
	
int main(){
    cout<<"Graph Series - 11/09/2022"<<endl;
    cout<<"Graph Series restart after 10 - 01/12/2022"<<endl;
	
    return 0;
}
