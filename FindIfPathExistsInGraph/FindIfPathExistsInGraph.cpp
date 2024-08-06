#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    // Check if there's only one node
    if (n == 1) return true;
    vector<int>visited(n, 0);

    // Create & construct adjacency list
    vector<vector<int>>adj(n);
    for (auto ele : edges) {

        adj[ele[0]].push_back(ele[1]);
        adj[ele[1]].push_back(ele[0]);
    }

    // BFS traversal
    queue<int> q;

    q.push(source);
    
    visited[source] = 1;
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();

        for (int i = 0; i < adj[curr].size(); i++) {
            
            // If destination found, return true
            if (adj[curr][i] == destination) return true;

            // Explore unvisited neighbors
            if (!visited[adj[curr][i]]) {
                q.push(adj[curr][i]);
                visited[adj[curr][i]] = 1;
            }
        }
    }
    // No valid path found
    return false;
}

//  0     1   2     3    4     5
//[1, 0] [0] [0] [5, 4][5, 3][3, 4]

//los adyacente son los que son contiguos y se pueden obtener
//creando un array 2d aparte, ahi por cada numero dentro de un grupo se le asigna un indice
//es decir, si [5,3], quiere decir que 5 y 3 estan unidos
//entonces en el indice 5 colocamo el 3, y en el indice 3 colocamos un 5
//porque?
//porque pueden haber mas, es decir, [5,2] [2,3]...etc

//Esto estubo complicao no te voy a mentir mi brodie.

int main()
{
    vector<vector<int>> v = { {0,1}, {0,2}, {3,5}, {5,4}, {4,3}};
    vector<vector<int>> v2 = { {0,1}, {1,2}, {2,0}};

    validPath(6, v, 0, 5);
    //validPath(3, v2, 0, 2);
}
