#include "card_factory.h"
#include "trust_before_condition_leverage_card.h"

std::unique_ptr<Card> CardFactory::createCard(const std::string& cardName, int id) {
    // Characters
    if (cardName == "Team Lead") return createCharacterCard("Team Lead", id);
    if (cardName == "Financial Consultant") return createCharacterCard("Financial Consultant", id);
    if (cardName == "Lawyer") return createCharacterCard("Lawyer", id);
    if (cardName == "Sales Manager") return createCharacterCard("Sales Manager", id);
    if (cardName == "Developer") return createCharacterCard("Developer", id);
    if (cardName == "Financial Analyst") return createCharacterCard("Financial Analyst", id);
    if (cardName == "PR Specialist") return createCharacterCard("PR Specialist", id);
    if (cardName == "Marketer") return createCharacterCard("Marketer", id);
    if (cardName == "Tester") return createCharacterCard("Tester", id);
    if (cardName == "Accountant") return createCharacterCard("Accountant", id);
    if (cardName == "Legal Counsel") return createCharacterCard("Legal Counsel", id);
    if (cardName == "Sales Agent") return createCharacterCard("Sales Agent", id);
    if (cardName == "Web Developer") return createCharacterCard("Web Developer", id);
    if (cardName == "Chief Financial Officer") return createCharacterCard("Chief Financial Officer", id);
    if (cardName == "Intellectual Property Specialist") return createCharacterCard("Intellectual Property Specialist", id);
    if (cardName == "Marketing Manager") return createCharacterCard("Marketing Manager", id);
    if (cardName == "Software Architect") return createCharacterCard("Software Architect", id);
    if (cardName == "Financial Controller") return createCharacterCard("Financial Controller", id);
    if (cardName == "Litigation Lawyer") return createCharacterCard("Litigation Lawyer", id);
    if (cardName == "Sales Director") return createCharacterCard("Sales Director", id);

    // Actions
    if (cardName == "Frame a colleague and get a promotion") return createActionCard("Frame a colleague and get a promotion", id);
    if (cardName == "Present a big project") return createActionCard("Present a big project", id);
    if (cardName == "Sell business information to competitors") return createActionCard("Sell business information to competitors", id);
    if (cardName == "Fire an employee") return createActionCard("Fire an employee", id);
    if (cardName == "Organize a corporate event") return createActionCard("Organize a corporate event", id);
    if (cardName == "Get a loan") return createActionCard("Get a loan", id);
    if (cardName == "Create a new department") return createActionCard("Create a new department", id);
    if (cardName == "Hire a new employee") return createActionCard("Hire a new employee", id);
    if (cardName == "Conduct an audit") return createActionCard("Conduct an audit", id);
    if (cardName == "Create a new product") return createActionCard("Create a new product", id);
    if (cardName == "Negotiate with a client") return createActionCard("Negotiate with a client", id);
    if (cardName == "Run an advertising campaign") return createActionCard("Run an advertising campaign", id);
    if (cardName == "Create a strategic plan") return createActionCard("Create a strategic plan", id);
    if (cardName == "Conduct staff training") return createActionCard("Conduct staff training", id);
    if (cardName == "Conduct market analysis") return createActionCard("Conduct market analysis", id);
    if (cardName == "Create a new direction") return createActionCard("Create a new direction", id);
    if (cardName == "Meet with investors") return createActionCard("Meet with investors", id);
    if (cardName == "Conduct IT audit") return createActionCard("Conduct IT audit", id);
    if (cardName == "Create a new team") return createActionCard("Create a new team", id);
    if (cardName == "Run a PR campaign") return createActionCard("Run a PR campaign", id);
    if (cardName == "Conduct financial analysis") return createActionCard("Conduct financial analysis", id);
    if (cardName == "Create a new brand") return createActionCard("Create a new brand", id);
    if (cardName == "Meet with partners") return createActionCard("Meet with partners", id);
    if (cardName == "Analyze competitors") return createActionCard("Analyze competitors", id);
    if (cardName == "Create a new offer") return createActionCard("Create a new offer", id);
    if (cardName == "Conduct leadership training") return createActionCard("Conduct leadership training", id);
    if (cardName == "Analyze clients") return createActionCard("Analyze clients", id);
    if (cardName == "Create a new strategy") return createActionCard("Create a new strategy", id);
    if (cardName == "Meet with clients") return createActionCard("Meet with clients", id);
    if (cardName == "Analyze market trends") return createActionCard("Analyze market trends", id);

    // Leverage-cards
    if (cardName == "Reveal the migration status of a cousin") return createLeverageCard("Reveal the migration status of a cousin", id);
    if (cardName == "Tell about a tweet from the last decade") return createLeverageCard("Tell about a tweet from the last decade", id);
    if (cardName == "Call the tax inspectorate") return createLeverageCard("Call the tax inspectorate", id);
    if (cardName == "Reveal secret information") return createLeverageCard("Reveal secret information", id);
    if (cardName == "Accuse of plagiarism") return createLeverageCard("Accuse of plagiarism", id);
    if (cardName == "Reveal personal data") return createLeverageCard("Reveal personal data", id);
    if (cardName == "Call for a security check") return createLeverageCard("Call for a security check", id);
    if (cardName == "Reveal financial violations") return createLeverageCard("Reveal financial violations", id);
    if (cardName == "Accuse of negligence") return createLeverageCard("Accuse of negligence", id);
    if (cardName == "Reveal conflict of interest") return createLeverageCard("Reveal conflict of interest", id);
    if (cardName == "Call for an audit") return createLeverageCard("Call for an audit", id);
    if (cardName == "Reveal information about competitors") return createLeverageCard("Reveal information about competitors", id);
    if (cardName == "Accuse of unethical behavior") return createLeverageCard("Accuse of unethical behavior", id);
    if (cardName == "Reveal information about employees") return createLeverageCard("Reveal information about employees", id);
    if (cardName == "Call for compliance check") return createLeverageCard("Call for compliance check", id);

    if (cardName == "CEO Death") return createEndCard(id);

    return nullptr;
}

std::unique_ptr<CharacterCard> CardFactory::createCharacterCard(const std::string& name, int id) {
    if (name == "Team Lead") return std::make_unique<CharacterCard>(id, name, 30, 10, "development");
    if (name == "Financial Consultant") return std::make_unique<CharacterCard>(id, name, 20, 20, "finance");
    if (name == "Lawyer") return std::make_unique<CharacterCard>(id, name, 25, 15, "legal");
    if (name == "Sales Manager") return std::make_unique<CharacterCard>(id, name, 28, 12, "sales");
    if (name == "Developer") return std::make_unique<CharacterCard>(id, name, 22, 8, "development");
    if (name == "Financial Analyst") return std::make_unique<CharacterCard>(id, name, 18, 22, "finance");
    if (name == "PR Specialist") return std::make_unique<CharacterCard>(id, name, 20, 10, "legal");
    if (name == "Marketer") return std::make_unique<CharacterCard>(id, name, 24, 16, "sales");
    if (name == "Tester") return std::make_unique<CharacterCard>(id, name, 19, 11, "development");
    if (name == "Accountant") return std::make_unique<CharacterCard>(id, name, 21, 19, "finance");
    if (name == "Legal Counsel") return std::make_unique<CharacterCard>(id, name, 26, 14, "legal");
    if (name == "Sales Agent") return std::make_unique<CharacterCard>(id, name, 23, 17, "sales");
    if (name == "Web Developer") return std::make_unique<CharacterCard>(id, name, 27, 13, "development");
    if (name == "Chief Financial Officer") return std::make_unique<CharacterCard>(id, name, 29, 21, "finance");
    if (name == "Intellectual Property Specialist") return std::make_unique<CharacterCard>(id, name, 32, 18, "legal");
    if (name == "Marketing Manager") return std::make_unique<CharacterCard>(id, name, 31, 19, "sales");
    if (name == "Software Architect") return std::make_unique<CharacterCard>(id, name, 35, 15, "development");
    if (name == "Financial Controller") return std::make_unique<CharacterCard>(id, name, 33, 17, "finance");
    if (name == "Litigation Lawyer") return std::make_unique<CharacterCard>(id, name, 34, 16, "legal");
    if (name == "Sales Director") return std::make_unique<CharacterCard>(id, name, 36, 14, "sales");

    return nullptr;
}

std::unique_ptr<ActionCard> CardFactory::createActionCard(const std::string& name, int id) {
    if (name == "Frame a colleague and get a promotion") 
        return std::make_unique<ActionCard>(id, name, -10, 10, -2);
    if (name == "Present a big project") 
        return std::make_unique<ActionCard>(id, name, 4, -1, 1);
    if (name == "Sell business information to competitors") 
        return std::make_unique<ActionCard>(id, name, -20, 25, -5);
    if (name == "Fire an employee") 
        return std::make_unique<ActionCard>(id, name, -5, 5, 1);
    if (name == "Organize a corporate event") 
        return std::make_unique<ActionCard>(id, name, 3, -2, 1);
    if (name == "Get a loan") 
        return std::make_unique<ActionCard>(id, name, 0, 20, -2);
    if (name == "Create a new department") 
        return std::make_unique<ActionCard>(id, name, 2, -10, 3);
    if (name == "Hire a new employee") 
        return std::make_unique<ActionCard>(id, name, 1, -5, 1);
    if (name == "Conduct an audit") 
        return std::make_unique<ActionCard>(id, name, 5, -3, 2);
    if (name == "Create a new product") 
        return std::make_unique<ActionCard>(id, name, 6, -8, 4);
    if (name == "Negotiate with a client") 
        return std::make_unique<ActionCard>(id, name, 4, 2, 2);
    if (name == "Run an advertising campaign") 
        return std::make_unique<ActionCard>(id, name, 5, -6, 1);
    if (name == "Create a strategic plan") 
        return std::make_unique<ActionCard>(id, name, 3, -4, 3);
    if (name == "Conduct staff training") 
        return std::make_unique<ActionCard>(id, name, 2, -3, 1);
    if (name == "Conduct market analysis") 
        return std::make_unique<ActionCard>(id, name, 1, -2, 2);
    if (name == "Create a new direction") 
        return std::make_unique<ActionCard>(id, name, 4, -7, 5);
    if (name == "Meet with investors") 
        return std::make_unique<ActionCard>(id, name, 6, 5, 4);
    if (name == "Conduct IT audit") 
        return std::make_unique<ActionCard>(id, name, 5, -4, 3);
    if (name == "Create a new team") 
        return std::make_unique<ActionCard>(id, name, 3, -6, 2);
    if (name == "Run a PR campaign") 
        return std::make_unique<ActionCard>(id, name, 7, -9, 5);
    if (name == "Conduct financial analysis") 
        return std::make_unique<ActionCard>(id, name, 2, -1, 1);
    if (name == "Create a new brand") 
        return std::make_unique<ActionCard>(id, name, 5, -8, 4);
    if (name == "Meet with partners") 
        return std::make_unique<ActionCard>(id, name, 4, 3, 3);
    if (name == "Analyze competitors") 
        return std::make_unique<ActionCard>(id, name, 3, -2, 2);
    if (name == "Create a new offer") 
        return std::make_unique<ActionCard>(id, name, 6, -10, 5);
    if (name == "Conduct leadership training") 
        return std::make_unique<ActionCard>(id, name, 5, -6, 3);
    if (name == "Analyze clients") 
        return std::make_unique<ActionCard>(id, name, 4, -3, 2);
    if (name == "Create a new strategy") 
        return std::make_unique<ActionCard>(id, name, 7, -11, 6);
    if (name == "Meet with clients") 
        return std::make_unique<ActionCard>(id, name, 6, 4, 4);
    if (name == "Analyze market trends") 
        return std::make_unique<ActionCard>(id, name, 5, -5, 3);

    return nullptr;
}

std::unique_ptr<LeverageCard> CardFactory::createLeverageCard(const std::string& name, int id) {
    if (name == "Reveal the migration status of a cousin") 
        return std::make_unique<TrustBeforeConditionLeverageCard>(id, name, -10, -5, -4, 50);
    if (name == "Tell about a tweet from the last decade") 
        return std::make_unique<LeverageCard>(id, name, -5, 0, -1);
    if (name == "Call the tax inspectorate") 
        return std::make_unique<LeverageCard>(id, name, -8, -10, -2);
    if (name == "Reveal secret information") 
        return std::make_unique<LeverageCard>(id, name, -12, 0, -3);
    if (name == "Accuse of plagiarism") 
        return std::make_unique<LeverageCard>(id, name, -9, -6, -1);
    if (name == "Reveal personal data") 
        return std::make_unique<LeverageCard>(id, name, -11, -8, -2);
    if (name == "Call for a security check") 
        return std::make_unique<LeverageCard>(id, name, -7, -5, -1);
    if (name == "Reveal financial violations") 
        return std::make_unique<LeverageCard>(id, name, -10, -12, -3);
    if (name == "Accuse of negligence") 
        return std::make_unique<LeverageCard>(id, name, -8, -7, -2);
    if (name == "Reveal conflict of interest") 
        return std::make_unique<LeverageCard>(id, name, -9, -9, -2);
    if (name == "Call for an audit") 
        return std::make_unique<LeverageCard>(id, name, -6, -4, -1);
    if (name == "Reveal information about competitors") 
        return std::make_unique<LeverageCard>(id, name, -5, -3, -1);
    if (name == "Accuse of unethical behavior") 
        return std::make_unique<LeverageCard>(id, name, -12, 0, -2);
    if (name == "Reveal information about employees") 
        return std::make_unique<LeverageCard>(id, name, -11, -10, -2);
    if (name == "Call for compliance check") 
        return std::make_unique<LeverageCard>(id, name, -7, -6, -1);

    return nullptr;
}

std::unique_ptr<EndCard> CardFactory::createEndCard(int id) {
    return std::make_unique<EndCard>(id);
} 