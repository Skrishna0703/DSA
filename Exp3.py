class TreeNode:
    def __init__(self, data):
        self.data = data
        self.children = []

    def add_child(self, child_node):
        self.children.append(child_node)

    def print_tree(self, level=0):
        print("  " * level + self.data)
        for child in self.children:
            child.print_tree(level + 1)

def main():
    # Construct the tree for the book
    book = TreeNode("Book")
    chapter1 = TreeNode("Chapter 1")
    chapter2 = TreeNode("Chapter 2")
    book.add_child(chapter1)
    book.add_child(chapter2)

    section1_1 = TreeNode("Section 1.1")
    section1_2 = TreeNode("Section 1.2")
    chapter1.add_child(section1_1)
    chapter1.add_child(section1_2)

    subsection1_1_1 = TreeNode("Subsection 1.1.1")
    subsection1_1_2 = TreeNode("Subsection 1.1.2")
    section1_1.add_child(subsection1_1_1)
    section1_1.add_child(subsection1_1_2)

    subsection1_2_1 = TreeNode("Subsection 1.2.1")
    section1_2.add_child(subsection1_2_1)

    section2_1 = TreeNode("Section 2.1")
    chapter2.add_child(section2_1)

    # Print the tree nodes
    print("Nodes of the book:")
    book.print_tree()

if __name__ == "__main__":
    main()
