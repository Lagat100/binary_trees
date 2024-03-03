#include "binary_trees.h"

/**
 *  * binary_tree_postorder - Goes through the tree using postorder
 *   * @tree: POinter to the tree
 *    * @func: Pointer to the print function
 *     */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
