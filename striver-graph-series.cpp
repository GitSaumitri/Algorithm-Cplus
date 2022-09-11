/* Strivers Graph series */
    /*  1. Introduction to Graphs
        2. 
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
    space complexity - O(3N) ~ O(N)
    time complexity - O(N) + O(2E)
*/
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[n] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push(node);
        for(auto it: adj[node]) {
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main(){
    cout<<"Graph Series - 11/09/2022"<<endl;

    return 0;
}