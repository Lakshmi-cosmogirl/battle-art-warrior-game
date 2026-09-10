#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Node structure for Customization Linked List
struct CustomNode {
    string category;
    string selectedOption;
    CustomNode* next;
    
    CustomNode(string cat, string opt) {
        category = cat;
        selectedOption = opt;
        next = nullptr;
    }
};

// Node structure for High Score Database (Linked List Data Structure)
struct ScoreNode {
    string warriorName;
    string enemyName;
    int score;
    ScoreNode* next;

    ScoreNode(string w, string e, int s) {
        warriorName = w;
        enemyName = e;
        score = s;
        next = nullptr;
    }
};

// Database Manager for High Scores using Linked List
class HighScoreDatabase {
private:
    ScoreNode* head;

public:
    HighScoreDatabase() {
        head = nullptr;
        // Pre-populate some historical database records
        addScore("Kay", "Demon", 450);
        addScore("Yui", "Dragon", 520);
    }

    void addScore(string warrior, string enemy, int score) {
        ScoreNode* newNode = new ScoreNode(warrior, enemy, score);
        if (!head || head->score < score) {
            newNode->next = head;
            head = newNode;
        } else {
            ScoreNode* current = head;
            while (current->next && current->next->score >= score) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void displayLeaderboard() {
        cout << "\n========================================\n";
        cout << "      BATTLE ART - LEADERBOARD        \n";
        cout << "========================================\n";
        if (!head) {
            cout << "No records found in database.\n";
            return;
        }
        ScoreNode* temp = head;
        int rank = 1;
        while (temp != nullptr) {
            cout << rank << ". Warrior: " << temp->warriorName << " | Boss Defeated: " << temp->enemyName << " | Score: " << temp->score << " XP\n";
            temp = temp->next;
            rank++;
        }
        cout << "----------------------------------------\n";
    }

    ~HighScoreDatabase() {
        ScoreNode* current = head;
        while (current != nullptr) {
            ScoreNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Class to manage the Customization Linked List workflow
class CustomizationManager {
public:
    CustomNode* head;

    CustomizationManager() {
        head = new CustomNode("Warrior", "Kay");
        head->next = new CustomNode("Enemy", "Demon");
        head->next->next = new CustomNode("Weapon", "Metal Sword");
    }

    void showCustomizationMenu() {
        int choice;
        
        while (true) {
            cout << "\n--- CUSTOMIZATION MENU (Linked List Config) ---\n";
            int index = 1;
            CustomNode* temp = head;
            while (temp != nullptr) {
                cout << index << ". Change " << temp->category << " [Current: " << temp->selectedOption << "]\n";
                temp = temp->next;
                index++;
            }
            cout << "4. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Select Warrior (1. Kay, 2. Yui, 3. Miyo, 4. Takashi, 5. Zuhu): ";
                int wChoice; cin >> wChoice;
                if (wChoice == 1) head->selectedOption = "Kay";
                else if (wChoice == 2) head->selectedOption = "Yui";
                else if (wChoice == 3) head->selectedOption = "Miyo";
                else if (wChoice == 4) head->selectedOption = "Takashi";
                else head->selectedOption = "Zuhu";
                cout << "Warrior updated successfully!\n";
            } 
            else if (choice == 2) {
                cout << "Select Enemy (1. Dragon, 2. Demon, 3. Goblin, 4. Kaal, 5. Dark Witch): ";
                int eChoice; cin >> eChoice;
                if (eChoice == 1) head->next->selectedOption = "Dragon";
                else if (eChoice == 2) head->next->selectedOption = "Demon";
                else if (eChoice == 3) head->next->selectedOption = "Goblin";
                else if (eChoice == 4) head->next->selectedOption = "Kaal";
                else head->next->selectedOption = "Dark Witch";
                cout << "Enemy updated successfully!\n";
            } 
            else if (choice == 3) {
                cout << "Select Weapon (1. Diamond Sword, 2. Metal Sword, 3. Black Mythical Metal Sword, 4. Double Sword, 5. Knife): ";
                int wpChoice; cin >> wpChoice;
                if (wpChoice == 1) head->next->next->selectedOption = "Diamond Sword";
                else if (wpChoice == 2) head->next->next->selectedOption = "Metal Sword";
                else if (wpChoice == 3) head->next->next->selectedOption = "Black Mythical Metal Sword";
                else if (wpChoice == 4) head->next->next->selectedOption = "Double Sword";
                else head->next->next->selectedOption = "Knife";
                cout << "Weapon updated successfully!\n";
            } 
            else if (choice == 4) {
                break;
            } 
            else {
                cout << "Invalid choice! Try again.\n";
            }
        }
    }

    string getWarrior() { return head->selectedOption; }
    string getEnemy() { return head->next->selectedOption; }
    string getWeapon() { return head->next->next->selectedOption; }

    ~CustomizationManager() {
        CustomNode* current = head;
        while (current != nullptr) {
            CustomNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Game Execution Logic integrated with High Score Database tracking
void playBattleGame(string warrior, string enemy, string weapon, HighScoreDatabase &db) {
    cout << "\n[Japanese BG: ~Shamisen & Epic Orchestral Beats Echo in the Background~]\n";
    cout << "Starting Battle: " << warrior << " equipped with " << weapon << " facing " << enemy << "!\n";
    
    int enemyXp = 500;
    int warriorHp = 100;
    int wp1 = 100, wp2 = 100, wp3 = 100;
    int lives = 3;
    int healingPotions = 1;
    char moveInput;

    cout << "\n--- CONTROL SYSTEM --- \n";
    cout << "[Keyboard Mapping] W: Front | A: Left | D: Right | S: Back | Space: Jump | Enter: Shoot/Attack\n";
    cout << "[Touch/Pad Mapping] Mobile Touch Screen Tap & Laptop Trackpad Gestures map directly to console entries.\n";
    cout << "Combat Actions: [1] Normal Attack (-3 WP) | [2] Charged Attack (-100 WP) | [3] Healing Potion (+10 HP)\n\n";

    while (lives > 0 && (wp1 > 0 || wp2 > 0 || wp3 > 0)) {
        cout << "\n----------------------------------------\n";
        cout << "Enemy Weak Points -> WP1: " << wp1 << "% | WP2: " << wp2 << "% | WP3: " << wp3 << "%\n";
        cout << "Warrior HP: " << warriorHp << "/100 | Lives Left: " << lives << " | Potions Left: " << healingPotions << "\n";
        cout << "Enter move (W:Front, A:Left, D:Right, S:Back, J:Jump, E:Shoot/Action): ";
        cin >> moveInput;

        int botAction = rand() % 3;
        if (botAction == 0) {
            int incomingDamage = 35;
            cout << ">> " << enemy << " fires an intense dark energy beam! You got hit for " << incomingDamage << " damage!\n";
            
            warriorHp -= incomingDamage;

            if (warriorHp <= 0) {
                lives--;
                cout << ">> ðŸ’€ Warrior HP reached 0! You lost a life.\n";
                
                if (lives > 0) {
                    warriorHp = 100; 
                    cout << ">> âœ¨ RESPAWN SUCCESSFUL! Revived with 100 HP. Lives remaining: " << lives << "\n";
                } else {
                    cout << "\n[GAME OVER] You have died 3 times! Returning to Main Menu.\n";
                    return;
                }
            } else {
                cout << ">> Warrior HP remaining: " << warriorHp << "/100\n";
            }
            continue;
        } else {
            cout << ">> You smoothly dodged the attack using floating bricks and touch controls!\n";
        }

        int combatAction;
        cout << "Choose Action -> 1. Normal Attack (3 HP damage) | 2. Charged Attack | 3. Use Healing Potion: ";
        cin >> combatAction;

        if (combatAction == 1) {
            int targetWp;
            cout << "Select Weak Point to strike (1, 2, or 3): ";
            cin >> targetWp;

            if (targetWp == 1 && wp1 > 0) {
                wp1 = max(0, wp1 - 3);
                enemyXp = max(0, enemyXp - 10);
                cout << ">> Normal Strike! WP1 drops by 3 HP. Current WP1: " << wp1 << "%\n";
            } else if (targetWp == 2 && wp2 > 0) {
                wp2 = max(0, wp2 - 3);
                enemyXp = max(0, enemyXp - 10);
                cout << ">> Normal Strike! WP2 drops by 3 HP. Current WP2: " << wp2 << "%\n";
            } else if (targetWp == 3 && wp3 > 0) {
                wp3 = max(0, wp3 - 3);
                enemyXp = max(0, enemyXp - 10);
                cout << ">> Normal Strike! WP3 drops by 3 HP. Current WP3: " << wp3 << "%\n";
            } else {
                cout << ">> Invalid or already destroyed weak point target!\n";
            }
        } 
        else if (combatAction == 2) {
            cout << ">> Charging up sword skill... [Holding position] ...\n";
            cout << ">> âœ¨ AURA EXPLOSION READY! Unleashing Charged Attack!\n";
            
            int targetWp;
            cout << "Target weak point for Charged Attack (1, 2, or 3): ";
            cin >> targetWp;

            if (targetWp == 1 && wp1 > 0) {
                wp1 = max(0, wp1 - 100);
                enemyXp = max(0, enemyXp - 150);
                cout << ">> BOOM! Charged strike devastates WP1 down to 0%!\n";
            } else if (targetWp == 2 && wp2 > 0) {
                wp2 = max(0, wp2 - 100);
                enemyXp = max(0, enemyXp - 150);
                cout << ">> BOOM! Charged strike devastates WP2 down to 0%!\n";
            } else if (targetWp == 3 && wp3 > 0) {
                wp3 = max(0, wp3 - 100);
                enemyXp = max(0, enemyXp - 150);
                cout << ">> BOOM! Charged strike devastates WP3 down to 0%!\n";
            } else {
                cout << ">> Missed target area!\n";
            }
        } 
        else if (combatAction == 3) {
            if (healingPotions > 0) {
                warriorHp = min(100, warriorHp + 10);
                healingPotions--;
                cout << ">> ðŸ§ª Healing potion consumed! Warrior HP increased by 10. Current HP: " << warriorHp << "/100\n";
            } else {
                cout << ">> No healing potions left in inventory!\n";
            }
        } 
        else {
            cout << ">> Invalid combat action selected.\n";
        }
    }

    if (wp1 == 0 && wp2 == 0 && wp3 == 0) {
        int finalScore = (lives * 100) + (warriorHp * 2); // Calculated victory performance score
        cout << "\n[VICTORY!] " << enemy << " shatters into pieces and disappears into thin air!\n";
        cout << ">> Legendary Treasure successfully added to " << warrior << "'s inventory!\n";
        cout << ">> Total Combat Score Achieved: " << finalScore << " XP\n";
        
        // Save score into linked list database
        db.addScore(warrior, enemy, finalScore);
        cout << ">> Your score has been logged to the high score!\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    CustomizationManager customMgr;
    HighScoreDatabase scoreDb;
    int choice;

    do {
        cout << "\n===============================\n";
        cout << "        BATTLE ART             \n";
        cout << "===============================\n";
        cout << "1. Game Start\n";
        cout << "2. Customization (Warrior, Enemy, Weapon)\n";
        cout << "3. Leaderboard\n";
        cout << "4. How to Play\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                playBattleGame(customMgr.getWarrior(), customMgr.getEnemy(), customMgr.getWeapon(), scoreDb);
                break;
            case 2:
                customMgr.showCustomizationMenu();
                break;
            case 3:
                scoreDb.displayLeaderboard();
                break;
            case 4:
                cout << "\n--- HOW TO PLAY ---\n";
                cout << "- Characters: Warriors (Kay, Yui, Miyo, Takashi, Zuhu). Enemies (Dragon, Demon, Goblin, Kaal, Dark Witch).\n";
                cout << "- Weapons: Diamond Sword, Metal Sword, Black Mythical Metal Sword, Double Sword, Knife.\n";
                cout << "- Controls: W (Front), A (Left), D (Right), S (Back), Space (Jump), Enter (Shoot/Attack).\n";
                cout << "- Accessibility: Fully mapped to support mobile touch screens and laptop trackpad gestures.\n";
                cout << "- Rules: Warrior starts with 100 HP and 3 lives. Losing all HP costs 1 life and respawns. Game ends on 3rd death.\n";
                cout << "- Objective: Reduce all 3 enemy weak points to 0% to defeat them, collect treasure, and save score to the Database.\n";
                break;
            case 5:
                cout << "Exiting game. Sayonara!\n";
                break;
            default:
                cout << "Invalid selection. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
