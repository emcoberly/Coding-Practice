"""
Print map of amicable numbers
"""

# import matplotlib as mpl
import matplotlib.pyplot as plt

# from matplotlib.figure import Figure


# fig, ax = plt.subplots()

# ax = fig.add_subplot(111)

# x = 0
# y = 0

# circle = plt.Circle((x, y), radius=0.1)
# ax.add_patch(circle)

# label = ax.annotate("1184", xy=(x,y), fontsize=30, verticalalignment="center", horizontalalignment="center")

# ax.axis('off')
# ax.set_aspect('equal')
# ax.autoscale_view()

# plt.show()

import networkx as nx

graph = nx.DiGraph()
graph.add_nodes_from([1184, 1210], color="red")
# graph.add_edges_from([("1184","1210"),("1210","1184")])
# plt.tight_layout()
nx.draw_networkx(graph, node_color="lightgreen", node_size=1000, arrows=True)
plt.savefig("amicable_map.png", format="PNG")
plt.clf()
