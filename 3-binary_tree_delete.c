#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree.
 * @tree: a ptr to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	if (tree->right != NULL)
	{
		/*Del right subtree recursively*/
		binary_tree_delete(tree->right);
	}

	if (tree->left != NULL)
	{
		/*Del left subtree recursively*/
		binary_tree_delete(tree->left);
	}

	/*Free current node after its children have been freed*/
	free(tree);

}
