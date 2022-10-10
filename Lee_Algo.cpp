#include <iostream>
# include<queue>
using namespace std;
#define ROW 5
#define COL 5

//To store cell cordinates
struct Cell
{
	int x;
	int y;
};

// Declaring Queue to be used in BFS
struct queueNode
{
	Cell pt; // Cell cordinates 
	int dist; // Cell's distance of from the source
};

// Check whether given cell(row,col) is a valid cell or not
bool checkValid(int row, int col)
{
	return ((row >= 0) && (row < ROW) &&	(col >= 0) && (col < COL));
}

// These arrays show the 4 possible movement from a cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

// Function to find the shortest path between source cell and destination cell. 
int bfsLee(int mat[][COL], Cell src, Cell dest)
{
	// Checking if source and destination cell have value 1 
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
		return -1;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);
	
	// Mark the source cell as visited 
	visited[src.x][src.y] = true;

	// Create a queue for BFS
	queue<queueNode> q;
	
	// Distance of source cell is 0
	queueNode s = {src, 0};
	q.push(s); // Enqueue source cell

	// Performing BFS starting from source cell
	while (!q.empty())
	{
		queueNode curr = q.front();
		Cell pt = curr.pt;

		// If we have reached the destination cell, return the final distance
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;
		q.pop();
        // Otherwise enqueue its adjacent cells with value 1 
		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];
			
			// Enqueue valid adjacent cell that is not visited
			if (checkValid(row, col) && mat[row][col] && 
			!visited[row][col])
			{
				
				visited[row][col] = true;
				queueNode Adjcell = { {row, col},
									curr.dist + 1 };
				q.push(Adjcell);
			}
		}
	}

	// Return -1 if destination cannot be reached
	return -1;
}

// Driver program to test above function
int main()
{
	int mat[ROW][COL] =
	{
		{ 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1 },
		{ 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1 }};

	Cell source = {0, 0};	//Starting point 
	Cell dest = {2, 1};		//Final point to reach

	int dist = bfsLee(mat, source, dest);

	if (dist != -1)
		cout<< "Length of the Shortest Path is "<<dist<<endl;
	else
		cout<< "Shortest Path doesn't exist"<<endl;

	return 0;
}
