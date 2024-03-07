#include "binary_trees.h"

/**
 *  * avl_remove - Removes a node from an AVL tree
 *   * @root: Pointer to the root node of the tree for removing a node
 *    * @value: Value to remove in the tree
 *     *
 *      * Return: Pointer to the new root node of the tree after removing the value
 *       */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return NULL;

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		/* Node to delete found */
		if (root->left == NULL || root->right == NULL)
		{
			/* Node has at most one child */
			avl_t *temp = root->left ? root->left : root->right;
			if (temp == NULL)
			{
				/* Node has no child */
				temp = root;
				root = NULL;
			}
			else
			{
				/* Node has one child */
				*root = *temp; /* Copy the contents of the child */
			}
			free(temp);
		}
		else
		{
			/* Node has two children */
			avl_t *temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			root->n = temp->n; /* Copy the successor's value to the current node */
			root->right = avl_remove(root->right, temp->n); /* Delete the successor node */
		}
	}

	if (root == NULL)
		return NULL;

	/* Update the height of the current node */
	root = avl_balance_tree(root);

	return root;
}

