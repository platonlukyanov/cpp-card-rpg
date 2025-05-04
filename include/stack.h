#pragma once

#include <vector>
#include <memory>
#include "card.h"
#include "character_card.h"

/**
 * @brief Manages the game's card deck and discard pile
 * 
 * The Stack class handles all card operations in the game:
 * - Drawing cards from the deck
 * - Adding cards to the discard pile
 * - Shuffling the deck
 * - Managing card positions
 * - Special operations for character cards
 */
class Stack {
public:
    /**
     * @brief Creates a new empty stack
     */
    Stack();

    /**
     * @brief Destroys the stack and all cards in it
     */
    ~Stack();

    /**
     * @brief Checks if the stack is empty
     * @return true if no cards remain
     */
    bool isEmpty() const;

    /**
     * @brief Draws a card from the top of the stack
     * Removes and returns the top card
     * 
     * @return std::unique_ptr<Card> Drawn card, or nullptr if empty
     */
    std::unique_ptr<Card> drawCard();

    /**
     * @brief Removes and returns the top card without ownership transfer
     * Used internally for card operations
     * 
     * @return Card* Raw pointer to the top card, or nullptr if empty
     */
    Card* popCard();

    /**
     * @brief Adds a card to the top of the stack
     * Takes ownership of the card
     * 
     * @param card Card to add
     */
    void pushCard(std::unique_ptr<Card> card);

    /**
     * @brief Inserts a card at a specific position
     * Used for special card placement
     * 
     * @param card Card to insert
     * @param index Position to insert at
     */
    void insertCard(std::unique_ptr<Card> card, int index);

    /**
     * @brief Randomizes the order of cards in the stack
     * Used at game start and when deck is reshuffled
     */
    void shuffle();

    /**
     * @brief Draws a specific number of character cards
     * Used for player setup and special game events
     * Non-character cards are returned to the stack
     * 
     * @param count Number of character cards to draw
     * @return std::vector<std::unique_ptr<CharacterCard>> Drawn character cards
     */
    std::vector<std::unique_ptr<CharacterCard>> fetchPlayersCards(int count);

    /**
     * @brief Views the top card without removing it
     * Used for card preview and AI decision making
     * 
     * @return Card* Pointer to top card, or nullptr if empty
     */
    Card* peekCard() const;

private:
    std::vector<Card*> cards_; ///< Collection of cards in the stack
}; 