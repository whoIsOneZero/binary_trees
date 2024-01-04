#include "binary_trees.h"

/**
 * binary_tree_depth - measures the distance of a node from the root.
 *
 * @tree: ptr to the node to measure depth.
 * Return: the depth, or 0 if tree is NULl
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	/*Traverse upwards till you reach the root.*/
	return (1 + binary_tree_depth(tree->parent));
}
