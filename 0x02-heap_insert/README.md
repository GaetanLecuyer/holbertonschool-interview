# 0x02-heap_insert
For this interview practice algorithm, there are two tasks dealing with heaps.

[0. New Node](/0x02-heap_insert/0-binary_tree_node.c)
* Write a function `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)` that creates a binary tree node:
  * `parent` is a pointer to the parent node for the node to create
  * `value` is the data to put into the new node
  * the new node will not have any children (new node is leaf node)
  * returns pointer to new node, or NULL if failed

[1. Heap - Insert](/0x02-heap_insert/1-heap_insert.c)
* Write a function `heap_insert(heap_t **root, int value)` that inserts a value into a Max Binary Heap:
  * `root` is a double pointer to the root node of the Heap
  * if `root` is `NULL`, the created node becomes the root node
  * `value` is the data to put into the node to insert
  * Max Heap ordering must be preserved
  * returns a pointer to the new node, or NULL if failed

### test_files
The test_files/ directory contains files used to test the output of the algorithm locally and all given source code for reference, including struct definitions.
