public class Main {

    public static void main(String[] args) {
        Solution solution = new Solution();

        String delim = ";";
        Node root = new Node("root", new Node("left", new Node("left.left"), new Node()), new Node("right"));

        String out = solution.serialize(root, delim);
        System.out.println(out);

        System.out.println(solution.serialize(solution.deserialize(out, delim), delim));
    }
}
