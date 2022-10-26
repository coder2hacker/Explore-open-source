class Solution {
	public int sumNumbers(TreeNode root) {
		return helper(root, 0);
	}

	public static int helper(TreeNode root, int num) {
		if (root == null)
			return 0;
		if (root.left == null && root.right == null) {
			num = (num * 10) + root.val;        // num = (1*10) + 1; => num = 12;
			return num;
		}
		num = (num * 10) + root.val;  // num = (0 * 10)+ 1; => num = 1
		int a = helper(root.left, num); // a = num (12)
		int b = helper(root.right, num); // Similarly, b = num(13)
        return (a+b);
	}
}
