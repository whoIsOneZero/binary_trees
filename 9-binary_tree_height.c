#include "binary_trees.h"

/**
 * size_t binary_tree_height - measures the height of a binary tree
 *
 * @tree: a ptr to the root node of the tree to find height. 
 * Return: height of the tree or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lt_height = 0;
	size_t rt_height = 0;
    
    if ((tree == NULL) ||
    (tree->left == NULL && tree->right == NULL))
        return (0);
    
    /*Recursively call the func to calc. the height*/
    lt_height = binary_tree_height(tree->left);
    rt_height = binary_tree_height(tree->right);

    /*Compare for the maximum depth*/
	if (lt_height > rt_height)
		return (lt_height + 1);
	return (rt_height + 1);
}