#include "binary_trees.h"

int _binary_tree_height(const binary_tree_t *tree);
void _func_on_level(const binary_tree_t *tree, int level, void (*func)(int));

/**
 * binary_tree_levelorder - goes through a binary tree using
 *+ level-order traversal
 *
 * @tree: a ptr to the root node of the tree to traverse.
 * @func: a ptr to the function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    int tree_height, i;

    if (tree == NULL || func == NULL)
        return;

    /*Get tree height*/
    tree_height = _binary_tree_height(tree);

    /*Iterate through all levels till you reach the height*/
    for (i = 1; i <= tree_height; i++)
    {
        /*Call the function on each level*/
        _func_on_level(tree, i, func);
    }
}

/**
 * _binary_tree_height - measures the height of a binary tree
 *
 * @tree: a ptr to the root node of the tree to find height.
 * Return: height of the tree or 0 if tree is NULL.
 */
int _binary_tree_height(const binary_tree_t *tree)
{
    int lt_height = 0, rt_height = 0;

    if (tree == NULL)
    {
        return (0);
    }

	/*Recursively call the func to calc. the height*/
	lt_height = _binary_tree_height(tree->left);
	rt_height = _binary_tree_height(tree->right);

	/*Compare for the maximum depth*/
	if (lt_height > rt_height)
		return (lt_height + 1);
	return (rt_height + 1);
}

/**
 * _func_on_level - calls a given function on a level of the binary tree.
 *
 * @tree: ptr to the root of the binary tree.
 * @level: the level to call the function.
 * @func: the function to call.
 */

void _func_on_level(const binary_tree_t *tree, int level, void (*func)(int))
{
    if (tree == NULL)
        return;
        
    if (level == 1)
        func(tree->n);
    else if (level > 1)
    {
        /*Call the function recursively*/
        _func_on_level(tree->left, level - 1, func);
        _func_on_level(tree->right, level - 1, func);
    }
}