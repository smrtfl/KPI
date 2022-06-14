#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

struct Trunk
{
    Trunk* prev_trunk;
    string connection;

    Trunk(Trunk* prev_trunk, string connection)
    {
        this->prev_trunk = prev_trunk;
        this->connection = connection;
    }
};

class Tree
{
public:
    Tree();

    void insert(int);
    void destroy_tree();
    void output();

private:
    void insert(int, node*);
    void destroy_tree(node*);

    void show_trunk(Trunk*);
    void graphical_tree(node*, Trunk*, bool);

    node* root;
};