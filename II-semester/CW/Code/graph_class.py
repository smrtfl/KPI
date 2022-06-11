import networkx as nx
import matplotlib.pyplot as plt

class Graph:
    def __init__(self):
        self.__edges = [] # edges list
        self.__matrix = [] # adjacency matrix
        self.__vertices = [] # list of vertices
        self.__colors = ["red", "green", "blue", "yellow", "white", "fuchsia", "darkgreen", "cyan", "purple", "gray",
                         "violet", "orange", "lime", "lightblue", "brown", "olive", "magenta", "coral", "khaki", "wheat"] # list of all colors

    def init_matrix(self, n): # initialization of adjacency matrix
        for i in range(n):
            self.__matrix.append([])
            for j in range(n):
                self.__matrix[i].append(0)

    def set_matrix(self, row, col_str): # update adjacency matrix
        col = self.__vertices.index(col_str)
        self.__matrix[row][col], self.__matrix[col][row] = 1, 1

    def __vertices_degree(self): # get degree of vertices
        degree = []
        for i in range(len(self.__matrix)):
            degree.append(sum(self.__matrix[i]))

        return degree

    def add_vertex(self, vertex): # add vertex to list
        self.__vertices.append(vertex)

    def get_vertex(self, *args): # get vertex with index or get list of vertices
        if len(args) > 0:
            return self.__vertices[args[0]]
        else:
            return self.__vertices

    def add_edge(self, a, b): # add edge to list of edges
        if [a, b] not in self.__edges and [b, a] not in self.__edges:
            self.__edges.append([a, b])

    def check_isolated(self): # look for isolated vertices
        isolated = []
        for vertex in self.__vertices:
            observer = 0
            for edge in self.__edges:
                if vertex in edge:
                    observer += 1

            if observer == 0:
                isolated.append(vertex)

        return isolated

    def __color_graph(self, colors, seq): # color graph using sequence
        colors_seq = [''] * len(self.__vertices)
        for vertex in seq:
            set_color = colors[vertex]
            colors_seq[self.__vertices.index(vertex)] = set_color[0]
            curr_edges = self.__matrix[self.__vertices.index(vertex)]
            for i in range(len(curr_edges)):
                if curr_edges[i] == 1 and (set_color[0] in colors[self.__vertices[i]]) and vertex != self.__vertices[i]:
                    colors[self.__vertices[i]].remove(set_color[0])

        return colors_seq

    def visualize(self, *args): # visualization of graph
        vg = nx.Graph()
        for vertex in self.__vertices:
            vg.add_node(vertex)
        vg.add_edges_from(self.__edges)

        if len(args) > 0:
            nx.draw_networkx(vg, node_color=args[0])
            plt.gcf().canvas.set_window_title("Colored graph")
        else:
            nx.draw_networkx(vg)
            plt.gcf().canvas.set_window_title("Graph")

        plt.show()

    # coloring methods
    def greedy(self, info): # greedy algorithm
        n = len(self.__matrix)

        # set colors
        g_colors = {}
        for i in range(n):
            g_colors[self.__vertices[i]] = self.__colors[:n]

        greedy_coloring = self.__color_graph(g_colors, self.__vertices) # coloring graph

        # create info for greedy method
        greedy_used = []
        for color in self.__colors[:n]:
            if color in greedy_coloring:
                greedy_used.append(color)

        info.configure(text=f"Sequence of vertices to color (greedy method)\n{' '.join(self.__vertices)}\n\nUsed colors:\n{' '.join(greedy_used)}")

        self.visualize(greedy_coloring) # visualizing graph

    def backtracking_degree(self, info): # backtracking with degree heuristic
        n = len(self.__matrix)

        # set colors
        bd_colors = {}
        for i in range(n):
            bd_colors[self.__vertices[i]] = self.__colors[:n]

        # find optimal way to color graph
        bd_sequence = []
        indices = []
        index = 0
        for _ in range(n):
            max_degree = -1
            for i in range(n):
                if i not in indices and self.__vertices_degree()[i] > max_degree:
                    max_degree = self.__vertices_degree()[i]
                    index = i
            indices.append(index)
            bd_sequence.append(self.__vertices[index])

        # coloring graph
        bd_coloring = self.__color_graph(bd_colors, bd_sequence)

        # create info for backtracking (degree) method
        bd_used = []
        for color in self.__colors[:n]:
            if color in bd_coloring:
                bd_used.append(color)

        info.configure(text=f"Sequence of vertices to color (degree backtracking)\n{' '.join(bd_sequence)}\n\nUsed colors:\n{' '.join(bd_used)}")

        self.visualize(bd_coloring) # visualizing graph

    def backtracking_mrv(self, info): # backtracking with MRV heuristic
        n = len(self.__matrix)

        # set colors
        mrv_colors = {}
        for i in range(n):
            mrv_colors[self.__vertices[i]] = self.__colors[:n]

        # available colors for each vertex
        mrv_available = {}
        for i in range(n):
            mrv_available[self.__vertices[i]] = n

        # find optimal way to color graph
        mrv_sequence = []
        indices = []
        index = 0

        for _ in range(n):
            min_colors = 20
            for i in range(n):
                if i not in indices and mrv_available[self.__vertices[i]] < min_colors:
                    min_colors = mrv_available[self.__vertices[i]]
                    index = i
            indices.append(index)
            mrv_sequence.append(self.__vertices[index])
            for edge in self.__edges:
                if self.__vertices[index] in edge and self.__vertices[index] == edge[0] and edge[1] not in mrv_sequence:
                    mrv_available[edge[1]] -= 1
                elif self.__vertices[index] in edge and self.__vertices[index] == edge[1] and edge[0] not in mrv_sequence:
                    mrv_available[edge[0]] -= 1

        # coloring graph
        mrv_coloring = self.__color_graph(mrv_colors, mrv_sequence)

        # create info for backtracking (MRV) method
        mrv_used = []
        for color in self.__colors[:n]:
            if color in mrv_coloring:
                mrv_used.append(color)

        info.configure(text=f"Sequence of vertices to color (MRV backtracking)\n{' '.join(mrv_sequence)}\n\nUsed colors:\n{' '.join(mrv_used)}")

        self.visualize(mrv_coloring) # visualizing graph
