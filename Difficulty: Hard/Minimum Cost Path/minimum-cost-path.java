//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int[][] grid = new int[n][n];
            for(int i = 0; i < n; i++){
                String[] S = br.readLine().trim().split(" ");
                for(int j = 0; j < n; j++){
                    grid[i][j] = Integer.parseInt(S[j]);
                }
            }
            Solution obj = new Solution();
            int ans = obj.minimumCostPath(grid);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends



class Solution
{
    // Helper class to represent a cell with its coordinates and cost
    static class Cell implements Comparable<Cell> {
        int row, col, cost;

        Cell(int row, int col, int cost) {
            this.row = row;
            this.col = col;
            this.cost = cost;
        }

        @Override
        public int compareTo(Cell other) {
            return Integer.compare(this.cost, other.cost);
        }
    }

    public int minimumCostPath(int[][] grid)
    {
        int rows = grid.length;
        int cols = grid[0].length;

        // Array to store the minimum cost to reach each cell
        int[][] minCost = new int[rows][cols];
        for (int[] row : minCost) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        // Priority queue to store cells with their current cost
        PriorityQueue<Cell> pq = new PriorityQueue<>();

        // Starting from the top-left cell
        pq.offer(new Cell(0, 0, grid[0][0]));
        minCost[0][0] = grid[0][0];

        // Possible directions to move
        int[] dr = {0, 0, 1, -1};
        int[] dc = {1, -1, 0, 0};

        while (!pq.isEmpty()) {
            Cell current = pq.poll();

            // Check all possible directions
            for (int i = 0; i < 4; i++) {
                int newRow = current.row + dr[i];
                int newCol = current.col + dc[i];

                // Check if the new position is within bounds
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int newCost = current.cost + grid[newRow][newCol];

                    // If the new cost is less than the current minimum cost to reach the cell
                    if (newCost < minCost[newRow][newCol]) {
                        // Update the minimum cost and add the cell to the priority queue
                        minCost[newRow][newCol] = newCost;
                        pq.offer(new Cell(newRow, newCol, newCost));
                    }
                }
            }
        }

        // The minimum cost to reach the bottom-right cell
        return minCost[rows - 1][cols - 1];
    }
}