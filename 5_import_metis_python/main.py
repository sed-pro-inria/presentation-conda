import networkx as nx
import metis

G = metis.example_networkx()

mg =  metis.networkx_to_metis(G)

(edgecuts, parts) = metis.part_graph(G, 3)
print("edgecuts", edgecuts)
print("parts", parts)

colors = ['red','blue','green']
for i, p in enumerate(parts):
    G.node[i]['color'] = colors[p]
nx.draw(G)

nx.write_dot(G, 'example.dot') # Requires pydot or pygraphviz
