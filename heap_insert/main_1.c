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
	heap_t *node;

	node = heap_insert(&root, 98);
	printf("Value inserted: %d\n", node->n);
	binary_tree_print(root);

	node = heap_insert(&root, 110);
	printf("Value inserted: %d\n", node->n);
	binary_tree_print(root);

	node = heap_insert(&root, 43);
	printf("Value inserted: %d\n", node->n);
	binary_tree_print(root);

	_binary_tree_delete(root);
	return (0);
}
