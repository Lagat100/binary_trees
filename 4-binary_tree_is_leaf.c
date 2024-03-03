#include "binary_trees.h"


/**
 *  * binary_tree_is_leaf - Checks if node is leaf
 *   * @node: Pointer to the node
 *    *
 *     * Return: On Success 0 and 1 on failure
 *      */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}
