#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a bin tree using pre-order traversal.
 *
 * @tree: a ptr to the root node of the tree to traverse
 * @func: ptr to function to call for each node. the value in the node
 *+ must be passed as a parameter to that function
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
		return;

    binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
    
    /*Apply function to current node.*/
	func(tree->n);
}