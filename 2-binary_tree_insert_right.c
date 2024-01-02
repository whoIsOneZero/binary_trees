#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node as a right-child of another node.
 * 
 * @parent: node where to insert the right-child. 
 * @value: value to store in the new node. 
 * Return: ptr created child node [SUCCES] or NULL [FAILURE] 
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *right_child;

    if (parent == NULL )
        return (NULL);

    /*Create the new node called right_child*/
    right_child = binary_tree_node(parent, value);
    /*Node creation failed*/
    if (right_child == NULL)
        return (NULL);

    /*`parent` already has a right_child*/
    if (parent->right != NULL)
    {
        /*Set right_child's right-child to be parent's right-child*/
        right_child->right = parent->right;

        /*Set parent->right to right_child*/
        parent->right = right_child;
    }
    else
        parent->right = right_child;

    return (right_child);
}