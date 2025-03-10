import heapq
import sys
input = sys.stdin.readline

INF = int(1e9)

def shortest_path(start):
    queue = []
    heapq.heappush(queue, (0, start)) 
    distances[start] = 0  
    
    while queue:
        current_distance, current_node = heapq.heappop(queue)
        if current_distance > distances[current_node]:
            continue

        for next_node, travel_cost in graph[current_node]:
            total_cost = current_distance + travel_cost
            if total_cost < distances[next_node]:
                distances[next_node] = total_cost
                heapq.heappush(queue, (total_cost, next_node))

n, d = map(int, input().split())

graph = [[] for _ in range(d + 1)]
distances = [INF] * (d + 1)

for i in range(d):
    graph[i].append((i + 1, 1))

for _ in range(n):
    start, end, length = map(int, input().split())
    if end <= d:
        graph[start].append((end, length))  

shortest_path(0)
print(distances[d])
