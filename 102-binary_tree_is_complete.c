#include "binary_trees.h"
#include "queue.h"

/**
 *  * binary_tree_is_complete - Checks if a binary tree is complete
 *   * @tree: Pointer to the root node of the tree to check
 *    *
 *     * Return: 1 if the binary tree is complete, 0 otherwise
 *      */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	queue_t *queue = queue_create();

	if (queue == NULL)
		return (0);

	queue_push(queue, (void *)tree);

	int flag = 0;

	while (!queue_is_empty(queue))
	{
		const binary_tree_t *node = (const binary_tree_t *)queue_front(queue);
		queue_pop(queue);

		if (node == NULL)
			flag = 1;
		else
		{
			if (flag)
			{
				queue_delete(queue);
				return (0);
			}

			queue_push(queue, (void *)node->left);
			queue_push(queue, (void *)node->right);
		}
	}

	queue_delete(queue);
	return (1);
}

