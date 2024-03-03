#include "binary_trees.h"

/**
 *  * binary_tree_depth - calculates the depth of the tree
 *   * @tree: POinter to the node
 *    *
 *     * Return: Depth of tree on Success
 *      */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t i = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent)
	{
		tree = tree->parent;
		i++;
	}

	return (i);
}
