#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct contact_info
{
    char *name;
    char *phone_number;
    struct contact_info *next;
};

int main(int argc, char *argv[])
{

    struct contact_info *head = NULL;

    int menu;
    char end;

    do
    {
        printf("=======================================\n");
        printf("===        Phone number Book        ===\n");
        printf("=======================================\n");
        printf("=== 1. Insert new phone number      ===\n");
        printf("=== 2. Delete existing phone number ===\n");
        printf("=== 3. Update existing phone number ===\n");
        printf("=== 4. Show existing phone number   ===\n");
        printf("=== 5. Exit this program            ===\n");
        printf("=======================================\n\n");
        printf("Choose menu >> ");

        scanf("%d", &menu);
        if (menu > 5 && menu < 1)
        {
            printf("Choose correct one");
        }

        struct contact_info *new_node;
        new_node = (struct contact_info *)malloc(sizeof(struct contact_info));

        struct contact_info *current_node;
        current_node = head;

        char name[100] = {0};
        char phone_number[100] = {0};

        switch (menu)
        {
        case 1: // insert
            if (head == NULL)
            {

                printf("name: ");
                scanf("%s", name);
                printf("phone_number: ");
                scanf("%s", phone_number);
                new_node->name = strdup(name);
                new_node->phone_number = strdup(phone_number);
                new_node->next = NULL;
                head = new_node;
            }
            else
            {
                printf("name: ");
                scanf("%s", name);
                printf("phone_number: ");
                scanf("%s", phone_number);
                new_node->name = strdup(name);
                new_node->phone_number = strdup(phone_number);
                new_node->next = NULL;
                while (current_node->next != NULL)
                {
                    current_node = current_node->next;
                };
                current_node->next = new_node;
            }
            printf("1\n");
            break;
        case 2: // delete
            printf("2\n");
            break;
        case 3: // update
            printf("3\n");
            break;
        case 4: // display
            if (head == NULL)
            {
                printf("There is nothing\n");
            }
            else
            {
                struct contact_info *current_node;
                current_node = head;
                while (current_node != NULL)
                {
                    printf("name: %s \n", current_node->name);
                    printf("phone numbr: %s \n", current_node->phone_number);
                    current_node = current_node->next;
                }
            }
            break;
        case 5: // exit
            printf("5, bye\n");
            return 0;
        default:
            break;
        }
        printf("\n\tIf you want to continue, press enter key.. ");
        scanf("%c%c", &end, &end);
        system("clear");
    } while (menu != 5);

    return menu;
}