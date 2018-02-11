struct Edge{
    int from,to;
    Edge(int from,int to):from(from),to(to){}
}
struct LCA{
    vector<Edge> edges;
    vector<int> G[maxn];
    void addEdge(int from,int to){
        Edge e1(from,to),e2(to,from);
        edges.push_back(e1);
        edges.push_back(e2);
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    
}; 