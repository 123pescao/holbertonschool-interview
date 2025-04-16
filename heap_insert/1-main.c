#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		_binary_tree_delete(tree->left);
		_binary_tree_delete(tree->right);
		free(tree);
	}
}

int main(void)
{
	heap_t *root = NULL;
	int values[] = {98, 402, 12, 46, 128, 256, 512, 50};
	size_t i;

	for (i = 0; i < sizeof(values) / sizeof(values[0]); i++)
	{
		heap_insert(&root, values[i]);
		printf("Inserted: %d\n", values[i]);
		binary_tree_print(root);
	}

	_binary_tree_delete(root);
	return (0);
}
