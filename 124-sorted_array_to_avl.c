#include "binary_trees.h"

/**
 *  * sorted_array_to_avl_recursive - Recursively builds an AVL tree from a sorted array
 *   * @array: Pointer to the first element of the array
 *    * @start: Index of the first element of the current sub-array
 *     * @end: Index of the last element of the current sub-array
 *      *
 *       * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 *        */
avl_t *sorted_array_to_avl_recursive(int *array, int start, int end)
{
	if (start > end)
		return (NULL);

	int mid = (start + end) / 2;

	avl_t *root = binary_tree_node(NULL, array[mid]);
	if (root == NULL)
		return (NULL);

	root->left = sorted_array_to_avl_recursive(array, start, mid - 1);
	root->right = sorted_array_to_avl_recursive(array, mid + 1, end);

	return (root);
}

/**
 *  * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *   * @array: Pointer to the first element of the array to be converted
 *    * @size: Number of elements in the array
 *     *
 *      * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 *       */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return sorted_array_to_avl_recursive(array, 0, size - 1);
}

