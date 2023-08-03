import random
import networkx as nx
import matplotlib.pyplot as plt

n_nodes = [1,2,3,4,5]
edges = [(1,2), (2,3), (4,2), (1,4), (3,1), (2,5), (3,4), (5,3)]
weights = []

seed = 12

G = nx.DiGraph()
G.add_nodes_from(n_nodes)
G.add_edges_from(edges)
for u, v in G.edges():
  rand_weight = random.randint(1, 10)
  G[u][v]['weight'] = rand_weight
  weights.append(rand_weight)

def printGraph(g):
  # Cria figura para plotagem
  plt.figure(2) 
  # Define o layout
  pos = nx.spring_layout(g)
  # Plotar vertices de T
  nx.draw_networkx(g, pos, with_labels=True)
  # Plotar pesos das arestas
  labels = nx.get_edge_attributes(g, 'weight')
  nx.draw_networkx_edge_labels(g, pos, edge_labels=labels)
  # Exibir figura
  plt.show()


# cria um grafo com um nó que é seu próprio pai
def Make_set(v):
  T = nx.DiGraph()
  T.add_node(v, node=v, parent=v, rank=0)
  return T


def Find_set(G,v):
    print(v)
    v_p = G.nodes[v]["parent"]
    if not v_p == v:
        v_p = Find_set(G, v_p)
    return v_p
        

def Link(G,u,v):
    if G.nodes[u]["rank"] > G.nodes[v]["rank"]:
        G.nodes[v]["parent"] = u 
    else:
        G.nodes[u]["parent"] = v
        if G.nodes[u]["rank"] ==  G.nodes[v]["rank"]:
            G.nodes[v]["rank"] = G.nodes[v]["rank"] + 1
        

def Union(G, u,v):
    Link(G, Find_set(G,u), Find_set(G,v))



#G = Make_set(3)
#G.add_node(4, parent=3, rank=0)
#Find_set(G,4)

print(G.nodes(data=True))
# print(G.nodes[3]["parent"])


def MST_kruskall(G):
    T = nx.DiGraph()
    for node in n_nodes:
        Make_set(node)
    sortedG = sorted(G.edges(data=True))
    # sort nodes by atribute "weight"
    for u, v in sortedG.edges():
        if not Find_set(sortedG,u) == Find_set(sortedG,v):
            T.add_nodes([u,v])
            Union(sortedG, u,v)
    return T
    


MST_kruskall(G)