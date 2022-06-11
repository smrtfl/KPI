from graph_class import *
from root_config import root
from tkinter import ttk, messagebox
import pickle
import os

def initialization(): # create graph
    def start_create(frame):
        frame.destroy()
        create_graph()

    init_frame = ttk.Frame(root.access())
    init_frame.place(anchor='center', relx=0.5, rely=0.5)

    ttk.Label(init_frame, text="Welcome!", font=('Arial', 18)).pack()
    ttk.Label(init_frame, text="This is a program for creating and coloring undirected graph\nThere are 3 methods to color it:\ngreedy, backtracking (degree heuristic) and backtracking (MRV heuristic)", font=('Arial', 12), justify='center').pack()
    ttk.Label(init_frame, text="\nCreate graph now!", font=('Arial', 14)).pack()
    ttk.Button(init_frame, text="Create", command=lambda: start_create(init_frame), width=15,).pack(ipady=10, pady=10)

def close_app():
    if os.path.exists("files/graph_data.pickle"):
        os.remove("files/graph_data.pickle")

    root.destroy()

def create_graph():
    G = Graph()

    def end_create(): # destroy init page
        with open("files/graph_data.pickle", 'wb') as f: # write graph to binary file
            pickle.dump(G, f)

        output()

    def append_edge(vertex, edges_frame, end_list, i, n): # append edge to graph
        for edge_el in end_list.split():
            if edge_el in G.get_vertex():
                G.add_edge(vertex, edge_el)
                G.set_matrix(i, edge_el)

        if i < n - 1:
            edges_frame.destroy()
            fill_page(i + 1, n)
        else:
            end_create()

    def add_page(vertex, q_frame, i, n): # add edges for vertex
        q_frame.destroy()

        edges_frame = ttk.Frame(root.access())
        edges_frame.place(anchor='center', relx=0.5, rely=0.5)

        ttk.Label(edges_frame, text=f"List of vertices: {' '.join(G.get_vertex())}", font=('Arial', 12)).pack(pady=5)
        ttk.Label(edges_frame, text=f"Enter all edges for '{vertex}' separated by space", font=('Arial', 14)).pack()
        ttk.Label(edges_frame, text="(vertices out of list above will be skipped)", font=('Arial', 12)).pack()

        end_edge = ttk.Entry(edges_frame, width=10, font=("Arial", 10))
        end_edge.focus_force()
        end_edge.pack(pady=5)

        ttk.Button(edges_frame, text="Done", command=lambda: append_edge(vertex, edges_frame, end_edge.get(), i, n)).pack(pady=15)

    def skip_vertex(q_frame, i, n): # don't add edges for vertex
        q_frame.destroy()
        if i < n - 1:
            fill_page(i + 1, n)
        else:
            end_create()

    def fill_page(i, n): # fill graph
        q_frame = ttk.Frame(root.access())
        q_frame.place(anchor='center', relx=0.5, rely=0.5)

        ttk.Label(q_frame, text=f"Add edges for {G.get_vertex(i)}?", font=('Arial', 14)).pack(pady=5)

        q_buttons = ttk.Frame(q_frame)
        q_buttons.pack(pady=10)

        ttk.Button(q_buttons, text='Yes', command=lambda: add_page(G.get_vertex(i), q_frame, i, n)).grid(row=0, column=0, padx=5)
        ttk.Button(q_buttons, text='No', command=lambda: skip_vertex(q_frame, i, n)).grid(row=0, column=1, padx=5)

    def launch_func(i): # check conditions and start filling graph
        if n_entry.get().isdigit():
            num = int(n_entry.get())
            n_frame.destroy()

            if 20 >= num > 0:
                G.init_matrix(num)
                for c in range(65, 65 + num): # list of vertices (english alphabet)
                    G.add_vertex(chr(c))

                # for c in range(1, num + 1): # list of vertices (numbers)
                #     G.add_vertex(str(c))

                fill_page(i, num)
            else:
                if num > 20:
                    messagebox.showerror("Error", "Enter no more than 20 vertices!")
                elif num <= 0:
                    messagebox.showerror("Error", "Enter at least 1 vertex!")
                for el in root.winfo_children():
                    el.destroy()
                create_graph()
        else:
            messagebox.showerror("Error", "Enter a number between 1 and 20!")
            for el in root.winfo_children():
                el.destroy()
            create_graph()

    # start page
    n_frame = ttk.Frame(root.access())
    n_frame.place(anchor='center', relx=0.5, rely=0.5)

    ttk.Label(n_frame, text='Enter amount of vertices', font=('Arial', 14)).pack()
    n_entry = ttk.Entry(n_frame, width=10, font=("Arial", 10))
    n_entry.focus_force()
    n_entry.pack(pady=5)

    ttk.Button(n_frame, text='Next', command=lambda: launch_func(0)).pack(pady=15)

def output(): # visualize graph or select method to color it
    def reset_graph(frame): # reset graph and create again
        frame.destroy()
        create_graph()

    def output_graph(frame): # visualize graph with info
        if len(G.get_vertex()) > len(G.check_isolated()) > 0:
            frame.destroy()
            ttk.Label(root.access(), text=f"Isolated vertices:\n{' '.join(G.check_isolated())}", font=('Arial', 14), justify='center').place(anchor='center', relx=0.5, rely=0.5)
            G.visualize()
        elif len(G.check_isolated()) == len(G.get_vertex()):
            messagebox.showwarning("Warning", "Graph is empty. Reset it for visualizing and coloring!")
        else:
            G.visualize()

        output()

    def end_output(frame): # coloring option was chosen
        if len(G.check_isolated()) == len(G.get_vertex()):
            messagebox.showwarning("Warning", "Graph is empty. Reset it for visualizing and coloring!")
        else:
            frame.destroy()
            coloring_graph()

    for el in root.winfo_children():
        el.destroy()

    with open("files/graph_data.pickle", 'rb') as f: # get graph from binary file
        G = pickle.load(f)

    # output options
    output_frame = ttk.Frame(root.access())
    output_frame.place(anchor='center', relx=0.5, rely=0.5)

    ttk.Button(output_frame, text='Graph', command=lambda: output_graph(output_frame), width=15).grid(row=0, column=0, padx=10, pady=10, ipady=10)
    ttk.Button(output_frame, text='Coloring', command=lambda: end_output(output_frame), width=15).grid(row=0, column=1, padx=10, pady=10, ipady=10)

    ttk.Button(output_frame, text='Reset graph', command=lambda: reset_graph(output_frame), width=15).grid(row=1, column=0, padx=10, pady=10)
    ttk.Button(output_frame, text='Exit', command=close_app, width=15).grid(row=1, column=1, padx=10, pady=10)

def coloring_graph(): # choose method to color graph
    def greedy_start(): # launch greedy method
        choice_frame.destroy()

        coloring_info = ttk.Label(root.access(), font=("Arial", 14), justify='center') # greedy method info
        coloring_info.place(anchor='center', relx=0.5, rely=0.5)
        G.greedy(coloring_info)

        coloring_graph()

    def degree_start(): # launch backtracking method with degree heuristic
        choice_frame.destroy()

        coloring_info = ttk.Label(root.access(), font=("Arial", 14), justify='center') # backtracking (degree) info
        coloring_info.place(anchor='center', relx=0.5, rely=0.5)
        G.backtracking_degree(coloring_info)

        coloring_graph()

    def mrv_start(): # launch backtracking method with MRV heuristic
        choice_frame.destroy()

        coloring_info = ttk.Label(root.access(), font=("Arial", 14), justify='center') # backtracking (MRV) info
        coloring_info.place(anchor='center', relx=0.5, rely=0.5)
        G.backtracking_mrv(coloring_info)

        coloring_graph()

    with open("files/graph_data.pickle", 'rb') as f: # get graph from binary file
        G = pickle.load(f)

    for el in root.winfo_children():
        el.destroy()

    # method choosing page
    choice_frame = ttk.Frame(root.access())
    choice_frame.place(anchor='center', relx=0.5, rely=0.5)

    ttk.Label(choice_frame, text="Choose coloring method", font=("Arial", 14), justify='center').pack()

    choice_buttons = ttk.Frame(choice_frame)
    choice_buttons.pack(pady=20)

    ttk.Button(choice_buttons, text='Greedy', command=greedy_start, width=25).pack(ipady=10)

    backtracking_buttons = ttk.Frame(choice_buttons)
    backtracking_buttons.pack(pady=10)
    ttk.Button(backtracking_buttons, text='Backtracking (Degree)', command=degree_start, width=25).grid(row=0, column=0, padx=10, ipady=10)
    ttk.Button(backtracking_buttons, text='Backtracking (MRV)', command=mrv_start, width=25).grid(row=0, column=1, padx=10, ipady=10)

    # navigation buttons
    nav_frame = ttk.Frame(choice_frame)
    nav_frame.pack(pady=25)

    ttk.Button(nav_frame, text='Back', command=output).grid(row=0, column=0, padx=10)
    ttk.Button(nav_frame, text='Exit', command=close_app).grid(row=0, column=1, padx=10)
