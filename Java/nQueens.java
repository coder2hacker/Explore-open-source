import java.util.*;

class Solution {

    public boolean isValid(String[][] arr, int row, int col, int n) {
        int rowTemp = row, colTemp = col;
        for (int i = 0; i < n; i++) {
            if (arr[row][i] == "Q")
                return false;
        }
        for (int i = 0; i < n; i++) {
            if (arr[i][col] == "Q")
                return false;
        }
        while (row < n && col < n) {
            if (arr[row][col] == "Q")
                return false;
            row++;
            col++;
        }
        row = rowTemp;
        col = colTemp;
        while (row >= 0 && col >= 0) {
            if (arr[row][col] == "Q")
                return false;
            row--;
            col--;
        }
        row = rowTemp;
        col = colTemp;
        while (row < n && col >= 0) {
            if (arr[row][col] == "Q")
                return false;
            row++;
            col--;
        }
        row = rowTemp;
        col = colTemp;
        while (col < n && row >= 0) {
            if (arr[row][col] == "Q")
                return false;
            col++;
            row--;
        }
        return true;
    }

    public void boards(int n, int row, String[][] arr, List<List<String>> ans) {
        if (row == n) {
            List<String> inner = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String str = "";
                for (int j = 0; j < n; j++) {
                    str += arr[i][j];
                }
                inner.add(str);
            }
            ans.add(inner);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(arr, row, col, n)) {
                arr[row][col] = "Q";
                boards(n, row + 1, arr, ans);
                arr[row][col] = ".";
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {

        String[][] arr = new String[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = ".";
            }
        }
        List<List<String>> ans = new ArrayList<>(4);
        boards(n, 0, arr, ans);
        return ans;
    }
}