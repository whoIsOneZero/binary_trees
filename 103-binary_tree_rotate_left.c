#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left-rotation on a binary tree.
 *
 * @tree: a ptr to the root node of the tree.
 * Return: a ptr to the new root node.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *ptr, *t;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	ptr = tree->right;
	t = ptr->left;
	ptr->left = tree;
	tree->right = t;

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
