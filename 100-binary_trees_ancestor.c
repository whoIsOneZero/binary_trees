#include "binary_trees.h"
/**
 * binary_tree_t *binary_trees_ancestor - finds the lowest common
 *+ ancestor of two nodes.
 *
 * @first: ptr to the first node.
 * @second: ptr to the second node.
 * Return: ptr to the lowest common ancestor or NULL if none found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *parent1, *parent2;

	if (first == NULL || second == NULL)
		return (NULL);

	/*Both point to the same node*/
	if (first == second)
		return ((binary_tree_t *)first);

	parent1 = first->parent;
	parent2 = second->parent;

	/*Check if parents are the root node OR*/
	/*If one of the nodes it the parent of the other OR*/
	/*One parent exists and the other parent has no parent*/
	if (parent1 == NULL || first == parent2 ||
			(!parent1->parent && parent2 != NULL))
	{
		return (binary_trees_ancestor(first, parent2));
	}
	else if (parent2 == NULL || second == parent1 ||
			(!parent2->parent && parent1 != NULL))
	{
		return (binary_trees_ancestor(parent1, second));
	}
	return (binary_trees_ancestor(parent1, parent2));
}
