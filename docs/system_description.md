# System Description

## General System Overview

The system is a console-based C++ application implementing a card game where players compete for the CEO's trust. Players take turns drawing cards from a deck, which can be of three types: "Characters", "Actions", and "Leverage cards". The goal of the game is to accumulate the highest amount of "CEO Trust" by the time the "CEO Death" card is drawn. The game ends when the "CEO Death" card is drawn, and the winner is declared as the player with the highest trust score. In case of a tie in trust, "Reputation" and "Money" scores are considered respectively.

## System Requirements

### Functional Requirements:

The system must successfully implement the "Game Rules" described in the "rules.md" file. The implementation must not contradict them. All card descriptions are located there.

### Game Initialization:

* Request number of players (minimum 2)
* Create card deck (characters, actions, leverage). The "CEO Death" card must be in the last 25% of the deck
* Deal starting cards to players (character card with initial stats)
* Determine player turn order using random number

### Main Game Loop:

* Display current game state (player information, their stats)
* Provide turn to current player
* Player draws a card from the deck
* Check for game end (drawing of "CEO Death" card)
* Pass turn to next player

### Card Processing:

* Character: Offer player to take character card as ally (if from their department) or sell to another player
* Action: Offer player to play the card or sell to another player
* Leverage card: Add card to player's "hand" 
* Implement trading between players (selling character and action cards)
* Apply card effects to player stats (reputation, money, CEO trust)
* Check conditions for applying card effects (e.g., having an ally with certain reputation)

### Leverage Card Usage:

* Allow player to use Leverage card against another player (reducing reputation or trust)
* Allow player targeted by Leverage card to offer buyout
* Implement buyout logic (player decides to accept buyout or apply card)

### Winner Determination:

* After drawing "CEO Death" card, determine player with highest CEO trust
* In case of trust tie, compare reputation
* In case of reputation tie, compare money amount
* Declare winner (or draw)

### Invalid Input Handling:

* Prevent invalid input (e.g., negative number of players)
* Handle action selection errors (e.g., attempting to play card without sufficient resources)

### Simple AI Implementation

#### Basic AI Decision Rules:

##### Taking Character Card:

* AI always takes character card as ally if from its department
* Otherwise - tries to sell it to other players at fixed price

##### Playing Action Card:

* AI plays action card if it increases CEO trust
* Otherwise - tries to sell it to other players

##### Using Leverage Card:

* AI uses Leverage card against player with highest CEO trust
* Does not offer buyout

##### Buyout:

* If Leverage card is used against AI, AI always refuses buyout
* AI sets fixed price for selling cards
* When buying cards, AI always agrees to price if has enough money

### Non-functional Requirements:

* Performance: Game should run quickly and smoothly
* Usability: Console interface should be intuitive and easy to use
* Reliability: System should be resistant to errors and crashes
* Support: Code should be well-documented and tested for easy maintenance and expansion

## Use Cases

### Starting New Game:

* System requests game mode (2+ players or AI game). If user chooses AI, see Section 7
* System requests number of players
* System creates card deck
* System deals starting cards to players
* System determines player turn order

### Player Turn:

* System displays current game state
* System offers player to draw a card
* Player chooses "draw card" action
* System draws card from deck
* System displays information about drawn card

### Processing Character Card:

* System offers player to take card as ally (if from their department) or sell to another player
* Player chooses action: "take as ally", "sell" or "do nothing"
* If player chooses "take as ally", system adds character card to their allies and applies effects (+5% from ally's reputation)
* If player chooses "sell", system requests name of player to sell to and price
* After price agreement, player stats are modified accordingly

### Processing Action Card:

* System offers player to play card or sell to another player
* Player chooses action: "play" or "sell"
* If player chooses "play", system applies card effects to player stats and/or other players
* If player chooses "sell", similar process as with character card occurs

### Using Leverage Card:

* Player chooses "use Leverage card" action
* System displays list of available Leverage cards
* Player chooses card and player to use it against
* System offers targeted player buyout option
* Player accepts or declines buyout
* Depending on player's decision, card effects are applied or buyout occurs

### Game End and Winner Determination:

* "CEO Death" card is drawn
* System determines player with highest CEO trust
* In case of trust tie, system compares reputation
* In case of reputation tie, system compares money amount
* System declares winner or draw

## Playing with AI

When entering the game, player chooses to play with AI

AI becomes a player in the game and the scenario works the same as in previous sections

## Resolving Potential Ambiguities

* Stats: Reputation, money, and CEO trust values must always be integers in range from 0 to 100. If card effect leads to value below 0, stat remains at 0
* Allies: Player can have multiple allies simultaneously. Ally effects are summed
* Trading: Card price is determined by agreement between players. System does not set fixed prices
* Leverage cards: Player can have multiple Leverage cards in hand. Can use them at any point during their turn (after drawing card)
* Card effect conditions: If card effect requires certain conditions (e.g., having ally with certain reputation), system must check these conditions before applying effect

This document provides general system description, system requirements, and use cases.
