class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class ChainingHashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        if self.table[index] is None:
            self.table[index] = Node(key, value)
        else:
            current = self.table[index]
            while current.next:
                current = current.next
            current.next = Node(key, value)

    def find(self, key):
        index = self.hash_function(key)
        current = self.table[index]
        while current:
            if current.key == key:
                return current.value
            current = current.next
        return None

    def delete(self, key):
        index = self.hash_function(key)
        current = self.table[index]
        prev = None
        while current:
            if current.key == key:
                if prev:
                    prev.next = current.next
                else:
                    self.table[index] = current.next
                return
            prev = current
            current = current.next

def main():
    # Example usage
    hash_table_with_replacement = ChainingHashTable(10)
    hash_table_without_replacement = ChainingHashTable(10)

    # Insert some key-value pairs
    hash_table_with_replacement.insert("Alice", "123-456-7890")
    hash_table_with_replacement.insert("Bob", "987-654-3210")
    hash_table_with_replacement.insert("Charlie", "555-123-4567")

    hash_table_without_replacement.insert("David", "999-888-7777")
    hash_table_without_replacement.insert("Eve", "111-222-3333")

    # Find and print values
    print("With replacement:")
    print("Alice's number:", hash_table_with_replacement.find("Alice"))
    print("Bob's number:", hash_table_with_replacement.find("Bob"))
    print("Charlie's number:", hash_table_with_replacement.find("Charlie"))

    print("\nWithout replacement:")
    print("David's number:", hash_table_without_replacement.find("David"))
    print("Eve's number:", hash_table_without_replacement.find("Eve"))

    # Delete a key
    hash_table_with_replacement.delete("Bob")
    print("\nAfter deleting Bob's number in hash_table_with_replacement:")
    print("Bob's number:", hash_table_with_replacement.find("Bob"))  # Should print None


if __name__ == "__main__":
    main()
