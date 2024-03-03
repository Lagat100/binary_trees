#include "binary_trees.h"

/**
 *  * binary_tree_insert_right - Inserts a left node to parent
 *   * @parent: Pointer to the parent node
 *    * @value: Value to be inserted in the node
 *     *
 *      * Return: Pointer to the created node on Success
 *       */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node;

	if (parent == NULL)
		return (NULL);


	right_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (right_node == NULL)
		return (NULL);

	right_node->n = value;
	right_node->parent = parent;
	right_node->right = NULL;
	right_node->left = NULL;
	if (parent->right)
	{
		parent->right->parent = right_node;
		right_node->right = parent->right;
	}

	parent->right = right_node;

	return (right_node);
}
