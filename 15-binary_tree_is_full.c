#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 *
 * @tree: ptr to the root node of the tree to check.
 * Return: 1 - tree isFull, 0 - tree isNotFull or NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/*Recursively check for nodes with left-child and right-child*/
	if ((tree->left != NULL) && (tree->right != NULL))
	{
		/*Traverse the sub-tree*/
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	}

	/*Check for leaves - would be @ base of b-tree*/
	if ((tree->left == NULL && tree->right == NULL))
	{
		return (1);
	}

	/*Has only one child*/
	return (0);
}
