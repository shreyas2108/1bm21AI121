from queue import PriorityQueue

# Function to calculate the Manhattan distance heuristic
def manhattan_distance(state, goal_state):
    distance = 0
    for i in range(len(state)):
        for j in range(len(state)):
            if state[i][j] != 0:
                row, col = divmod(goal_state.index(state[i][j]), len(state))
                distance += abs(row - i) + abs(col - j)
    return distance

# Function to get possible moves
def get_moves(i, j, n):
    moves = []
    if i > 0:
        moves.append((i - 1, j, "UP"))
    if i < n - 1:
        moves.append((i + 1, j, "DOWN"))
    if j > 0:
        moves.append((i, j - 1, "LEFT"))
    if j < n - 1:
        moves.append((i, j + 1, "RIGHT"))
    return moves

# A* algorithm
def solve_puzzle(initial_state, goal_state):
    n = len(initial_state)
    initial_state = tuple(tuple(row) for row in initial_state)
    goal_state = tuple(tuple(row) for row in goal_state)
    
    visited = set()
    pq = PriorityQueue()
    pq.put((0, 0, initial_state, []))  # (f, g, state, path)
    
    while not pq.empty():
        _, g, current_state, path = pq.get()
        
        if current_state == goal_state:
            return path
        
        if current_state in visited:
            continue
        visited.add(current_state)
        
        zero_i, zero_j = next((i, j) for i, row in enumerate(current_state) for j, val in enumerate(row) if val == 0)
        for new_i, new_j, move in get_moves(zero_i, zero_j, n):
            new_state = [list(row) for row in current_state]
            new_state[zero_i][zero_j], new_state[new_i][new_j] = new_state[new_i][new_j], new_state[zero_i][zero_j]
            new_state = tuple(tuple(row) for row in new_state)
            
            if new_state not in visited:
                pq.put((g + 1 + manhattan_distance(new_state, goal_state), g + 1, new_state, path + [move]))

# Read input
k = int(input())
initial_state = [list(map(int, input().split())) for _ in range(k)]

# Generate the goal state
goal_state = [list(range(i * k + 1, (i + 1) * k + 1)) for i in range(k)]
goal_state[-1][-1] = 0

# Solve the puzzle
solution = solve_puzzle(initial_state, goal_state)

# Print the solution
print(len(solution))
for move in solution:
    print(move)
