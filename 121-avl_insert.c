#include "binary_trees.h"

/**
 *  * binary_tree_height - Measures the height of a binary tree
 *   * @tree: Pointer to the root node of the tree
 *    *
 *     * Return: Height of the tree
 *      */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 *  * binary_tree_balance - Computes the balance factor of a binary tree node
 *   * @tree: Pointer to the root node of the tree
 *    *
 *     * Return: Balance factor of the tree
 *      */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 *  * avl_rotate_right - Performs a right rotation on an AVL tree
 *   * @tree: Pointer to the root node of the tree
 *    *
 *     * Return: Pointer to the new root node of the tree after rotation
 *      */
avl_t *avl_rotate_right(avl_t *tree)
{
	avl_t *new_root = tree->left;

	tree->left = new_root->right;
	new_root->right = tree;

	return new_root;
}

/**
 *  * avl_rotate_left - Performs a left rotation on an AVL tree
 *   * @tree: Pointer to the root node of the tree
 *    *
 *     * Return: Pointer to the new root node of the tree after rotation
 *      */
avl_t *avl_rotate_left(avl_t *tree)
{
	avl_t *new_root = tree->right;

	tree->right = new_root->left;
	new_root->left = tree;

	return new_root;
}

/**
 *  * avl_insert_recursive - Recursively inserts a value into an AVL tree
 *   * @tree: Pointer to the root node of the tree
 *    * @value: Value to insert into the tree
 *     *
 *      * Return: Pointer to the root node of the tree after insertion
 *       */
avl_t *avl_insert_recursive(avl_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
	}
	else if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, value);
	}
	else
	{
		return (NULL); /* Value already exists */
	}

	/* Update the height of the current node */
	*tree = avl_balance_tree(*tree);

	return (*tree);
}

/**
 *  * avl_insert - Inserts a value into an AVL tree
 *   * @tree: Double pointer to the root node of the AVL tree
 *    * @value: Value to insert into the tree
 *     *
 *      * Return: Pointer to the created node, or NULL on failure
 *       */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	return avl_insert_recursive(tree, value);
}

