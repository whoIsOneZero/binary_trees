#include "binary_trees.h"

size_t _calc_height(const binary_tree_t *tree);
int _is_avl(const binary_tree_t *tree, int lo, int hi);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree.
 *
 * @tree: a ptr to the root node of the tree to check.
 * Return: 1 isValid AVL tree, or 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_is_avl(tree, INT_MIN, INT_MAX));
}

/**
 * _calc_height - measures the height of a binary tree.
 *
 * @tree: a ptr to the root node of the tree to measure the height.
 * Return: height of the tree or 0 if tree is NULL.
 */
size_t _calc_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lt = 0, rt = 0;

		lt = tree->left ? 1 + _calc_height(tree->left) : 1;
		rt = tree->right ? 1 + _calc_height(tree->right) : 1;
		return ((lt > rt) ? lt : rt);
	}
	return (0);
}

/**
 * _is_avl - checks if binary tree is a valid AVL tree.
 *
 * @tree: a ptr to the root node of the tree to check.
 * @lo: the value of the smallest node visited.
 * @hi: the value of the largest node visited.
 * Return: 1 isValid AVL tree, otherwise, 0.
 */
int _is_avl(const binary_tree_t *tree, int lo, int hi)
{
	size_t lft, rgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);

		lft = _calc_height(tree->left);
		rgt = _calc_height(tree->right);
		diff = lft > rgt ? lft - rgt : rgt - lft;

		if (diff > 1)
			return (0);

		return (_is_avl(tree->left, lo, tree->n - 1) &&
			_is_avl(tree->right, tree->n + 1, hi));
	}
	return (1);
}