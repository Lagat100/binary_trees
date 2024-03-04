#include "binary_trees.h"

/**
 *  * bst_insert - Inserts a value in a Binary Search Tree (BST)
 *   * @tree: Double pointer to the root node of the BST to insert the value
 *    * @value: Value to store in the node to be inserted
 *     *
 *      * Return: Pointer to the created node, or NULL on failure
 *       */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *parent;

	if (tree == NULL)
		return (NULL);

	parent = NULL;
	new_node = *tree;

	Traverse the tree to find the appropriate position
		while (new_node != NULL)
		{
			parent = new_node;
			if (value < new_node->n)
				new_node = new_node->left;
			else if (value > new_node->n)
				new_node = new_node->right;
			else // value already exists in the tree
				return (NULL);
		}

	// Create a new node and assign the value
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	// If the tree is empty, the new node becomes the root
	if (parent == NULL)
		*tree = new_node;
	else if (value < parent->n) // Insert as left child
		parent->left = new_node;
	else // Insert as right child
		parent->right = new_node;

	return (new_node);
}

