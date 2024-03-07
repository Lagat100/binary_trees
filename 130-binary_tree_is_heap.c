#include "binary_trees.h"

/**
 *  * binary_tree_size - Measures the size of a binary tree
 *   * @tree: Pointer to the root node of the tree
 *    *
 *     * Return: Size of the tree
 *      */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 *  * binary_tree_is_heap_recursive - Helper function to check if a binary tree is a valid Max Binary Heap
 *   * @tree: Pointer to the root node of the tree
 *    * @index: Index of the current node
 *     * @size: Size of the tree
 *      *
 *       * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 *        */
int binary_tree_is_heap_recursive(const binary_tree_t *tree, size_t index, size_t size)
{
	/* If a tree is empty, it's a valid Max Binary Heap */
	if (tree == NULL)
		return (1);

	/* If the current index is greater than or equal to the size of the tree, return 1 */
	if (index >= size)
		return (1);

	/* Check if the current node's value is greater than or equal to its children's values */
	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);
	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	/* Recursively check the left and right subtrees */
	return (binary_tree_is_heap_recursive(tree->left, 2 * index + 1, size) &&
			binary_tree_is_heap_recursive(tree->right, 2 * index + 2, size));
}

/**
 *  * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 *   * @tree: Pointer to the root node of the tree
 *    *
 *     * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 *      */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	/* Get the size of the tree */
	size = binary_tree_size(tree);

	/* Check if the tree satisfies the Max Binary Heap properties */
	return binary_tree_is_heap_recursive(tree, 0, size);
}

