def dfs(node, graph, visited, result):
    visited[node] = True
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(neighbor, graph, visited, result)
    result.insert(0, node)


def topological_sort(graph):
    visited = {node: False for node in graph}
    result = []
    for node in graph:
        if not visited[node]:
            dfs(node, graph, visited, result)
    return result


graph = {'A': ['B', 'C'], 'B': ['C', 'D'], 'C': ['D'], 'D': []}
print(topological_sort(graph))
