// Create Graph

#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;
template<typename T> 
class Graph
{
  //Adacency Matrix
  unordered_map<T,vector<T> > adj;
  bool isUndirectedGraph;
  public:
      
    void addEdges(T u,T v,bool isUndirectedGraph)
    {
      this -> isUndirectedGraph = isUndirectedGraph;
      adj[u].push_back(v);
      
      if(isUndirectedGraph)
        adj[v].push_back(u);
    }

      
    void printGraph()
    {
      cout << (isUndirectedGraph ? "Undirected Graph" : "Directed Graph") << "is : " << endl;
      for(auto &it : adj)
      {
        cout << it.first << "-> ";
        for(auto &ele : it.second)
        {
          cout << ele << " ";
        }
        cout << endl;
      } 
    }
};

int main() 
{
  Graph<char> obj;
  //Number of edges
  int n;
  cout << "Enter the number of edges : " << endl;
  cin >> n;
    
	cout << "Enter the edges(u,v) of graph : " << endl;
	char u,v;
	for(int i = 0;i < n;i++)
	{
    cin >> u >> v;
    // true for undirected graph and false for directed graph 
    obj.addEdges(u,v,false);
	}
	
	//Print Graph
	obj.printGraph();
	
	return 0;
}
