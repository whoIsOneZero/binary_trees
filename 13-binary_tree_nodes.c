#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with >= 1 child in a binary tree.
 *
 * @tree: ptr to the root node of the tree to count the num of nodes.
 * Return: num. of nodes or 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		/*Don't count this node. Return to parent.*/
		return (binary_tree_nodes(tree->left) +
				binary_tree_nodes(tree->right));
	}

	/*Count this node and move to the children*/
	return (1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
}
