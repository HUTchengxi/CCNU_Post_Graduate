import java.util.Stack;

public class Solution {

    public static void main(String[] args) {


    }

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    int pre;
    int ans;
    public int minDiffInBST(TreeNode root) {

        pre = -1;
        ans = 100000;
        // 中序遍历，左根右，对于二叉搜索树而言，最小距离一定是相邻的两个节点之差
        postTravel(root);
        return ans;
    }

    public void postTravel(TreeNode root) {

        if (root == null) {
            return;
        }
        postTravel(root.left);
        if(pre == -1) {
            pre = root.val;
        } else {
            int temp = root.val - pre;
            ans = ans > temp ? temp : ans;
            pre = root.val;
        }
        postTravel(root.right);
    }

    public int minDiffInBST2(TreeNode root) {

        int result = 100000;

        int[] nodes = new int[100];

        // 遍历保存
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        int idx = 0;
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            int val = node.val;
            for (int i = 0; i < idx; i++) {
                int temp = val > nodes[i] ? val - nodes[i] : nodes[i] - val;
                if (temp == 1) {
                    return 1;
                }
                result = result > temp ? temp : result;
            }
            nodes[idx++] = val;

            if (node.left != null) {
                stack.push(node.left);
            }
            if (node.right != null) {
                stack.push(node.right);
            }
        }

        return result;
    }

}