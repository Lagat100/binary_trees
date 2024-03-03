#include "binary_trees.h"


/**
 *  * binary_tree_height - Clculates height of tree
 *   * @tree: Pointer of the tree
 *    *
 *     * Return: Height of the tree
 *      */
size_t binary_tree_height(const binary_tree_t *tree)
{

	size_t left, right;

	if (tree)
	{
		left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right = tree->right ? 1 + binary_tree_height(tree->right) : 1;

		return (left > right ? left : right);
	}


	return (0);
}


/**
 *  * binary_tree_size -  function measures the size of a binary tree
 *   * @tree: The tree to measure the size of
 *    * Return: size of the tree or 0 if tree is NULL
 *     **/

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}


/**
 *  * binary_tree_is_perfect - Checks if a binary tree is perfect
 *   * @tree: Pointer to the root node of the tree to check
 *    * Return: 1 if the tree is perfect, 0 otherwise
 *     **/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, nodes, perfect_nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);
	perfect_nodes = (1 << height) - 1;

	return (nodes == perfect_nodes);
}
