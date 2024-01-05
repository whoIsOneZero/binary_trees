#include "binary_trees.h"
/**
 * binary_tree_t *binary_trees_ancestor - finds the lowest common
 *+ ancestor of two nodes.
 *
 * @first: ptr to the first node.
 * @second: ptr to the second node.
 * Return: ptr to the lowest common ancestor or NULL if none found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    binary_tree_t *parent1, *parent2;

    if (first == NULL || second == NULL)
        return (NULL);

    parent1 = first->parent;
    parent2 = second->parent;

    /*Check if 'first' is a child of 'second'*/
    /*Return 'first' or 'second' based on which is the parent*/
    if ((first->left == second) || (first->right == second))
        return ((binary_tree_t *)first);

    if ((second->left == first) || (second->right == first))
        return ((binary_tree_t *)second);

    /*Is the parent of 'first' = the parent of 'second'?*/
    if (parent1 == parent2)
        return (parent1);
    /*Recursively call the fuction on 'first' and parent or 'second'*/
    return (binary_trees_ancestor(first, parent2));

    /*Is the parent of 'second' = the parent of 'first'?*/
    if (parent2 == parent1)
        return (parent2);
    /*Recursively call the function on 'second' and parent of 'fisrt'*/
    return (binary_trees_ancestor(second, parent1));
}