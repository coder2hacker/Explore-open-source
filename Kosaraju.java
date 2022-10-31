// Java program to check if a given directed graph
// is strongly connected or not with BFS use
import java.util.*;
 
class Graph {
  int V; // No. of vertices
  // An array of adjacency lists
  ArrayList<ArrayList<Integer> > adj;
 
  // Constructor and Destructor
  Graph(int V)
  {
    this.V = V;
    adj = new ArrayList<>();
    for (int i = 0; i < V; i++) {
      adj.add(new ArrayList<>());
    }
  }
 
  // Method to add an edge
  void addEdge(int v, int w)
  {
    adj.get(v).add(w); // Add w to v’s list.
  }
 
  // A recursive function to print DFS starting from v
  void BFSUtil(int v, boolean visited[])
  {
     
    // Create a queue for BFS
    Queue<Integer> queue = new ArrayDeque<>();
 
    // Mark the current node as visited and enqueue it
    visited[v] = true;
    queue.add(v);
 
    while (!queue.isEmpty())
    {
       
      // Dequeue a vertex from queue
      v = queue.peek();
      queue.remove();
 
      // Get all adjacent vertices of the dequeued
      // vertex s If a adjacent has not been visited,
      // then mark it visited and enqueue it
      for (Integer i : adj.get(v)) {
        if (!visited[i]) {
          visited[i] = true;
          queue.add(i);
        }
      }
    }
  }
 
  // The main function that returns true if the
  // graph is strongly connected, otherwise false
  boolean isSC()
  {
    // Step 1: Mark all the vertices as not
    // visited (For first BFS)
    boolean[] visited = new boolean[V];
    for (int i = 0; i < V; i++)
      visited[i] = false;
 
    // Step 2: Do BFS traversal starting
    // from first vertex.
    BFSUtil(0, visited);
 
    // If BFS traversal doesn’t visit all
    // vertices, then return false.
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        return false;
 
    // Step 3: Create a reversed graph
    Graph gr = getTranspose();
 
    // Step 4: Mark all the vertices as not
    // visited (For second BFS)
    for (int i = 0; i < V; i++)
      visited[i] = false;
 
    // Step 5: Do BFS for reversed graph
    // starting from first vertex.
    // Starting Vertex must be same starting
    // point of first DFS
    gr.BFSUtil(0, visited);
 
    // If all vertices are not visited in
    // second DFS, then return false
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        return false;
 
    return true;
  }
 
  // Function that returns reverse (or transpose)
  // of this graph
  Graph getTranspose()
  {
    Graph g = new Graph(V);
    for (int v = 0; v < V; v++) {
      // Recur for all the vertices adjacent to this
      // vertex
      for (Integer i : adj.get(v))
        g.adj.get(i).add(v);
    }
    return g;
  }
}
 
public class GFG {
 
  // Driver program to test above functions
  public static void main(String[] args)
  {
    Graph g1 = new Graph(5);
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 0);
    g1.addEdge(2, 4);
    g1.addEdge(4, 2);
    if (g1.isSC())
      System.out.println("Yes");
    else
      System.out.println("No");
 
    Graph g2 = new Graph(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    if (g2.isSC())
      System.out.println("Yes");
    else
      System.out.println("No");
  }
}
