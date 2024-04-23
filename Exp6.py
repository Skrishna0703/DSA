from collections import defaultdict, deque
class Graph:
    def __init__(self):
        self.adj_matrix = defaultdict(dict)
        self.adj_list = defaultdict(list)

    def add_edge(self, start, end, weight=1):
        self.adj_matrix[start][end] = weight
        self.adj_matrix[end][start] = weight
        self.adj_list[start].append(end)
        self.adj_list[end].append(start)

    def dfs_matrix(self, start):
        visited = set()
        stack = [start]

        while stack:
            vertex = stack.pop()
            if vertex not in visited:
                print(vertex, end=" ")
                visited.add(vertex)
                for neighbor in reversed(self.adj_matrix[vertex]):
                    if neighbor not in visited:
                        stack.append(neighbor)

    def bfs_list(self, start):
        visited = set()
        queue = deque([start])

        while queue:
            vertex = queue.popleft()
            if vertex not in visited:
                print(vertex, end=" ")
                visited.add(vertex)
                for neighbor in self.adj_list[vertex]:
                    if neighbor not in visited:
                        queue.append(neighbor)

def main():
    # Create a graph representing the map of the area around the college
    g = Graph()
    g.add_edge("College", "Park", 1)
    g.add_edge("Park", "Library", 1)
    g.add_edge("Library", "Market", 1)
    g.add_edge("Park", "Gym", 1)
    g.add_edge("Gym", "Cafe", 1)
    g.add_edge("Cafe", "Restaurant", 1)

    print("Depth-First Search using adjacency matrix:")
    g.dfs_matrix("College")

    print("\n\nBreadth-First Search using adjacency list:")
    g.bfs_list("College")

if __name__ == "__main__":
    main()
