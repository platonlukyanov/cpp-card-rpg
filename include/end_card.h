#pragma once

#include "card.h"

/**
 * @brief Special card that triggers the end of the game
 * 
 * The EndCard (CEO Death) is a unique card that:
 * - Cannot be played normally
 * - Triggers game end when drawn
 * - Determines the winner based on final stats
 * - Has no direct effects on player stats
 */
class EndCard : public Card {
public:
    /**
     * @brief Creates a new end card
     * 
     * @param id Unique card identifier
     */
    EndCard(int id);
    ~EndCard() override = default;

    /**
     * @brief Checks if the card can be played
     * End card cannot be played by players
     * 
     * @param player Player attempting to play the card
     * @return false Always returns false
     */
    bool isPossibleToPlay(const Player& player) const override;

    /**
     * @brief Handles the end of game
     * Called when the card is drawn
     * 
     * @param player Player who drew the card
     */
    void execute(Player& player) override;
}; 