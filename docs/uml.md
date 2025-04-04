# README для файла `uml.pdf`

## Описание структуры данных и классов

Файл описывает объектно-ориентированную структуру данных, включая классы, их свойства и методы. Основные элементы:

### Классы

#### **1. Player**
- Свойства:
  - `id`: string
  - `secret`: string
  - `reputation`: int
  - `money`: int
  - `trust`: int
  - `hand`: PlayerHand
- Методы:
  - `getId()`: string
  - `loseMoney(int)`
  - `loseReputation(int)`
  - `loseTrust(int)`
  - `gainTrust(int)`
  - `gainReputation(int)`
  - `gainMoney(int)`
  - `setName(string)`
  - `getPlayerName()`: string

#### **2. PlayerHand**
- Свойства:
  - `cards`: Card[]
- Методы:
  - `getCards()`: Card[]
  - `addCard(Card)`
  - `playCard(int): Card`
  - `getLeverageCards()`: LeverageCard[]

#### **3. Card**
- Свойства:
  - `id`: int
- Методы:
  - `type`: 'action' | 'character' | 'leverage' | 'end'
  - `name`: string
  - `getId()`: int
  - Виртуальные методы:
    - `isPossibleToPlay(&Player)`
    - `execute(&Player)`

#### **4. AI**
- Методы:
  - `getName()`: string // всегда возвращает 'AI'
  - `makeMove(move: Move)`

#### **5. Game**
- Свойства:
  - `players`: Player[]
  - `stack`: Stack
  - `playersQueue`: string[]
- Методы:
  - `initialize(UserPlayerInput[])`
  - `getPlayers()`: &Player[]
  - `offerMove()`: Move
  - `next()`
  - `isEnd()`
  - `determineWinner()`: &Player

#### **6. Stack**
- Свойства:
  - `cards`: Card[]
- Методы:
  - `popCard()`: Card
  - `shuffle()`
  - `fetchPlayersCards(int)`

---

### Дополнительные классы системы

#### **7. UserPlayerInput**
- Свойства:
  - `playerName`: string
  - `playerType`: 'ai' | 'user'

#### **8. Move**
- Свойства:
  - `actor`: &Player
  - `card`: Card
  - `hasPlayed`: bool
- Методы:
  - `getActor()`
  - `isAbleToAccept()`: bool
  - `accept()`
  - `trade(int, &Player)`
  - `decline()`
  - `useLeverage(&LeverageCard, &Player)`

#### **9. CardPurchase**
- Свойства:
  - `card`: Card
  - `seller`: &Player
  - `buyer`: &Player
  - `price`: int
- Методы:
  - `validate()`
  - `execute()`

#### **10. LeverageAttack**
- Свойства:
  - `card`: &LeverageCard
  - `attacker`: &Player
  - `victim`: &Player
- Методы:
  - `buyout(int)`
  - `accept()`

#### **11. EndCard** (наследует Card)
- Свойства:
  - `type`: 'end'
- Методы:
  - `execute(&Player)`

#### **12. LeverageCard** (наследует Card)
- Свойства:
  - `type`: 'leverage'
  - `reputationDamage`: int
  - `moneyDamage`: int
  - `trustDamage`: int
- Методы:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **13. AllyReputationConditionActionCard** (наследует ActionCard)
- Свойства:
  - `minAllyReputation`: int
- Методы:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **14. OwnReputationBeforeMoveConditionActionCard** (наследует ActionCard)
- Свойства:
  - `minReputation`: int
- Методы:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **15. OwnReputationAfterMoveConditionActionCard** (наследует ActionCard)
- Свойства:
  - `minReputation`: int
- Методы:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **16. AlreadyPlayedACardConditionActionCard** (наследует ActionCard)
- Свойства:
  - `forbiddenCard`: Card
- Методы:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **17. SameDepartmentConditionActionCard** (наследует ActionCard)
- Свойства:
  - `department`: string
- Методы:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **18. TrustBeforeConditionLeverageCard** (наследует LeverageCard)
- Свойства:
  - `minTrust`: int
- Методы:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **19. CharacterCard** (наследует Card)
 - Свойства:
  - `reputation`: int
  - `money`: int
  - `department`: string
  - `type`: 'character'
 - Методы:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`

#### **20. ActionCard** (наследует Card)
- Свойства:
  - `type`: 'action'
  - `reputationDamage`: int
  - `moneyDamage`: int
  - `trustDamage`: int
  - `trustGain`: int
  - `reputationGain`: int
  - `moneyGain`: int
- Методы:
  - `isPossibleToPlay(&Player)`
  - `execute(&Player)`
