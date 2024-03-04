#include "binary_trees.h"

/**
 *  * array_to_bst_helper - Recursively builds a Binary Search Tree (BST) from an array
 *   * @array: Pointer to the first element of the array
 *    * @start: Index of the first element of the current sub-array
 *     * @end: Index of the last element of the current sub-array
 *      *
 *       * Return: Pointer to the root node of the created BST, or NULL on failure
 *        */
bst_t *array_to_bst_helper(int *array, int start, int end)
{
	if (start > end)
		return (NULL);

	int mid = (start + end) / 2;

	bst_t *root = binary_tree_node(NULL, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = array_to_bst_helper(array, start, mid - 1);
	root->right = array_to_bst_helper(array, mid + 1, end);

	return (root);
}

/**
 *  * array_to_bst - Builds a Binary Search Tree (BST) from an array
 *   * @array: Pointer to the first element of the array to be converted
 *    * @size: Number of elements in the array
 *     *
 *      * Return: Pointer to the root node of the created BST, or NULL on failure
 *       */
bst_t *array_to_bst(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (array_to_bst_helper(array, 0, size - 1));
}

