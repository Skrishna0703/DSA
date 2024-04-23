class Patient:
    def __init__(self, name, priority):
        self.name = name
        self.priority = priority

class PriorityQueue:
    def __init__(self):
        self.queue = []

    def enqueue(self, patient):
        self.queue.append(patient)

    def dequeue(self):
        if not self.is_empty():
            max_priority_index = 0
            for i in range(1, len(self.queue)):
                if self.queue[i].priority > self.queue[max_priority_index].priority:
                    max_priority_index = i
            return self.queue.pop(max_priority_index)
        else:
            return None

    def is_empty(self):
        return len(self.queue) == 0

# Example usage:
priority_queue = PriorityQueue()

# Enqueue patients
priority_queue.enqueue(Patient("John", "Serious"))
priority_queue.enqueue(Patient("Alice", "Non-Serious"))
priority_queue.enqueue(Patient("Bob", "General Checkup"))

# Dequeue patients in order of priority
print("Patients served in order of priority:")
while not priority_queue.is_empty():
    patient = priority_queue.dequeue()
    print("Name:", patient.name, "| Priority:", patient.priority)

