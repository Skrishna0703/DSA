class TreeNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    def __init__(self):
        self.root = None

    def height(self, node):
        if node is None:
            return 0
        return node.height

    def update_height(self, node):
        node.height = 1 + max(self.height(node.left), self.height(node.right))

    def balance_factor(self, node):
        if node is None:
            return 0
        return self.height(node.left) - self.height(node.right)

    def rotate_right(self, y):
        x = y.left
        T2 = x.right

        x.right = y
        y.left = T2

        self.update_height(y)
        self.update_height(x)

        return x

    def rotate_left(self, x):
        y = x.right
        T2 = y.left

        y.left = x
        x.right = T2

        self.update_height(x)
        self.update_height(y)

        return y

    def insert(self, node, key, value):
        if node is None:
            return TreeNode(key, value)

        if key < node.key:
            node.left = self.insert(node.left, key, value)
        elif key > node.key:
            node.right = self.insert(node.right, key, value)
        else:
            node.value = value
            return node

        self.update_height(node)

        balance = self.balance_factor(node)

        if balance > 1:
            if key < node.left.key:
                return self.rotate_right(node)
            else:
                node.left = self.rotate_left(node.left)
                return self.rotate_right(node)

        if balance < -1:
            if key > node.right.key:
                return self.rotate_left(node)
            else:
                node.right = self.rotate_right(node.right)
                return self.rotate_left(node)

        return node

    def insert_key_value(self, key, value):
        self.root = self.insert(self.root, key, value)

    def find(self, node, key):
        if node is None:
            return None
        if key < node.key:
            return self.find(node.left, key)
        elif key > node.key:
            return self.find(node.right, key)
        else:
            return node.value

    def search(self, key):
        return self.find(self.root, key)

    def inorder_traversal(self, node, ascending=True):
        if node:
            if ascending:
                self.inorder_traversal(node.left)
            print(node.key, ":", node.value)
            if not ascending:
                self.inorder_traversal(node.right)

# Example usage:
tree = AVLTree()
tree.insert_key_value("apple", "A fruit")
tree.insert_key_value("banana", "A fruit")
tree.insert_key_value("carrot", "A vegetable")
tree.insert_key_value("zebra", "An animal")

print("Ascending order:")
tree.inorder_traversal(tree.root)
print("\nDescending order:")
tree.inorder_traversal(tree.root, ascending=False)

print("\nMeaning of 'banana':", tree.search("banana"))
