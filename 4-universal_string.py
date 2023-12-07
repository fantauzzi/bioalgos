import matplotlib.pyplot as plt

plt.ion()
import networkx as nx


def prefix(kmer):
    return kmer[:-1]


def suffix(kmer):
    return kmer[1:]


def hamiltonian_path(graph, start, path=[]):
    path = path + [start]

    if len(path) == len(graph.nodes()):
        return path  # Hamiltonian path found

    for neighbor in graph.successors(start):
        if neighbor not in path:
            hamiltonian_path_found = hamiltonian_path(graph, neighbor, path)
            if hamiltonian_path_found:
                return hamiltonian_path_found

    return None  # Hamiltonian path not found


def make_overlap_graphs(kmers: list) -> dict:
    prefixes = set([prefix(kmer) for kmer in kmers])
    pref_to_kmer = {the_prefix: [] for the_prefix in prefixes}
    for kmer in kmers:
        pref_to_kmer[prefix(kmer)].append(kmer)

    adj_list = {kmer: [] for kmer in kmers}
    for kmer in kmers:
        adj_list[kmer] = pref_to_kmer[suffix(kmer)]
    return adj_list


nodes = [format(int(bin(i), 2), '04b') for i in range(16)]

graph_as_dict = make_overlap_graphs(nodes)

overlap_graph = nx.DiGraph()
for k, v in graph_as_dict.items():
    for item in v:
        overlap_graph.add_edge(k, item)
# assert nx.is_tournament(overlap_graph)
# nx.draw_networkx(overlap_graph)
# input()

# res = nx.tournament.hamiltonian_path(overlap_graph)
res = hamiltonian_path(overlap_graph, '0000')
print(res)
for item in res:
    print(item, sep='', end='')
print()
