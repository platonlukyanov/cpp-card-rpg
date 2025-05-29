/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#ifndef INCLUDE_ALLY_H
#define INCLUDE_ALLY_H

#include <string>

class CharacterCard;

/**
 * @brief Represents an ally in the game
 *
 * The Ally class encapsulates the data of an ally in the game:
 * - Name
 * - Reputation
 * - Money
 * - Department
 *
 */
class Ally {
    public:
        /**
         * @brief Creates a new ally with basic properties
         */
        Ally(const CharacterCard& card);
        ~Ally() = default;

        /**
         * @brief Get the ally's name
         * @return const std::string& Ally name
         */
        const std::string& getName() const;
        /**
         * @brief Get the ally's reputation
         * @return int Ally reputation
         */
        int getReputation() const;
        /**
         * @brief Get the Money object
         * @return int Ally money
         **/
        int getMoney() const;
        /**
         * @brief Get the Department object
         * @return const std::string& Ally department
         */
        const std::string& getDepartment() const;

    private:
        std::string name_;
        int reputation_;
        int money_;
        std::string department_;
};

#endif // INCLUDE_ALLY_H