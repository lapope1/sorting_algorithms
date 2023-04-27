#ifndef __DECK_H__
#define __DECK_H__

/**
 * enum kind_e - Enumeration of card suits.
 * @SPADE: The spades suit represents a black, upside-down heart.
 * @HEART: The hearts suit represents a red heart.
 * @CLUB: The clubs suit represents a three-leaf clover.
 * @DIAMOND: The diamonds suit represents a red diamond.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

#include "sort.h"

/* FUNCTION PROTOTYPES */
void sort_deck(deck_node_t **deck);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);

#endif /* __DECK_H__ */
