/* Platon Lukyanov st128133@student.spbu.ru
 * Lab Work 2
 */
#include "card_factory.h"

#include <unordered_map>
#include <unordered_set>

#include "trust_before_condition_leverage_card.h"

struct CharacterCardParams {
        int trust;
        int money;
        std::string department;
};

struct ActionCardParams {
        int trust;
        int money;
        int influence;
};

struct LeverageCardParams {
        int trust;
        int money;
        int influence;
        int condition = 0;  // For special cards
};

const std::unordered_map<std::string, CharacterCardParams> CHARACTER_PARAMS = {
    {"Team Lead", {30, 10, "development"}},
    {"Financial Consultant", {20, 20, "finance"}},
    {"Lawyer", {25, 15, "legal"}},
    {"Sales Manager", {28, 12, "sales"}},
    {"Developer", {22, 8, "development"}},
    {"Financial Analyst", {18, 22, "finance"}},
    {"PR Specialist", {20, 10, "legal"}},
    {"Marketer", {24, 16, "sales"}},
    {"Tester", {19, 11, "development"}},
    {"Accountant", {21, 19, "finance"}},
    {"Legal Counsel", {26, 14, "legal"}},
    {"Sales Agent", {23, 17, "sales"}},
    {"Web Developer", {27, 13, "development"}},
    {"Chief Financial Officer", {29, 21, "finance"}},
    {"Intellectual Property Specialist", {32, 18, "legal"}},
    {"Marketing Manager", {31, 19, "sales"}},
    {"Software Architect", {35, 15, "development"}},
    {"Financial Controller", {33, 17, "finance"}},
    {"Litigation Lawyer", {34, 16, "legal"}},
    {"Sales Director", {36, 14, "sales"}}};

const std::unordered_map<std::string, ActionCardParams> ACTION_PARAMS = {
    {"Frame a colleague and get a promotion", {-10, 10, -2}},
    {"Present a big project", {4, -1, 1}},
    {"Sell business information to competitors", {-20, 25, -5}},
    {"Fire an employee", {-5, 5, 1}},
    {"Organize a corporate event", {3, -2, 1}},
    {"Get a loan", {0, 20, -2}},
    {"Create a new department", {2, -10, 3}},
    {"Hire a new employee", {1, -5, 1}},
    {"Conduct an audit", {5, -3, 2}},
    {"Create a new product", {6, -8, 4}},
    {"Negotiate with a client", {4, 2, 2}},
    {"Run an advertising campaign", {5, -6, 1}},
    {"Create a strategic plan", {3, -4, 3}},
    {"Conduct staff training", {2, -3, 1}},
    {"Conduct market analysis", {1, -2, 2}},
    {"Create a new direction", {4, -7, 5}},
    {"Meet with investors", {6, 5, 4}},
    {"Conduct IT audit", {5, -4, 3}},
    {"Create a new team", {3, -6, 2}},
    {"Run a PR campaign", {7, -9, 5}},
    {"Conduct financial analysis", {2, -1, 1}},
    {"Create a new brand", {5, -8, 4}},
    {"Meet with partners", {4, 3, 3}},
    {"Analyze competitors", {3, -2, 2}},
    {"Create a new offer", {6, -10, 5}},
    {"Conduct leadership training", {5, -6, 3}},
    {"Analyze clients", {4, -3, 2}},
    {"Create a new strategy", {7, -11, 6}},
    {"Meet with clients", {6, 4, 4}},
    {"Analyze market trends", {5, -5, 3}}};

const std::unordered_map<std::string, LeverageCardParams> LEVERAGE_PARAMS = {
    {"Reveal the migration status of a cousin", {-10, -5, -4, 50}},
    {"Tell about a tweet from the last decade", {-5, 0, -1}},
    {"Call the tax inspectorate", {-8, -10, -2}},
    {"Reveal secret information", {-12, 0, -3}},
    {"Accuse of plagiarism", {-9, -6, -1}},
    {"Reveal personal data", {-11, -8, -2}},
    {"Call for a security check", {-7, -5, -1}},
    {"Reveal financial violations", {-10, -12, -3}},
    {"Accuse of negligence", {-8, -7, -2}},
    {"Reveal conflict of interest", {-9, -9, -2}},
    {"Call for an audit", {-6, -4, -1}},
    {"Reveal information about competitors", {-5, -3, -1}},
    {"Accuse of unethical behavior", {-12, 0, -2}},
    {"Reveal information about employees", {-11, -10, -2}},
    {"Call for compliance check", {-7, -6, -1}}};

const std::unordered_set<std::string> CHARACTER_CARDS = {
    "Team Lead",
    "Financial Consultant",
    "Lawyer",
    "Sales Manager",
    "Developer",
    "Financial Analyst",
    "PR Specialist",
    "Marketer",
    "Tester",
    "Accountant",
    "Legal Counsel",
    "Sales Agent",
    "Web Developer",
    "Chief Financial Officer",
    "Intellectual Property Specialist",
    "Marketing Manager",
    "Software Architect",
    "Financial Controller",
    "Litigation Lawyer",
    "Sales Director"};

const std::unordered_set<std::string> ACTION_CARDS = {
    "Frame a colleague and get a promotion",
    "Present a big project",
    "Sell business information to competitors",
    "Fire an employee",
    "Organize a corporate event",
    "Get a loan",
    "Create a new department",
    "Hire a new employee",
    "Conduct an audit",
    "Create a new product",
    "Negotiate with a client",
    "Run an advertising campaign",
    "Create a strategic plan",
    "Conduct staff training",
    "Conduct market analysis",
    "Create a new direction",
    "Meet with investors",
    "Conduct IT audit",
    "Create a new team",
    "Run a PR campaign",
    "Conduct financial analysis",
    "Create a new brand",
    "Meet with partners",
    "Analyze competitors",
    "Create a new offer",
    "Conduct leadership training",
    "Analyze clients",
    "Create a new strategy",
    "Meet with clients",
    "Analyze market trends"};

const std::unordered_set<std::string> LEVERAGE_CARDS = {
    "Reveal the migration status of a cousin",
    "Tell about a tweet from the last decade",
    "Call the tax inspectorate",
    "Reveal secret information",
    "Accuse of plagiarism",
    "Reveal personal data",
    "Call for a security check",
    "Reveal financial violations",
    "Accuse of negligence",
    "Reveal conflict of interest",
    "Call for an audit",
    "Reveal information about competitors",
    "Accuse of unethical behavior",
    "Reveal information about employees",
    "Call for compliance check"};

std::unique_ptr<Card> CardFactory::createCard(const std::string& cardName,
                                              int id) {
    if (CHARACTER_CARDS.contains(cardName)) {
        return createCharacterCard(cardName, id);
    }
    if (ACTION_CARDS.contains(cardName)) {
        return createActionCard(cardName, id);
    }
    if (LEVERAGE_CARDS.contains(cardName)) {
        return createLeverageCard(cardName, id);
    }
    if (cardName == "CEO Death") {
        return createEndCard(id);
    }
    return nullptr;
}

std::unique_ptr<CharacterCard> CardFactory::createCharacterCard(
    const std::string& name, int id) {
    auto it = CHARACTER_PARAMS.find(name);
    if (it != CHARACTER_PARAMS.end()) {
        const auto& params = it->second;
        return std::make_unique<CharacterCard>(id, name, params.trust,
                                               params.money, params.department);
    }
    return nullptr;
}

std::unique_ptr<ActionCard> CardFactory::createActionCard(
    const std::string& name, int id) {
    auto it = ACTION_PARAMS.find(name);
    if (it != ACTION_PARAMS.end()) {
        const auto& params = it->second;
        return std::make_unique<ActionCard>(id, name, params.trust,
                                            params.money, params.influence);
    }
    return nullptr;
}

std::unique_ptr<LeverageCard> CardFactory::createLeverageCard(
    const std::string& name, int id) {
    auto it = LEVERAGE_PARAMS.find(name);
    if (it != LEVERAGE_PARAMS.end()) {
        const auto& params = it->second;
        if (name == "Reveal the migration status of a cousin") {
            return std::make_unique<TrustBeforeConditionLeverageCard>(
                id, name, params.trust, params.money, params.influence,
                params.condition);
        }
        return std::make_unique<LeverageCard>(id, name, params.trust,
                                              params.money, params.influence);
    }
    return nullptr;
}

std::unique_ptr<EndCard> CardFactory::createEndCard(int id) {
    return std::make_unique<EndCard>(id);
}