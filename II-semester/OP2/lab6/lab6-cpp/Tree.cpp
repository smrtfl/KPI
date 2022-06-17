#include "Tree.h"

Tree::Tree()
{
	root = NULL;
}

void Tree::insert(int num) // initialize creating new level
{
    if (root != NULL)
        insert(num, root);
    else
    {
        root = new node;
        root->data = num;
        root->left = NULL;
        root->right = NULL;
    }
}

void Tree::insert(int num, node* leaf) // insert num siblings to the new level
{
    if (leaf->left != NULL && leaf->right != NULL)
    {
        insert(num, leaf->left);
        insert(num, leaf->right);
    }
    else
    {
        leaf->left = new node;
        leaf->left->data = num;
        leaf->left->left = NULL;
        leaf->left->right = NULL;

        leaf->right = new node;
        leaf->right->data = num;
        leaf->right->left = NULL;
        leaf->right->right = NULL;
    }
}

void Tree::destroy_tree() // initialize destroying tree
{
    destroy_tree(root);
}

void Tree::destroy_tree(node* leaf) // destroy tree
{
    if (leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void Tree::output() // initialize tree output
{
    graphical_tree(root, NULL, false);
}

void Tree::show_trunk(Trunk* curr_trunk) // output trunk
{
    if (curr_trunk == NULL) {
        return;
    }

    show_trunk(curr_trunk->prev_trunk);
    cout << curr_trunk->connection;
}

void Tree::graphical_tree(node* curr_root, Trunk* previous, bool is_right) // output tree horizontally
{
    if (curr_root == NULL) {
        return;
    }

    string prev_connection = "    ";
    Trunk* curr_trunk = new Trunk(previous, prev_connection);

    graphical_tree(curr_root->right, curr_trunk, true);

    if (!previous) {
        curr_trunk->connection = "---";
    }
    else if (is_right)
    {
        curr_trunk->connection = ".---";
        prev_connection = "   |";
    }
    else if (previous)
    {
        curr_trunk->connection = "`---";
        previous->connection = prev_connection;
    }

    show_trunk(curr_trunk);
    cout << " " << curr_root->data << endl;

    if (previous) {
        previous->connection = prev_connection;
    }
    curr_trunk->connection = "   |";

    graphical_tree(curr_root->left, curr_trunk, false);
}