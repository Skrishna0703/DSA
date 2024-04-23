class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        if not self.root:
            self.root = TreeNode(value)
        else:
            self._insert_recursive(self.root, value)

    def _insert_recursive(self, node, value):
        if value < node.data:
            if node.left is None:
                node.left = TreeNode(value)
            else:
                self._insert_recursive(node.left, value)
        elif value > node.data:
            if node.right is None:
                node.right = TreeNode(value)
            else:
                self._insert_recursive(node.right, value)

    def find_longest_path_length(self):
        return self._find_longest_path_length_recursive(self.root)

    def _find_longest_path_length_recursive(self, node):
        if node is None:
            return 0
        else:
            left_height = self._find_longest_path_length_recursive(node.left)
            right_height = self._find_longest_path_length_recursive(node.right)
            return max(left_height, right_height) + 1

    def find_minimum_value(self):
        current = self.root
        while current.left:
            current = current.left
        return current.data

    def swap_left_and_right(self):
        self._swap_left_and_right_recursive(self.root)

    def _swap_left_and_right_recursive(self, node):
        if node is not None:
            node.left, node.right = node.right, node.left
            self._swap_left_and_right_recursive(node.left)
            self._swap_left_and_right_recursive(node.right)

    def search(self, value):
        return self._search_recursive(self.root, value)

    def _search_recursive(self, node, value):
        if node is None or node.data == value:
            return node
        if value < node.data:
            return self._search_recursive(node.left, value)
        else:
            return self._search_recursive(node.right, value)

def main():
    bst = BinarySearchTree()

    # Constructing binary search tree
    values = [50, 30, 70, 20, 40, 60, 80]
    for value in values:
        bst.insert(value)

    # i. Insert new node
    bst.insert(55)

    # ii. Find number of nodes in the longest path from root
    longest_path_length = bst.find_longest_path_length()
    print("Number of nodes in the longest path from root:", longest_path_length)

    # iii. Minimum data value found in the tree
    minimum_value = bst.find_minimum_value()
    print("Minimum data value found in the tree:", minimum_value)

    # iv. Change the tree so that the roles of the left and right pointers are swapped at every node
    bst.swap_left_and_right()

    # v. Search a value
    search_value = 60
    if bst.search(search_value):
        print(f"{search_value} found in the tree")
    else:
        print(f"{search_value} not found in the tree")

if __name__ == "__main__":
    main()
