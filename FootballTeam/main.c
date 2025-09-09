#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    int choice2;

    do
    {
        printf("\n=====  Football Team Management =====\n");
        printf("1 - Add a Player\n");
        printf("2 - Display Players\n");
        printf("3 - Delete Player\n");
        printf("4 - Modify Player\n");
        printf("5 - Search Player\n");
        printf("6 - Stats\n");
        printf("7 - Quit\n");
        printf("Select your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 7)
        {
            printf("Invalid choice!\n");
        }

        switch (choice)
        {
        case 1:
            printf("\n1 - Add a new Player\n");
            printf("2 - Add multiple Players\n");
            printf("Select your choice: ");
            scanf("%d", &choice2);

            switch (choice2)
            {
            case 1:
                printf("Add a new Player:\n");
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

            switch (choice2)
            {
            case 1:
                printf("List of all Players:\n");
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

            switch (choice2)
            {
            case 1:
                printf("Modify Player's Position:\n");
                break;
            case 2:
                printf("Modify Player's Age:\n");
                break;
            case 3:
                printf("Modify Player's Number of Goals:\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
            }
            break;

        case 5:
            printf("\nSearch Player:\n");
            printf("1 - By ID\n");
            printf("2 - By Name\n");
            printf("Select your choice: ");
            scanf("%d", &choice2);

            switch (choice2)
            {
            case 1:
                printf("Search Player by ID:\n");
                break;
            case 2:
                printf("Search Player by Name:\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
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

            switch (choice2)
            {
            case 1:
                printf("Total number of Players:\n");
                break;
            case 2:
                printf("Average Age of Players:\n");
                break;
            case 3:
                printf("Players with more than X Goals:\n");
                break;
            case 4:
                printf("Best Scorer:\n");
                break;
            case 5:
                printf("Youngest and Oldest Player:\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
            }
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
