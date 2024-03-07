/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        //Iterative code
        
       ArrayList < Integer > preOrder = new ArrayList < Integer > ();
        if (root == null)
            return preOrder;

        Stack < TreeNode > s = new Stack < > ();
        s.push(root);

        while (!s.isEmpty()) {
            TreeNode topNode = s.peek();
            preOrder.add(topNode.val);
            s.pop();
            if (topNode.right != null)
                s.push(topNode.right);
            if (topNode.left != null)
                s.push(topNode.left);
        }
        return preOrder;
     }
    
}