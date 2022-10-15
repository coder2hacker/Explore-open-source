// https://leetcode.com/problems/regular-expression-matching/

class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        Boolean[][] M = new Boolean[m+1][n]; // Why Boolean: null indicates the sub-problem not processed yet
        return dfs(s, p, 0, 0, m, n, M);  // The problem: to match s[i, m), p[j, n)
    }

    // the sub-problem: to match[i, m
    private boolean dfs(String s, String p, int i, int j, int m, int n, Boolean[][] M) {
        if (j == n) return i == m;
        if (M[i][j] != null) return M[i][j];

        char c2 = p.charAt(j);
        if (j < n - 1 && p.charAt(j + 1) == '*')
            return M[i][j] = dfs(s, p, i, j+2, m, n, M) || // do not match 'x*' , x means any char or . (use'*' as 0 char)
                    i < m && match(s.charAt(i), c2) && dfs(s, p, i+1, j, m, n, M); // match 1 char in string for '*'

        return M[i][j] = i < m && match(s.charAt(i), c2) && dfs(s, p, i+1, j+1, m, n, M); // match 1 char from both sides
    }

    private boolean match(char c1, char c2) {
        if (c2 == '.') return true;
        return c1 == c2;
    }
}
