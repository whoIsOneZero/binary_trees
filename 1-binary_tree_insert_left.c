#include "binary_trees.h"

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *left_child;

    if (parent == NULL )
        return (NULL);

    /*Create the new node called left_child*/
    left_child = binary_tree_node(parent, value);
    /*Node creation failed*/
    if (left_child == NULL)
        return (NULL);

    /*`parent` already has a left_child*/
    if (parent->left != NULL)
    {
        /*Set left_child's left-child to be parent's left-child*/
        left_child->left = parent->left;

        /*Set parent->left to left_child*/
        parent->left = left_child;
    }
    else
        parent->left = left_child;

    return (left_child);
}