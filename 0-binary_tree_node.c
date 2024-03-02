#include "binary_trees.h"

/**
 *  * binary_tree_node - Creates a binary tree node
 *   * @parent: POinter to the parent node
 *    * @value: value to put in the node
 *     *
 *      * Return: Pointer to the new node
 *       */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->n = value;

	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = parent;

	return (newnode);
}
