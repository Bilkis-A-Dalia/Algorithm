void dfs(int u)
// {
//     //section-1:actions just after entring node
//     visited[u] = true;
//     cout << "Visiting node:" << u << endl;

//     for(int v:adj[u])
//     {
//         //section-2:before entring new  neighbor
//         //if(visited[v]==false)
//         if(visited[v]==true)
//             continue;
//         dfs(v);
//         //section-3:after exiting a neighbor
//     }
//     //section-4:before exiting node u
// }