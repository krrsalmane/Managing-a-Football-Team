#include <stdio.h>
#include <stdlib.h>
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

struct Player addPlayer() {
    struct Player p;
    p.id = nextid++;

    printf("Enter first name: ");
    scanf("%s", p.firstName);
    printf("Enter last name: ");
    scanf("%s", p.lastName);
    printf("Enter shirt number: ");
    scanf("%d", &p.shirtNumber);


    int posChoice;
    printf("\nSelect position:\n");
    printf("1 - Goalkeeper\n");
    printf("2 - Defender\n");
    printf("3 - Midfielder\n");
    printf("4 - Forward\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &posChoice);

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
    printf("Enter how many goals: ");
    scanf("%d", &p.goals);


    if (p.age < 0 || p.goals < 0 || p.shirtNumber < 0) {
        printf("Invalid input! Age, goals, and shirt number must be non-negative.\n");
        p.id = 0;
    }

    return p;
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

    // all players
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

                // Swap players
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
            for (int j = i; j < playerCount - 1; j++)  // shifting step P2 to P1
                {
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
void modifyPlayerGoals(int id){
        int found = 0;
        for(int i =0; i < playerCount;i++){
            if (team[i].id == id){
                found = 1;
                printf("Enter the new goals scored for player ID %d: ",id);
                int newGoals;
                scanf("%d",&newGoals);
                if(newGoals <= 0){
                    printf(" Invalid goals !!");
                    return;
                }
                team[i].goals=newGoals;
                printf("numbers of goals updates successfully ");
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

void searchPlayerByID() {
    int id, found = 0;
    printf("Enter Player ID to search: ");
    scanf("%d", &id);

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
                    if (team[playerCount].id != 0) {
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
            deletePlayer(id);
            break;

        case 4:
          printf("\nModify Player:\n");
            printf("1 - Modify Position\n");
            printf("2 - Modify Age\n");
            printf("3 - Modify Number of Goals\n");
            printf("Select your choice: ");
            scanf("%d", &choice2);
            if (choice2 >= 1 && choice2 <= 3) {
                printf("Enter Player ID to modify: ");
                int id;
                scanf("%d", &id);
                switch (choice2) {
                    case 1:
                        modifyPlayerPosition(id);
                        break;
                    case 2:
                        modifyPlayerAge( id);
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
            printf(" ====   Sayonara   ==== !!!! \n");
            break;

        default:
            break;
        }
    } while (choice != 7);

    return 0;
}
