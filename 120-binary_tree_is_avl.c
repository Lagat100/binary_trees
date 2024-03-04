nclude "binary_trees.h"

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
 *  * binary_tree_is_avl_helper - Helper function to check if a binary tree is a valid AVL Tree
 *   * @tree: Pointer to the root node of the tree
 *    *
 *     * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 *      */
int binary_tree_is_avl_helper(const binary_tree_t *tree)
{
	int height_diff, left_height, right_height;

	if (tree == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	height_diff = left_height - right_height;

	if (height_diff < -1 || height_diff > 1)
		return (0);

	return (binary_tree_is_avl_helper(tree->left) && binary_tree_is_avl_helper(tree->right));
}

/**
 *  * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 *   * @tree: Pointer to the root node of the tree
 *    *
 *     * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 *      */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	return binary_tree_is_avl_helper(tree);
}

