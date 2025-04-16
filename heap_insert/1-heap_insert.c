#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - calculates size of a binary tree
 * @tree: pointer to root
 * Return: size (number of nodes)
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_node_by_index - gets a node by index using BFS logic
 * @root: root node
 * @index: target index
 * Return: pointer to the node at that index
 */
binary_tree_t *get_node_by_index(binary_tree_t *root, size_t index)
{
	binary_tree_t *queue[1024];
	size_t front = 0, rear = 0, i = 0;

	if (!root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		binary_tree_t *node = queue[front++];

		if (i++ == index)
			return (node);

		if (node->left)
			queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;
	}
	return (NULL);
}

/**
 * heapify_up - bubbles up node to maintain max heap
 * @node: node to bubble up
 */
void heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to root node
 * @value: value to insert
 * Return: pointer to the inserted node (not where it ends up)
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	size_t size, parent_index;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = binary_tree_size(*root);
	parent_index = (size - 1) / 2;
	parent = get_node_by_index(*root, parent_index);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	heapify_up(new_node);  /* Maintain max-heap property */

	return (new_node);     /* Always return the inserted node */
}
