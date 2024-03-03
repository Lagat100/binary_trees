#include "binary_trees.h"

/**
 *  * binary_tree_balance - Measures the balance factor of a binary tree.
 *   * @tree: A pointer to the root node of the tree to measure the balance factor.
 *    * Return: If tree is NULL, return 0, else return balance factor.
 *     **/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 *  * binary_tree_height - Clculates height of tree
 *   * @tree: Pointer of the tree
 *    * Return: Height of the tree
 *     **/

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
