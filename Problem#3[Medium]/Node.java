public class Node {
    String value;
    Node left, right;

    public Node() {
        this.value = null;
        left = null;
        right = null;
    }

    public Node(String value) {
        this.value = value;
        left = null;
        right = null;
    }

    public Node(String value, Node left, Node right) {
        this.value = value;
        this.left = left;
        this.right = right;
    }
}
