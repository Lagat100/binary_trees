#include "binary_trees.h"

/**
 *  * binary_tree_insert_left - Inserts a left node to parent
 *   * @parent: Pointer to the parent node
 *    * @value: Value to be inserted in the node
 *     *
 *      * Return: Pointer to the created node on Success
 *       */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node;

	if (parent == NULL)
		return (NULL);


	left_node = malloc(sizeof(binary_tree_t));
	if (left_node == NULL)
		return (NULL);

	left_node->n = value;
	left_node->parent = parent;
	left_node->left = NULL;
	left_node->right = NULL;
	if (parent->left != NULL)
	{
		left_node->left = parent->left;
		left_node->left->parent = left_node;
	}

	parent->left = left_node;

	return (left_node);
}
