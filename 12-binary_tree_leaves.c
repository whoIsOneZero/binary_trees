#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 *
 * @tree: a ptr to the root node of the tree find num. of leaves.
 * Return: the number of leaves or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
	{
		/*Count this node and move to the children*/
		return (1 + binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
	}

	/*Don't count this node. Move to children*/
	return (binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
}
