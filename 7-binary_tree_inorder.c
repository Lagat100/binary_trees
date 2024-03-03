#include "binary_trees.h"

/**
 *  * binary_tree_inorder - Goes through the tree using inorder
 *   * @tree: POinter to the tree
 *    * @func: Pointer to the print function
 *     */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);

}
