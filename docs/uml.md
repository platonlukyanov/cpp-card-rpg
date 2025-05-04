# UML Documentation

## Class Diagram

### Core Classes

#### **1. Game**
- Properties:
  - `players`: vector<Player>
  - `deck`: Deck
  - `currentPlayer`: Player*
  - `gameState`: GameState
- Methods:
  - `initialize()`
  - `start()`
  - `processTurn()`
  - `checkGameEnd()`
  - `declareWinner()`

#### **2. Player**
- Properties:
  - `name`: string
  - `department`: string
  - `reputation`: int
  - `money`: int
  - `ceoTrust`: int
  - `hand`: vector<Card>
  - `allies`: vector<CharacterCard>
- Methods:
  - `drawCard()`
  - `playCard(Card)`
  - `addAlly(CharacterCard)`
  - `removeAlly(CharacterCard)`
  - `updateStats(int, int, int)`

#### **3. Deck**
- Properties:
  - `cards`: vector<Card>
- Methods:
  - `shuffle()`
  - `drawCard()`
  - `addCard(Card)`
  - `removeCard(Card)`

#### **4. Card** (Abstract)
- Properties:
  - `name`: string
  - `description`: string
  - `type`: string
- Methods:
  - `execute(Player)`
  - `isPlayable(Player)`

#### **5. CharacterCard** (inherits Card)
- Properties:
  - `type`: 'character'
  - `department`: string
  - `reputation`: int
  - `money`: int
  - `trust`: int
- Methods:
  - `isPossibleToPlay(Player)`
  - `execute(Player)`

#### **6. ActionCard** (inherits Card)
- Properties:
  - `type`: 'action'
  - `reputationEffect`: int
  - `moneyEffect`: int
  - `trustEffect`: int
- Methods:
  - `isPossibleToPlay(Player)`
  - `execute(Player)`

#### **7. GameState**
- Properties:
  - `currentPhase`: Phase
  - `activePlayer`: Player*
  - `targetPlayer`: Player*
  - `currentCard`: Card*
- Methods:
  - `updatePhase(Phase)`
  - `setActivePlayer(Player*)`
  - `setTargetPlayer(Player*)`
  - `setCurrentCard(Card*)`

#### **8. TradeOffer**
- Properties:
  - `card`: Card
  - `seller`: Player*
  - `buyer`: Player*
  - `price`: int
- Methods:
  - `getActor()`
  - `isAbleToAccept()`: bool
  - `accept()`
  - `trade(int, &Player)`
  - `decline()`
  - `useLeverage(&LeverageCard, &Player)`

#### **9. CardPurchase**
- Properties:
  - `card`: Card
  - `seller`: &Player
  - `buyer`: &Player
  - `price`: int
- Methods:
  - `validate()`
  - `execute()`

#### **10. LeverageAttack**
- Properties:
  - `card`: &LeverageCard
  - `attacker`: &Player
  - `victim`: &Player
- Methods:
  - `buyout(int)`
  - `accept()`

#### **11. EndCard** (inherits Card)
- Properties:
  - `type`: 'end'
- Methods:
  - `execute(&Player)`

#### **12. LeverageCard** (inherits Card)
- Properties:
  - `type`: 'leverage'
  - `reputationDamage`: int
  - `moneyDamage`: int
  - `trustDamage`: int
- Methods:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **13. AllyReputationConditionActionCard** (inherits ActionCard)
- Properties:
  - `minAllyReputation`: int
- Methods:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **14. OwnReputationBeforeMoveConditionActionCard** (inherits ActionCard)
- Properties:
  - `minReputation`: int
- Methods:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **15. OwnReputationAfterMoveConditionActionCard** (inherits ActionCard)
- Properties:
  - `minReputation`: int
- Methods:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **16. AlreadyPlayedACardConditionActionCard** (inherits ActionCard)
- Properties:
  - `forbiddenCard`: Card
- Methods:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **17. SameDepartmentConditionActionCard** (inherits ActionCard)
- Properties:
  - `department`: string
- Methods:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **18. TrustBeforeConditionLeverageCard** (inherits LeverageCard)
- Properties:
  - `minTrust`: int
- Methods:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`
