#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree.
 *
 * @tree: ptr to the root node of the tree to measure.
 * Return: tree size or 0 if tree is NULL.
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
		return (0);

	/* printf("%d\n", tree->n); */
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}