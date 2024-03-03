#include "binary_trees.h"

/**
 *  * binary_tree_is_root - Check if a node is a root
 *   * @node: POinter to the node
 *    * Return: On Success 0 and 1 on failure
 *     */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);

	return (0);
}
