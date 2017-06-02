class Node {
    char data;
    Node leftChild;
    Node rightChild;

    Node(char data) {
        this.data = data;
        leftChild = null;
        rightChild = null;
    }
}
public class BuildTree {

    private Node buildTree(String pre, String mid) throws Exception {
        if(pre.length()==0){
            return null;
        }
        int pos = mid.indexOf(pre.charAt(0));
        if (pos < 0) {
            throw new Exception("build tree failed");
        }
        Node root = new Node(pre.charAt(0));
        root.leftChild = buildTree(pre.substring(1, pos+1), mid.substring(0, pos));
        root.rightChild = buildTree(pre.substring(pos+1), mid.substring(pos+1));
        return root;
    }

    private void postOrder(Node root) {
        if (root == null) {
            return;
        }
        postOrder(root.leftChild);
        postOrder(root.rightChild);
        System.out.print(root.data);
    }

    public void getPostOrder(String pre, String mid) {
        Node root = null;
        try {
            root = buildTree(pre, mid);
        } catch (Exception e) {
            System.out.println("build tree failed");
        }
        postOrder(root);
    }

    public static void main(String... args) {
        new BuildTree().getPostOrder("ABDEFCGH", "EDFBAGCH");
    }
}
