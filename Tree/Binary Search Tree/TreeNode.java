public class TreeNode<T extends Comparable<T>> {
    T element;
    TreeNode<T> left;
    TreeNode<T> right;

    public TreeNode(T element) {
        this.element = element;
        this.left = null;
        this.right = null;
    }

    public TreeNode() {
        this.element = null;
        this.left = null;
        this.right = null;
    }

    void insert(T e) {
        if (element.compareTo(e) < 0) {
            if (right == null) {
                right = new TreeNode<>(e);
            } else {
                right.insert(e);
            }
        } else if (element.compareTo(e) > 0) {
            if (left == null) {
                left = new TreeNode<>(e);
            } else {
                left.insert(e);
            }
        }
    }

    TreeNode<T> delete(TreeNode<T> root, T key) {
        if (root == null) {
            return root;
        }

        if (root.element.compareTo(key) > 0) {
            root.left = delete(root.left, key);
        } else if (root.element.compareTo(key) < 0) {
            root.right = delete(root.right, key);
        } else {
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            } else {
                root.element = inSucc(root.right);
                root.right = delete(root.right, root.element);
            }
        }
        return root;
    }

    private T inSucc(TreeNode<T> temp) {
        T min = null;
        while (temp.left != null) {
            min = temp.left.element;
            temp = temp.left;
        }
        return min;
    }

    public TreeNode<T> search(T key) {// return tree from provided node
        if (this.element == null) {
            return null;
        } else {
            if (this.element.compareTo(key) == 0) {
                return this;
            }
        }

        if (this.element.compareTo(key) > 0) {
            if (this.left == null) {
                return null;
            }
            return left.search(key);
        } else {
            if (this.right == null) {
                return null;
            }
            return right.search(key);
        }
    }

    void searchKey(T key) {
        if (search(key) == null) {
            System.out.print("not found");
        } else {
            System.out.print("found");
        }
    }

    void visit() {
        System.out.print(this.element + " ");
    }

    void inorder(TreeNode<T> t) {
        if (t != null) {
            inorder(t.left);
            t.visit();
            inorder(t.right);
        }
    }

    void preorder(TreeNode<T> t) {
        if (t != null) {
            t.visit();
            preorder(t.left);
            preorder(t.right);
        }
    }

    void postorder(TreeNode<T> t) {
        if (t != null) {
            postorder(t.left);
            postorder(t.right);
            t.visit();
        }
    }

    public static void main(String[] args) {
        TreeNode<Integer> bt = new TreeNode<>(8);

        bt.insert(4);
        bt.insert(12);
        bt.insert(2);
        bt.insert(6);
        bt.insert(1);
        bt.insert(3);
        bt.insert(5);
        bt.insert(7);
        bt.insert(10);
        bt.insert(14);
        bt.insert(9);
        bt.insert(11);
        bt.insert(13);
        bt.insert(15);

        System.out.print("Inorder Traversial: ");
        bt.inorder(bt);
        System.out.println();

        System.out.print("Postorder Traversial: ");
        bt.postorder(bt);
        System.out.println();

        System.out.print("Preorder Traversial: ");
        bt.preorder(bt);
        System.out.println();

        System.out.print("Inorder traversial from a perticular key: ");
        bt.inorder(bt.search(4));
        System.out.println();

        System.out.print("Searching Invalid key: ");
        bt.searchKey(24);
        System.out.println();

        System.out.print("Deleting node from Tree: ");
        bt.inorder(bt.delete(bt, 12));
        System.out.println();
    }
}
