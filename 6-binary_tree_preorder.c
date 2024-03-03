#include "binary_trees.h"

/**
 *  * binary_tree_preorder - Goes through the tree using pretorder
 *   * @tree: POinter to the tree
 *    * @func: Pointer to the print function
 *     */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
