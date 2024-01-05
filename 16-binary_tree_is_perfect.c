#include "binary_trees.h"

int _binary_tree_size(const binary_tree_t *tree);
int _binary_tree_is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 *
 * @tree: ptr to the root node of the tree to check
 * Return: 1 - if isPerfect, 0 - ifNotPerfect or tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int lt_child_size, rt_child_size, rt_child_full, lt_child_full;
	int size_check = 0, full_check = 0;

	if (tree == NULL)
		return (0);

	/*Only one node*/
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	lt_child_size = _binary_tree_size(tree->left);
	rt_child_size = _binary_tree_size(tree->right);
	/*If left-subtree and right-subtree have equal sizes*/
	if (lt_child_size == rt_child_size)
		size_check = 1;

	rt_child_full = _binary_tree_is_full(tree->left);
	lt_child_full = _binary_tree_is_full(tree->right);
	/*And if left-subtree and the right subtree is full*/
	if (rt_child_full == 1 && lt_child_full == 1)
		full_check = 1;

	/*Then it's a perfect binary tree*/
	if (size_check == 1 && full_check == 1)
		return (1);

	return (0);
}

/**
 * _binary_tree_size - measures the size of a binary tree.
 *
 * @tree: ptr to the root node of the tree to measure.
 * Return: tree size or 0 if tree is NULL.
*/
int _binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + _binary_tree_size(tree->left) + _binary_tree_size(tree->right));
}

/**
 * _binary_tree_is_full - checks if a binary tree is full.
 *
 * @tree: ptr to the root node of the tree to check.
 * Return: 1 - tree isFull, 0 - tree isNotFull or NULL.
 */
int _binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/*Recursively check for nodes with left-child and right-child*/
	if ((tree->left != NULL) && (tree->right != NULL))
	{
		/*Traverse the sub-tree*/
		return (_binary_tree_is_full(tree->left) &&
				_binary_tree_is_full(tree->right));
	}

	/*Check for leaves - would be @ base of b-tree*/
	if ((tree->left == NULL && tree->right == NULL))
	{
		return (1);
	}

	/*Has only one child*/
	return (0);
}
