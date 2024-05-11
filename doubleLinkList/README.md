# Doubly Linked List Implementation

This C++ program implements a doubly linked list and provides various operations like appending nodes, prepending nodes, inserting nodes, deleting nodes, updating nodes, and printing the list. 

## Classes

### `node`

- Represents a node in the doubly linked list.
- Attributes:
  - `key`: Unique identifier for the node.
  - `data`: Data stored in the node.
  - `next`: Pointer to the next node.
  - `previous`: Pointer to the previous node.
- Constructors:
  - Default constructor initializes `key`, `data`, `next`, and `previous` to default values.
  - Parameterized constructor initializes `key` and `data`.

### `doublyLinkList`

- Manages the operations on the doubly linked list.
- Attributes:
  - `head`: Pointer to the head node.
- Methods:
  1. `nodeExists(int k)`: Checks if a node exists with the given key.
  2. `appendNode(node *n)`: Appends a node to the end of the list.
  3. `prependNode(node *n)`: Prepends a node to the beginning of the list.
  4. `insertNode(int k, node *n)`: Inserts a node after a particular node in the list.
 