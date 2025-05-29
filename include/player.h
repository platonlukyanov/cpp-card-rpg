/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef INCLUDE_PLAYER_H
#define INCLUDE_PLAYER_H

#include <memory>
#include <string>
#include <vector>

#include "ally.h"
#include "card.h"
#include "player_hand.h"

/**
 * @brief Represents a player in the game
 *
 * The Player class manages all player-related data and actions, including:
 * - Basic stats (reputation, money, trust)
 * - Player identification and department
 * - Hand of cards
 * - Allies
 */
class Player {
    public:
        /**
         * @brief Creates a new player with authentication credentials
         *
         * @param id Unique identifier for the player
         * @param secret Secret key for player authentication
         */
        Player(const std::string& id, const std::string& secret);

        /**
         * @brief Virtual destructor
         */
        virtual ~Player() = default;

        /**
         * @brief Get the player's unique identifier
         *
         * @return const std::string& Player ID
         */
        const std::string& getId() const;

        /**
         * @brief Get the player's secret key
         *
         * @return const std::string& Secret key
         */
        const std::string& getSecret() const;

        /**
         * @brief Get the player's reputation score
         *
         * @return int Reputation value (0-100)
         */
        int getReputation() const;

        /**
         * @brief Get the player's money amount
         *
         * @return int Money amount (0-100)
         */
        int getMoney() const;

        /**
         * @brief Get the player's CEO trust score
         *
         * @return int Trust value (0-100)
         */
        int getTrust() const;

        /**
         * @brief Get the player's display name
         *
         * @return const std::string& Player name
         */
        const std::string& getPlayerName() const;

        /**
         * @brief Get the player's department
         *
         * @return const std::string& Department name
         */
        const std::string& getDepartment() const;

        /**
         * @brief Decreases player's money, ensuring it doesn't go below 0
         *
         * @param amount Amount to decrease
         */
        void loseMoney(int amount);

        /**
         * @brief Decreases player's reputation, ensuring it doesn't go below 0
         *
         * @param amount Amount to decrease
         */
        void loseReputation(int amount);

        /**
         * @brief Decreases player's CEO trust, ensuring it doesn't go below 0
         *
         * @param amount Amount to decrease
         */
        void loseTrust(int amount);

        /**
         * @brief Increases player's money, capped at 100
         *
         * @param amount Amount to increase
         */
        void gainMoney(int amount);

        /**
         * @brief Increases player's reputation, capped at 100
         *
         * @param amount Amount to increase
         */
        void gainReputation(int amount);

        /**
         * @brief Increases player's CEO trust, capped at 100
         *
         * @param amount Amount to increase
         */
        void gainTrust(int amount);

        /**
         * @brief Set the player's display name
         *
         * @param name New player name
         */
        void setName(const std::string& name);

        /**
         * @brief Set the player's department
         *
         * @param department New department name
         */
        void setDepartment(const std::string& department);

        /**
         * @brief Get the player's hand of cards
         *
         * @return std::shared_ptr<PlayerHand> Pointer to player's hand
         */
        std::shared_ptr<PlayerHand> getHand();

        /**
         * @brief Get the player's allies
         *
         * @return const std::vector<Ally>& Vector of player's allies
         */
        const std::vector<Ally>& getAllies() const;

        /**
         * @brief Adds a character card as an ally, applying its effects to the
         * player
         *
         * @param card Character card to add as ally
         */
        void addAlly(const CharacterCard& card);

        /**
         * @brief Checks if player has an ally from specific department
         * Used for card effect conditions
         *
         * @param department Department to check
         * @return true if player has ally from department
         */
        bool hasAllyFromDepartment(const std::string& department) const;

        /**
         * @brief Checks if player has an ally with reputation above threshold
         * Used for card effect conditions
         *
         * @param reputation Minimum reputation threshold
         * @return true if player has ally with sufficient reputation
         */
        bool hasAllyWithReputationAbove(int reputation) const;

    protected:
        std::string id_;                    ///< Unique identifier
        std::string secret_;                ///< Secret key for authentication
        std::string playerName_;            ///< Display name
        std::string department_;            ///< Department name
        int reputation_;                    ///< Reputation score (0-100)
        int money_;                         ///< Money amount (0-100)
        int trust_;                         ///< CEO trust score (0-100)
        std::shared_ptr<PlayerHand> hand_;  ///< Player's hand of cards
        std::vector<Ally> allies_;          ///< Player's allies
};

#endif  // INCLUDE_PLAYER_H