#include <stdio.h>
#include <stdlib.h>
#define MAX_PLAYERS 100 // Define MAX_PLAYERS

struct Player {
    int id;
    int age;
    int goals;
    int shirtNumber;
    char position[20];
    char firstName[50];
    char lastName[50];
};

int nextid = 1;
struct Player team[MAX_PLAYERS];
int playerCount = 0;

struct Player addPlayer() { // Fixed syntax
    struct Player p;
    p.id = nextid++;

    printf("Enter first name: ");
    scanf("%s", p.firstName);
    printf("Enter last name: ");
    scanf("%s", p.lastName);
    printf("Enter shirt number: ");
    scanf("%d", &p.shirtNumber);
    printf("Enter position: ");
    scanf("%s", p.position);
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Enter how many goals: ");
    scanf("%d", &p.goals);

    // Basic validation
    if (p.age < 0 || p.goals < 0 || p.shirtNumber < 0) {
        printf("Invalid input! Age, goals, and shirt number must be non-negative.\n");
        p.id = 0; // Mark as invalid (optional handling)
    }

    return p;
}

void displayPlayers() { // Removed unused parameter
    if (playerCount == 0) {
        printf("No players added yet!\n");
        return;
    }
    for (int i = 0; i < playerCount; i++) {
        printf("\nPlayer %d Information:\n", i + 1);
        printf("ID: %d\n", team[i].id);
        printf("Name: %s %s\n", team[i].firstName, team[i].lastName);
        printf("Shirt Number: %d\n", team[i].shirtNumber);
        printf("Position: %s\n", team[i].position);
        printf("Age: %d\n", team[i].age);
        printf("Goals: %d\n", team[i].goals);
    }
}

int main() {
    int choice, choice2;

    do {
        printf("\n===== Football Team Management =====\n");
        printf("1 - Add a Player\n");
        printf("2 - Display Players\n");
        printf("3 - Delete Player\n");
        printf("4 - Modify Player\n");
        printf("5 - Search Player\n");
        printf("6 - Stats\n");
        printf("7 - Quit\n");
        printf("Select your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 7) {
            printf("Invalid choice!\n");
        }

        switch (choice) {
        case 1:
            printf("\n1 - Add a new Player\n");
            printf("2 - Add multiple Players\n");
            printf("Select your choice: ");
            scanf("%d", &choice2);

            switch (choice2) {
            case 1:
                if (playerCount < MAX_PLAYERS) {
                    team[playerCount] = addPlayer();
                    if (team[playerCount].id != 0) { // Check for valid player
                        playerCount++;
                        printf("Player added successfully!\n");
                    }
                } else {
                    printf("Team is full!\n");
                }
                break;
            case 2:
                printf("Add multiple Players:\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
            }
            break;

        case 2:
            printf("\n1 - Display all Players\n");
            printf("2 - Sort Players by Name\n");
            printf("3 - Sort Players by Age\n");
            printf("4 - Display Players by Position\n");
            printf("Select your choice: ");
            scanf("%d", &choice2);

            switch (choice2) {
            case 1:
                displayPlayers(); // Fixed call
                break;
            case 2:
                printf("Players sorted by Name:\n");
                break;
            case 3:
                printf("Players sorted by Age:\n");
                break;
            case 4:
                printf("Players by Position:\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
            }
            break;

        case 3:
            printf("Delete a Player by ID:\n");
            break;

        case 4:
            printf("\nModify Player:\n");
            printf("1 - Modify Position\n");
            printf("2 - Modify Age\n");
            printf("3 - Modify Number of Goals\n");
            printf("Select your choice: ");
            scanf("%d", &choice2);
            break;

        case 5:
            printf("\nSearch Player:\n");
            printf("1 - By ID\n");
            printf("2 - By Name\n");
            printf("Select your choice: ");
            scanf("%d", &choice2);
            break;

        case 6:
            printf("\nStats:\n");
            printf("1 - Total number of Players\n");
            printf("2 - Average Age of Players\n");
            printf("3 - Players with more than X Goals\n");
            printf("4 - Best Scorer\n");
            printf("5 - Youngest and Oldest Player\n");
            printf("Select your choice: ");
            scanf("%d", &choice2);
            break;

        case 7:
            printf("Sayonara !!\n");
            break;

        default:
            break;
        }
    } while (choice != 7);

    return 0;
}
