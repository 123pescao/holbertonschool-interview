#include <stdlib.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Recursively frees an entire binary tree
 * @tree: Pointer to the root node
 */
void _binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		_binary_tree_delete(tree->left);
		_binary_tree_delete(tree->right);
		free(tree);
	}
}
