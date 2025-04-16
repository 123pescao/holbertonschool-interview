#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 * @tree: Pointer to the root of the tree to delete
 */
void _binary_tree_delete(binary_tree_t *tree);

int main(void)
{
	heap_t *root = NULL;
	int value;

	value = 98;
	heap_insert(&root, value);
	printf("Value inserted: %d\n", value);
	binary_tree_print(root);

	value = 110;
	heap_insert(&root, value);
	printf("Value inserted: %d\n", value);
	binary_tree_print(root);

	value = 43;
	heap_insert(&root, value);
	printf("Value inserted: %d\n", value);
	binary_tree_print(root);

	_binary_tree_delete(root);
	return (0);
}
