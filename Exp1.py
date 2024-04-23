class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]
    def hash_function(self, key):
        return hash(key) % self.size
    def insert(self, key, value):
        index = self.hash_function(key)
        self.table[index].append((key, value))
    def search_linear_probing(self, key):
        index = self.hash_function(key)
        comparisons = 1
        while self.table[index] and self.table[index][0][0] != key:
            index = (index + 1) % self.size
            comparisons += 1
        return comparisons
    def search_separate_chaining(self, key):
        index = self.hash_function(key)
        comparisons = 1
        for k, _ in self.table[index]:
            if k == key:
                return comparisons
            comparisons += 1
        return comparisons
def main():
    telephone_book = HashTable(10)  # Adjust size as needed
    telephone_book.insert("Alice", "123-456-7890")
    telephone_book.insert("Bob", "987-654-3210")
    telephone_book.insert("Charlie", "555-123-4567")
    telephone_book.insert("David", "999-888-7777")
    # Search for telephone numbers and compare collision handling techniques
    names_to_search = ["Alice", "Bob", "Charlie", "David"]
    total_linear_probing_comparisons = 0
    total_separate_chaining_comparisons = 0
    for name in names_to_search:
        total_linear_probing_comparisons += telephone_book.search_linear_probing(name)
        total_separate_chaining_comparisons += telephone_book.search_separate_chaining(name)
    print("Total comparisons using linear probing:", total_linear_probing_comparisons)
    print("Total comparisons using separate chaining:", total_separate_chaining_comparisons)
if __name__ == "__main__":
    main()
