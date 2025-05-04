/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#pragma once

#include <string>

class Player;

/**
 * @brief Base class for all cards in the game
 * 
 * The Card class defines the interface for all card types in the game.
 * Each card type has specific effects and conditions for play:
 * - Action cards: Immediate effects on player stats
 * - Character cards: Can become allies with ongoing effects
 * - Leverage cards: Special cards that can be used against other players
 * - End card: Triggers game end when drawn
 */
class Card {
public:
    /**
     * @brief Enumeration of possible card types
     * Each type has specific rules for when and how it can be played
     */
    enum class Type {
        ACTION,     ///< Cards with immediate effects on player stats
        CHARACTER,  ///< Cards that can become allies with ongoing effects
        LEVERAGE,   ///< Special cards that can be used against other players
        END         ///< Card that triggers game end when drawn
    };

    /**
     * @brief Creates a new card with basic properties
     * 
     * @param id Unique identifier for the card
     * @param type Type of the card (determines play rules)
     * @param name Display name of the card
     */
    Card(int id, Type type, const std::string& name);
    
    /**
     * @brief Virtual destructor
     */
    virtual ~Card() = default;

    /**
     * @brief Get the card's unique identifier
     * 
     * @return int Card ID
     */
    int getId() const;

    /**
     * @brief Get the card's type
     * 
     * @return Type Card type
     */
    Type getType() const;

    /**
     * @brief Get the card's name
     * 
     * @return const std::string& Card name
     */
    const std::string& getName() const;

    /**
     * @brief Checks if the card can be played by the given player
     * Each card type has specific conditions that must be met
     * 
     * @param player The player attempting to play the card
     * @return true if all conditions are met
     */
    virtual bool isPossibleToPlay(const Player& player) const = 0;

    /**
     * @brief Executes the card's effect on the given player
     * Effects can modify player stats or trigger special actions
     * 
     * @param player The player playing the card
     */
    virtual void execute(Player& player) = 0;

protected:
    int id_;        ///< Unique identifier for card tracking
    Type type_;     ///< Card type (determines play rules)
    std::string name_; ///< Display name shown to players
}; 