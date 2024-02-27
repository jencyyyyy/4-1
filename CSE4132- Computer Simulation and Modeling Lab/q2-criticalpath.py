# Network diagram
import networkx as nx
import matplotlib.pyplot as plt

# Create a graph
G = nx.DiGraph()

# Add nodes
G.add_nodes_from(['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'])

# Add edges
G.add_edges_from([('A', 'D'), ('A', 'F'), ('B', 'E'), ('C', 'G'), ('D', 'G'), ('E', 'G'), ('F', 'G'), ('G', 'H')])

# Set edge weights
G.edges['A', 'D']['weight'] = 11
G.edges['A', 'F']['weight'] = 11
G.edges['B', 'E']['weight'] = 3
G.edges['C', 'G']['weight'] = 10
G.edges['D', 'G']['weight'] = 3
G.edges['E', 'G']['weight'] = 1
G.edges['F', 'G']['weight'] = 2
G.edges['G', 'H']['weight'] = 1

# Draw the graph
nx.draw(G, with_labels=True)
plt.show()

# Critical path
critical_path = nx.critical_path(G)
print(critical_path)