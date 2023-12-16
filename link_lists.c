#include "shell.h"

/**
 * print_linked_list - Function to print linked lists
 * @lst: linked list
 *
 * Return: size of linked list
 */
size_t print_linked_list(list_t *lst)
{
	list_t *custom_list = lst;
	int index, count;

	if (lst == NULL)
		return (0);

	for (index = 0; custom_list != NULL; index++)
	{
		if (custom_list->v == NULL)
		{
			custom_print("(nil)");
			custom_print("\n");
		}
		else
		{
			count = 0;
			while ((custom_list->v)[count] != '\0')
				count++;

			print_string(custom_list->v, count);
			custom_print("\n");
		}
		custom_list = custom_list->next_node;
	}
	return (index);
}

/**
 * add_list_end - Function to add node to end of linked list
 * @head_node: pointer to head node of the linked list
 * @str: data of the new list to be added
 *
 * Return: pointer to new linked list
 */
list_t *add_list_end(list_t **head_node, char *str)
{
	list_t *new_list, *temp;

	if (head_node == NULL || str == NULL)
		return (NULL);

	new_list = malloc(sizeof(list_t));
	if (new_list == NULL)
		return (NULL);

	new_list->v = _strdup(str);
	new_list->next_node = NULL;

	temp = *head_node;
	if (temp != NULL)
	{
		while (temp->next_node != NULL)
			temp = temp->next_node;

		temp->next_node = new_list;
	}
	else
		*head_node = new_list;

	return (*head_node);
}

/**
 * delete_list_idx - Function to delete list at a given index
 * @head_node: pointer to head node
 * @index: index of node to be deleted
 *
 * Return: return 1 on success, -1 on failure
 */
int delete_list_idx(list_t **head_node, int index)
{
	list_t *new_head_node, *temp;
	int count = 0;

	if (*head_node == NULL)
		return (-1);

	if (index == 0)
	{
		temp = (*head_node)->next_node;
		free((*head_node)->v);
		free(*head_node);
		*head_node = temp;
		return (1);
	}

	count = 1;
	new_head_node = *head_node;

	do {
		if (new_head_node == NULL)
			return (-1);
		new_head_node = new_head_node->next_node;
		count++;
	} while (count < index);

	temp = new_head_node->next_node;
	new_head_node->next_node = temp->next_node;
	free(temp->v);
	free(temp);
	return (1);
}

/**
 * free_list - frees linked list dynamically allocated memory
 * @list_head: linked list to be freed
 */
void free_list(list_t *list_head)
{
	list_t *temp;

	while (list_head != NULL)
	{
		temp = list_head;
		list_head = list_head->next_node;
		free(temp->v);
		free(temp);
	}
}

