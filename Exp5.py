class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def construct_expression_tree(prefix_expression):
    stack = []

    for char in reversed(prefix_expression):
        if char.isalnum():
            stack.append(TreeNode(char))
        else:
            node = TreeNode(char)
            node.left = stack.pop()
            node.right = stack.pop()
            stack.append(node)

    return stack.pop()

def post_order_traversal(root):
    stack = []
    result = []
    current = root

    while stack or current:
        if current:
            if current.right:
                stack.append(current.right)
            stack.append(current)
            current = current.left
        else:
            node = stack.pop()
            if node.right and stack and node.right == stack[-1]:
                stack[-1] = node
                current = node.right
            else:
                result.append(node.data)
    
    return result

def delete_tree(root):
    if root:
        delete_tree(root.left)
        delete_tree(root.right)
        del root

def main():
    prefix_expression = "+-a*bc/def"
    root = construct_expression_tree(prefix_expression)
    
    print("Post-order traversal:")
    print(" ".join(post_order_traversal(root)))

    # Delete the entire tree
    delete_tree(root)
    print("Tree deleted successfully")

if __name__ == "__main__":
    main()
