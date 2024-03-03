#include "binary_trees.h"

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
 *  * binary_tree_leaves - Counts the leaves of the tree
 *   * @tree: Pointer to the root node
 *    * Return: Number of leaves on Success
 *     **/

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

/**
 *  * binary_tree_nodes - counts the nodes of the tree
 *   * @tree: tree to count nodes from
 *    * Return: Number of nodes on success
 *     */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}
