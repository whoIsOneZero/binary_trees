#include "binary_trees.h"
#include <stdio.h>

int _binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 *
 * @tree: ptr to the root node of the tree to measure b. factor
 * Return: the balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int left, right;

    if (tree == NULL)
        return (0);

    /*Get height of left child*/
    left = _binary_tree_height(tree->left);
    /*Get height of right child*/
    right = _binary_tree_height(tree->right);

    /* printf("Left: %d.\nRight: %d.\n", left, right); */

    return (left - right);
}


/**
 * _binary_tree_height - measures the height of a binary tree
 *
 * @tree: a ptr to the root node of the tree to find height.
 * Return: height of the tree or 0 if tree is NULL
 */
int _binary_tree_height(const binary_tree_t *tree)
{
	int lt_height = 0;
	int rt_height = 0;

	if (tree == NULL)
        return (-1);
	
    if (tree->left == NULL && tree->right == NULL)
		return (0);

	/*Recursively call the func to calc. the height*/
	lt_height = _binary_tree_height(tree->left);
	rt_height = _binary_tree_height(tree->right);

	/*Compare for the maximum depth*/
	if (lt_height > rt_height)
		return (lt_height + 1);
	return (rt_height + 1);
}
