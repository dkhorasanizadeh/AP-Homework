#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <vector>

struct Edge {
  int src, dest;
};

template <class T>
class Graph {
 public:
  Graph(std::vector<Edge> const& edges, std::map<int, T> const& nodes) {
    adjList.resize(nodes.size());
    for (auto& edge : edges) {
      if (nodes.find(edge.src) == nodes.end() ||
          nodes.find(edge.dest) == nodes.end()) {
        throw "Given node dosen't exist";
      }
      adjList[edge.src].push_back(edge.dest);
    }
    this->nodes = nodes;
  }
  bool BFS(T target) {
    int size = nodes.size();
    int current = 0;
    bool* visited = new bool[size];
    for (int i = 0; i < size; i++) {
      visited[i] = false;
    }
    std::list<int> queue;
    visited[current] = true;
    queue.push_back(current);
    std::vector<int>::iterator i;
    while (!queue.empty()) {
      current = queue.front();
      if (target == getNodeValue(current)) {
        return true;
      }
      queue.pop_front();
      for (i = adjList[current].begin(); i != adjList[current].end(); ++i) {
        if (!visited[*i]) {
          visited[*i] = true;
          queue.push_back(*i);
        }
      }
    }
    return false;
  }
  bool DFS(T target) {
    int size = nodes.size();
    int current = 0;
    bool* visited = new bool[size];
    for (int i = 0; i < size; i++) {
      visited[i] = false;
    }
    std::stack<int> stack;
    stack.push(current);
    std::vector<int>::iterator i;
    while (!stack.empty()) {
      current = stack.top();
      stack.pop();
      if (!visited[current]) {
        if (target == getNodeValue(current)) {
          return true;
        }
        visited[current] = true;
      }
      for (i = adjList[current].begin(); i != adjList[current].end(); ++i) {
        if (!visited[*i]) {
          stack.push(*i);
        }
      }
    }
    return false;
  }
  int size() const { return nodes.size(); }
  std::vector<int> getNeighbor(int i) const { return adjList[i]; }
  T getNodeValue(int i) const { return nodes.at(i); }

 protected:
  std::vector<std::vector<int>> adjList;
  std::map<int, T> nodes;
};
template <class T>
class Tree : public Graph<T> {
 public:
  Tree(std::vector<Edge> const& edges, std::map<int, T> const& nodes)
      : Graph<T>(edges, nodes) {
    if (!isTree()) {
      throw "This graph is not a tree";
    }
  }

 private:
  bool isCyclicUtil(int v, bool visited[], int parent) {
    visited[v] = true;
    std::vector<int>::iterator i;
    for (i = this->adjList[v].begin(); i != this->adjList[v].end(); ++i) {
      if (!visited[*i]) {
        if (isCyclicUtil(*i, visited, v)) {
          return true;
        }
      } else if (*i != parent) {
        return true;
      }
    }
    return false;
  }
  bool isTree() {
    int size = this->nodes.size();
    bool* visited = new bool[size];
    for (int i = 0; i < size; i++) {
      visited[i] = false;
    }
    if (isCyclicUtil(0, visited, -1)) {
      return false;
    }
    for (int u = 0; u < size; u++) {
      if (!visited[u]) {
        return false;
      }
    }
    return true;
  }
};
template <class T>
void printGraph(Graph<T> const& graph) {
  int N = graph.size();
  for (int i = 0; i < N; i++) {
    std::cout << i << "( value = " << graph.getNodeValue(i) << " ) --> ";
    for (int v : graph.getNeighbor(i)) {
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }
}
Graph<int>* readFromFile(std::string fileName) {
  std::fstream file;
  file.open(fileName, std::ios::in);
  int i;
  file >> i;
  std::map<int, int> nodes;
  while (i--) {
    int adress, data;
    file >> adress >> data;
    nodes.insert({adress, data});
  }
  std::vector<Edge> edges;
  while (file) {
    Edge e;
    int origin, destination;
    file >> origin >> destination;
    e.src = origin;
    e.dest = destination;
    edges.push_back(e);
  }
  Graph<int>* graph = new Graph<int>(edges, nodes);
  return graph;
}

int main() {
  std::string fileName;
  int i;
  std::cin >> fileName >> i;
  Graph<int>* graph = readFromFile(fileName);
  if (graph->BFS(i)) {
    std::cout << "Found\n";
  } else {
    std::cout << "Not found\n";
  }
  return 0;
}
