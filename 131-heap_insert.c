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
 *  * heapify_up - Reorders the heap by moving the new node up to its correct position
 *   * @new_node: Pointer to the new node
 *    *
 *     * Return: Pointer to the root node of the heap after heapify-up operation
 *      */
heap_t *heapify_up(heap_t *new_node)
{
	int temp;

	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		/* Swap the values of the new node and its parent */
		temp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;

		/* Move up to the parent */
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 *  * heap_insert - Inserts a value in a Max Binary Heap
 *   * @root: Double pointer to the root node of the heap
 *    * @value: Value to insert
 *     *
 *      * Return: Pointer to the created node, or NULL on failure
 *       */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	/* Create a new node */
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		/* If the heap is empty, the new node becomes the root */
		*root = new_node;
		return (new_node);
	}

	/* Find the parent for the new node */
	parent = *root;
	while (parent->left != NULL && parent->right != NULL)
	{
		if (binary_tree_height(parent->left) <= binary_tree_height(parent->right))
			parent = parent->left;
		else
			parent = parent->right;
	}

	/* Insert the new node as the left child if the parent has no left child,
	 *      * otherwise insert it as the right child */
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* Set the parent of the new node */
	new_node->parent = parent;

	/* Reorder the heap by moving the new node up */
	return (heapify_up(new_node));
}

