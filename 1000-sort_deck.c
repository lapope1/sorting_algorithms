#include "deck.h"

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
	char *values[] = {"Ace", "1", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(card->card->value, values[i]) == 0)
			return (i);
	}
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	/* Declare variables to hold current, insert, and temporary nodes */
	deck_node_t *current, *insert, *temp;

	/* Iterate over the doubly-linked list, starting from the second node */
	for (current = (*deck)->next; current != NULL; current = temp)
	{
		/* Store the next node in a temporary variable */
		temp = current->next;

		/* Initialize insert as the previous node to current */
		insert = current->prev;

		/* Iterate backwards over the sorted portion of the list */
		while (insert != NULL && insert->card->kind > current->card->kind)
		{
			/* Swap the positions of current and insert */
			insert->next = current->next;
			if (current->next != NULL)
				current->next->prev = insert;
			current->prev = insert->prev;
			current->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*deck = current;
			insert->prev = current;
			insert = current->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	/* Declare variables to use for currentation and sorting */
	deck_node_t *current, *insert, *tmp;

	/* Iterate through the deck, starting from the second card */
	for (current = (*deck)->next; current != NULL; current = tmp)
	{
		/* Store the next card in the deck to be sorted */
		tmp = current->next;

		/* Set the insert node to the card before the current card */
		insert = current->prev;

		/**
		 * Sort cards of the same kind by value, startingi
		 * from the second card of that kind.
		 */
		while (insert != NULL &&
				insert->card->kind == current->card->kind &&
				get_value(insert) > get_value(current))
		{
			/* Swap the position of the cards in the linked list */
			insert->next = current->next;
			if (current->next != NULL)
				current->next->prev = insert;
			current->prev = insert->prev;
			current->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*deck = current;
			insert->prev = current;

			/* Update the insert node to continue sorting the deck */
			insert = current->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
