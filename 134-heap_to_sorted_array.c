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
 *  * get_last_node - Gets the last level-order node of a binary tree
 *   * @root: Pointer to the root node of the tree
 *    * @height: Height of the tree
 *     *
 *      * Return: Pointer to the last level-order node
 *       */
heap_t *get_last_node(heap_t *root, size_t height)
{
	size_t i;
	heap_t *last_node = root;

	for (i = 0; i < height - 1; i++)
	{
		if (last_node->left)
			last_node = last_node->left;
		else
			last_node = last_node->right;
	}

	return (last_node);
}

/**
 *  * heapify_down - Reorders the heap by moving the given node down to its correct position
 *   * @root: Pointer to the root node of the heap
 *    *
 *     * Return: Pointer to the root node of the heap after heapify-down operation
 *      */
heap_t *heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;
	int temp;

	/* Find the largest among root, left, and right */
	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	/* If largest is not root, swap root with largest */
	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		return heapify_down(largest);
	}

	return root;
}

/**
 *  * heap_extract_root - Extracts the root node of a Max Binary Heap
 *   * @root: Double pointer to the root node of the heap
 *    *
 *     * Return: Value stored in the root node, or 0 on failure
 *      */
int heap_extract_root(heap_t **root)
{
	int value;
	size_t height;
	heap_t *last_node, *parent;

	if (root == NULL || *root == NULL)
		return (0);

	/* Store the value of the root node */
	value = (*root)->n;

	/* Get the height of the heap */
	height = binary_tree_height(*root);

	/* Get the last node of the heap */
	last_node = get_last_node(*root, height);

	/* Replace the root node with the last node */
	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
	}
	else
	{
		parent = last_node->parent;
		if (parent->left == last_node)
			parent->left = NULL;
		else
			parent->right = NULL;

		(*root)->n = last_node->n;
		free(last_node);

		/* Reorder the heap */
		*root = heapify_down(*root);
	}

	return (value);
}

/**
 *  * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 *   * @heap: Pointer to the root node of the heap to convert
 *    * @size: Address to store the size of the array
 *     *
 *      * Return: Pointer to the sorted array of integers
 *       */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	int value;
	size_t i, heap_size;

	if (heap == NULL || size == NULL)
		return (NULL);

	heap_size = binary_tree_height(heap);
	sorted_array = malloc(heap_size * sizeof(int));
	if (sorted_array == NULL)
		return (NULL);

	for (i = 0; i < heap_size; i++)
	{
		value = heap_extract_root(&heap);
		if (value == 0)
		{
			free(sorted_array);
			return (NULL);
		}
		sorted_array[i] = value;
	}

	*size = heap_size;
	return (sorted_array);
}

