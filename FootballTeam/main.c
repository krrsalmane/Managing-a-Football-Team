#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PLAYERS 24

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



int isShirtNumberUnique(int shirtNumber) {
    for (int i = 0; i < playerCount; i++) {
        if (team[i].shirtNumber == shirtNumber) {
            return 0;
        }
    }
    return 1;
}

struct Player addPlayer() {
    struct Player p;
    p.id = nextid++;

    printf("Enter first name: ");
    scanf("%s", p.firstName);
    getchar();
    printf("Enter last name: ");
    scanf("%s", p.lastName);
    getchar();
    printf("Enter shirt number: ");
    scanf("%d", &p.shirtNumber);
    getchar();
    if (!isShirtNumberUnique(p.shirtNumber)) {
        printf("Shirt number %d is already taken!\n", p.shirtNumber);
        p.id = 0;
        return p;
    }

    int posChoice;
    printf("\nSelect position:\n");
    printf("1 - Goalkeeper\n");
    printf("2 - Defender\n");
    printf("3 - Midfielder\n");
    printf("4 - Forward\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &posChoice);
    getchar();

    switch (posChoice) {
        case 1:
            strcpy(p.position, "Goalkeeper");
            break;
        case 2:
            strcpy(p.position, "Defender");
            break;
        case 3:
            strcpy(p.position, "Midfielder");
            break;
        case 4:
            strcpy(p.position, "Forward");
            break;
        default:
            printf("Invalid choice! Defaulting to Forward.\n");
            strcpy(p.position, "Forward");
            break;
    }

    printf("Enter age: ");
    scanf("%d", &p.age);
    getchar();
    printf("Enter how many goals: ");
    scanf("%d", &p.goals);
    getchar();

    if (p.age < 0 || p.goals < 0 || p.shirtNumber < 0) {
        printf("Invalid input! Age, goals, and shirt number must be non-negative.\n");
        p.id = 0;
    }

    return p;
}

void addMultiplePlayers() {
    int numPlayers;
    printf("How many players to add? ");
    scanf("%d", &numPlayers);
    getchar();
    if (numPlayers <= 0) {
        printf("Number of players must be positive!\n");
        return;
    }
    if (playerCount + numPlayers > MAX_PLAYERS) {
        printf("Cannot add %d players, only %d spots left!\n", numPlayers, MAX_PLAYERS - playerCount);
        return;
    }
    for (int i = 0; i < numPlayers; i++) {
        printf("\nAdding player %d of %d:\n", i + 1, numPlayers);
        struct Player p = addPlayer();
        if (p.id != 0) {
            team[playerCount++] = p;
            printf("Player added!\n");
        } else {
            printf("Player not added due to invalid input.\n");
        }
    }
}

void displayPlayersByPosition() {
    int posChoice;
    int found = 0;

    printf("\nSelect position to display:\n");
    printf("1 - Goalkeeper\n");
    printf("2 - Defender\n");
    printf("3 - Midfielder\n");
    printf("4 - Forward\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &posChoice);
    getchar();

    char pos[20];
    switch (posChoice) {
        case 1: strcpy(pos, "Goalkeeper"); break;
        case 2: strcpy(pos, "Defender"); break;
        case 3: strcpy(pos, "Midfielder"); break;
        case 4: strcpy(pos, "Forward"); break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    for (int i = 0; i < playerCount; i++) {
        if (strcmp(team[i].position, pos) == 0) {
            printf("\nPlayer %d Information:\n", i + 1);
            printf("ID: %d\n", team[i].id);
            printf("Name: %s %s\n", team[i].firstName, team[i].lastName);
            printf("Shirt Number: %d\n", team[i].shirtNumber);
            printf("Position: %s\n", team[i].position);
            printf("Age: %d\n", team[i].age);
            printf("Goals: %d\n", team[i].goals);
            found = 1;
        }
    }

    if (found == 0) {
        printf("\nNo players found in position: %s\n", pos);
    }
}

void sortPlayersByAge() {
    for (int i = 0; i < playerCount - 1; i++) {
        for (int j = 0; j < playerCount - i - 1; j++) {
            if (team[j].age > team[j + 1].age) {
                struct Player temp = team[j];
                team[j] = team[j + 1];
                team[j + 1] = temp;
            }
        }
    }
}

void sortPlayersByName() {
    for (int i = 0; i < playerCount - 1; i++) {
        for (int j = 0; j < playerCount - i - 1; j++) {
            if (strcmp(team[j].lastName, team[j + 1].lastName) > 0) {
                struct Player temp = team[j];
                team[j] = team[j + 1];
                team[j + 1] = temp;
            }
        }
    }
}

void displayPlayers() {
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

void deletePlayer(int id) {
    int found = 0;
    for (int i = 0; i < playerCount; i++) {
        if (team[i].id == id) {
            found = 1;
            for (int j = i; j < playerCount - 1; j++) {
                team[j] = team[j + 1];
            }
            playerCount--;
            printf("Player with ID %d deleted successfully!\n", id);
            break;
        }
    }
    if (!found) {
        printf("Player with ID %d not found!\n", id);
    }
}

void modifyPlayerGoals(int id) {
    int found = 0;
    for (int i = 0; i < playerCount; i++) {
        if (team[i].id == id) {
            found = 1;
            printf("Enter the new goals scored for player ID %d: ", id);
            int newGoals;
            scanf("%d", &newGoals);
            getchar();
            if (newGoals < 0) {
                printf("Invalid goals!\n");
                return;
            }
            team[i].goals = newGoals;
            printf("Number of goals updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Player with ID %d not found!\n", id);
    }
}

void modifyPlayerAge(int id) {
    int found = 0;
    for (int i = 0; i < playerCount; i++) {
        if (team[i].id == id) {
            found = 1;
            printf("Enter new age for player ID %d: ", id);
            int newAge;
            scanf("%d", &newAge);
            getchar();
            if (newAge < 0) {
                printf("Invalid age! Age must be non-negative.\n");
                return;
            }
            team[i].age = newAge;
            printf("Age updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Player with ID %d not found!\n", id);
    }
}

void modifyPlayerPosition(int id) {
    int found = 0;
    for (int i = 0; i < playerCount; i++) {
        if (team[i].id == id) {
            found = 1;
            printf("\nSelect new position for player ID %d:\n", id);
            printf("1 - Goalkeeper\n");
            printf("2 - Defender\n");
            printf("3 - Midfielder\n");
            printf("4 - Forward\n");
            printf("Enter choice (1-4): ");
            int posChoice;
            scanf("%d", &posChoice);
            getchar();
            switch (posChoice) {
                case 1: strcpy(team[i].position, "Goalkeeper"); break;
                case 2: strcpy(team[i].position, "Defender"); break;
                case 3: strcpy(team[i].position, "Midfielder"); break;
                case 4: strcpy(team[i].position, "Forward"); break;
                default: printf("Invalid choice! Position unchanged.\n"); return;
            }
            printf("Position updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Player with ID %d not found!\n", id);
    }
}

void searchPlayerById() {
    int id, found = 0;
    printf("Enter Player ID to search: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < playerCount; i++) {
        if (team[i].id == id) {
            printf("\nPlayer Found:\n");
            printf("ID: %d\n", team[i].id);
            printf("Name: %s %s\n", team[i].firstName, team[i].lastName);
            printf("Shirt Number: %d\n", team[i].shirtNumber);
            printf("Position: %s\n", team[i].position);
            printf("Age: %d\n", team[i].age);
            printf("Goals: %d\n", team[i].goals);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No player found with ID: %d\n", id);
    }
}

void searchPlayerByName() {
    char name[50];
    int found = 0;
    printf("Enter Player Last Name to search: ");
    scanf("%s", name);
    getchar();

    for (int i = 0; i < playerCount; i++) {
        if (strcasecmp(team[i].lastName, name) == 0) {
            printf("\nPlayer Found:\n");
            printf("ID: %d\n", team[i].id);
            printf("Name: %s %s\n", team[i].firstName, team[i].lastName);
            printf("Shirt Number: %d\n", team[i].shirtNumber);
            printf("Position: %s\n", team[i].position);
            printf("Age: %d\n", team[i].age);
            printf("Goals: %d\n", team[i].goals);
            found = 1;
        }
    }

    if (!found) {
        printf("No player found with Last Name: %s\n", name);
    }
}

void totalPlayers() {
    printf("Total number of players: %d\n", playerCount);
}

void averageAge() {
    if (playerCount == 0) {
        printf("No players to calculate average age!\n");
        return;
    }
    int totalAge = 0;
    for (int i = 0; i < playerCount; i++) {
        totalAge += team[i].age;
    }
    float avgAge = (float)totalAge / playerCount;
    printf("Average age of players: %.1f years\n", avgAge);
}

void playersWithMoreThanXGoals(int x) {
    int found = 0;
    printf("Players with more than %d goals:\n", x);
    for (int i = 0; i < playerCount; i++) {
        if (team[i].goals > x) {
            found = 1;
            printf("ID: %d, Name: %s %s, Goals: %d\n",
                   team[i].id, team[i].firstName, team[i].lastName, team[i].goals);
        }
    }
    if (!found) {
        printf("No players with more than %d goals!\n", x);
    }
}

void bestScorer() {
    if (playerCount == 0) {
        printf("No players to find best scorer!\n");
        return;
    }
    int maxGoals = -1;
    printf("Best scorer(s):\n");
    for (int i = 0; i < playerCount; i++) {
        if (team[i].goals > maxGoals) {
            maxGoals = team[i].goals;
        }
    }
    for (int i = 0; i < playerCount; i++) {
        if (team[i].goals == maxGoals) {
            printf("%s %s (ID: %d) with %d goals\n",
                   team[i].firstName, team[i].lastName, team[i].id, team[i].goals);
        }
    }
}

void youngestAndOldestPlayer() {
    if (playerCount == 0) {
        printf("No players to find youngest and oldest!\n");
        return;
    }
    int minAge = team[0].age;
    int maxAge = team[0].age;
    for (int i = 1; i < playerCount; i++) {
        if (team[i].age < minAge) minAge = team[i].age;
        if (team[i].age > maxAge) maxAge = team[i].age;
    }
    printf("Youngest player(s):\n");
    for (int i = 0; i < playerCount; i++) {
        if (team[i].age == minAge) {
            printf("%s %s (ID: %d, Age: %d)\n",
                   team[i].firstName, team[i].lastName, team[i].id, team[i].age);
        }
    }
    printf("Oldest player(s):\n");
    for (int i = 0; i < playerCount; i++) {
        if (team[i].age == maxAge) {
            printf("%s %s (ID: %d, Age: %d)\n",
                   team[i].firstName, team[i].lastName, team[i].id, team[i].age);
        }
    }
}

int main() {
    struct Player fakeData[] = {
        {1, 30, 50, 7, "Forward", "Cristiano", "Ronaldo"},
        {2, 28, 40, 10, "Forward", "Lionel", "Messi"},
        {3, 35, 0, 1, "Goalkeeper", "Manuel", "Neuer"},
        {4, 32, 10, 4, "Defender", "Sergio", "Ramos"},
        {5, 33, 15, 8, "Midfielder", "Luka", "Modric"},
        {6, 25, 30, 9, "Forward", "Kylian", "Mbappe"},
        {7, 29, 5, 6, "Midfielder", "NGolo", "Kante"},
        {8, 31, 8, 5, "Defender", "Virgil", "VanDijk"},
        {9, 27, 25, 11, "Forward", "Neymar", "Jr"},
        {10, 34, 3, 3, "Defender", "Thiago", "Silva"},
        {11, 26, 20, 17, "Midfielder", "Kevin", "DeBruyne"},
        {12, 24, 0, 12, "Goalkeeper", "Gianluigi", "Donnarumma"},
        {13, 29, 12, 14, "Midfielder", "Toni", "Kroos"},
        {14, 27, 7, 2, "Defender", "Trent", "Arnold"},
        {15, 23, 35, 19, "Forward", "Erling", "Haaland"},
        {16, 25, 4, 15, "Defender", "Matthijs", "DeLigt"},
        {17, 24, 18, 20, "Midfielder", "Bruno", "Fernandes"},
        {18, 22, 22, 13, "Forward", "Vinicius", "Junior"},
        {19, 28, 0, 23, "Goalkeeper", "Alisson", "Becker"},
        {20, 30, 10, 16, "Midfielder", "Casemiro", ""}
    };
    playerCount = sizeof(fakeData) / sizeof(fakeData[0]);
    for (int i = 0; i < playerCount; i++) {
        team[i] = fakeData[i];
    }
    nextid = playerCount + 1;

    int choice, choice2;
    do {
        printf("\n ===== Football Team Management ===== \n");
        printf("1 - Add a Player\n");
        printf("2 - Display Players\n");
        printf("3 - Delete Player\n");
        printf("4 - Modify Player\n");
        printf("5 - Search Player\n");
        printf("6 - Stats\n");
        printf("7 - Quit\n");
        printf("Select your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice < 1 || choice > 7) {
            printf("Invalid choice!\n");
        }

        switch (choice) {
        case 1:
            printf("\n1 - Add a new Player\n");
            printf("2 - Add multiple Players\n");
            printf("Select your choice: ");
            scanf("%d", &choice2);
            getchar();
            switch (choice2) {
            case 1:
                if (playerCount < MAX_PLAYERS) {
                    team[playerCount] = addPlayer();
                    if (team[playerCount].id != 0) {
                        playerCount++;
                        printf("Player added successfully!\n");
                    }
                } else {
                    printf("Team is full!\n");
                }
                break;
            case 2:
                addMultiplePlayers();
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
            getchar();
            switch (choice2) {
            case 1:
                displayPlayers();
                break;
            case 2:
                sortPlayersByName();
                displayPlayers();
                break;
            case 3:
                sortPlayersByAge();
                displayPlayers();
                break;
            case 4:
                displayPlayersByPosition();
                break;
            default:
                printf("Invalid choice!\n");
                break;
            }
            break;

        case 3:
            printf("Enter Player ID to delete: ");
            int id;
            scanf("%d", &id);
            getchar();
            deletePlayer(id);
            break;

        case 4:
            printf("\nModify Player:\n");
            printf("1 - Modify Position\n");
            printf("2 - Modify Age\n");
            printf("3 - Modify Number of Goals\n");
            printf("Select your choice: ");
            scanf("%d", &choice2);
            getchar();
            if (choice2 >= 1 && choice2 <= 3) {
                printf("Enter Player ID to modify: ");
                int id;
                scanf("%d", &id);
                getchar();
                switch (choice2) {
                    case 1:
                        modifyPlayerPosition(id);
                        break;
                    case 2:
                        modifyPlayerAge(id);
                        break;
                    case 3:
                        modifyPlayerGoals(id);
                        break;
                }
            } else {
                printf("Invalid choice!\n");
            }
            break;

        case 5:
            printf("\nSearch Player:\n");
            printf("1 - By ID\n");
            printf("2 - By Name\n");
            printf("Select your choice: ");
            scanf("%d", &choice2);
            getchar();
            if (choice2 == 1) {
                searchPlayerById();
            } else if (choice2 == 2) {
                searchPlayerByName();
            } else {
                printf("Invalid choice!\n");
            }
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
            getchar();
            if (choice2 >= 1 && choice2 <= 5) {
                if (choice2 == 3) {
                    printf("Enter number of goals: ");
                    int x;
                    scanf("%d", &x);
                    getchar();
                    playersWithMoreThanXGoals(x);
                } else {
                    switch (choice2) {
                        case 1: totalPlayers(); break;
                        case 2: averageAge(); break;
                        case 4: bestScorer(); break;
                        case 5: youngestAndOldestPlayer(); break;
                    }
                }
            } else {
                printf("Invalid choice!\n");
            }
            break;

        case 7:
            printf(" ====   Sayonara   ==== !!!! \n");
            break;

        default:
            break;
        }
    } while (choice != 7);

    return 0;
}
