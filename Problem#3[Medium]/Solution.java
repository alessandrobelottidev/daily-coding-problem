import java.util.Stack;

public class Solution {
    private Stack<String> stack = new Stack<>();

    private void postOrderTraversal(Node n) {
        if (n.left != null)
            postOrderTraversal(n.left);
        else stack.add(null);

        if (n.right != null)
            postOrderTraversal(n.right);
        else stack.add(null);

        stack.add(n.value);
    }

    public String serialize(Node root, String delim) {
        postOrderTraversal(root);

        String out = "";
        while (!stack.empty()) {
            out += stack.pop() + delim;
        }

        return out;
    }

    public Node deserialize(String s, String delim) {
        if (s.length() <= delim.length()) return new Node();

        String[] list = s.split(delim);

        Node root = new Node(list[0], null, null);
        Node prev = null;
        Node current = root;

        int nullCount = 0;
        for (int i = 1; i < list.length; i++) {
            if (list[i].equals("null")) nullCount++;
            else {
                if (nullCount < 2) {
                    current.right = new Node(list[i]);
                    prev = current;
                    current = current.right;
                } else if (nullCount == 2) {
                    prev.left = new Node(list[i]);
                    current = prev.left;
                } else if (nullCount == 3) {
                    current.right = new Node();
                    current.left = new Node(list[i]);
                    current = current.left.right;
                }
                nullCount = 0;
            }
        }

        return root;
    }
}

