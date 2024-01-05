#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs right-rotation on a binary tree
 *
 * @tree: a ptr to the root node of the tree to rotate.
 * Return: a ptr to the new root node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *ptr, *t;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	ptr = tree->left;
	t = ptr->right;
	ptr->right = tree;
	tree->left = t;

	if (t)
	{
		t->parent = tree;
	}
	t = tree->parent;
	tree->parent = ptr;
	ptr->parent = t;

	if (t)
	{
		if (t->left == tree)
		{
			t->left = ptr;
		}
		else
		{
			t->right = ptr;
		}
	}

	return (ptr);
}
