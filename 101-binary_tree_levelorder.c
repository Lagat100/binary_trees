#include "binary_trees.h"
#include "queue.h"

/**
 *  * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 *   * @tree: Pointer to the root node of the tree to traverse
 *    * @func: Pointer to a function to call for each node
 *     *
 *      * Description: If tree or func is NULL, do nothing
 *       */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;

	if (tree == NULL || func == NULL)
		return;

	queue = queue_create();
	if (queue == NULL)
		return;

	queue_push(queue, (void *)tree);

	while (!queue_is_empty(queue))
	{
		const binary_tree_t *node = (const binary_tree_t *)queue_front(queue);

		func(node->n);

		if (node->left)
			queue_push(queue, (void *)node->left);
		if (node->right)
			queue_push(queue, (void *)node->right);

		queue_pop(queue);
	}

	queue_delete(queue);
}

