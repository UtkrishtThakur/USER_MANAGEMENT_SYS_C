
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX_USERS 10
#define CREDENTIAL_LENGHT 30
typedef struct
{
    char username[30];
    char password[30];
} user;
user users[MAX_USERS];
int user_count = 0;

void registration();
int login(); // Return the user credentials if registered
void fix_fgetsprob(char*);
void input_password(char*); // Fixed signature

int main()
{
    int user_index;
    int choice;
    while(1)
    {
        printf("Welcome to the user management system! \n");
        printf("1. Register \n 2. Login \n 3. Exit \n select you choice:");
        scanf("%d", &choice);
        getchar();//eats away the extra enter
        switch (choice)
        {
        case 1:
            registration();
            break;
        case 2:
            user_index = login();
            if (user_index >= 0)
            {
                printf("Login successfull! Welcome %s \n", users[user_index].username);
                printf("You can now access the system \n");
            }
            else
            {
                printf("Login failed. Please try again. \n");
            }
            break;
        case 3:
            printf("Exiting the program. Goodbye! \n");
            return 0;
        default:
            printf("Invalid choice ,Please try again. \n");
            break;
        }
    }
}

void registration()
{
    if (user_count >=MAX_USERS)
    {
        printf("User limit reached. Cannot register more users. \n");
        return;
    }
    int new_index=user_count;
    printf("Register a new user \nEnter your username: \n");
    fgets(users[new_index].username, sizeof(users[new_index].username), stdin);
    fix_fgetsprob(users[new_index].username);
    input_password(users[new_index].password);
    user_count++;
    printf("Registration successful \n");
}

int login()
{
    char username[30];
    char password[30];
    printf("Enter your username: \n");
    fgets(username, CREDENTIAL_LENGHT, stdin);
    fix_fgetsprob(username);
    input_password(password); 
    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(username,users[i].username)==0 && strcmp(password, users[i].password)==0)
        {
            return i; 
        }
    }
    return -1; // If not found
}

// Masked password input 
void input_password(char* password)
{
    printf("Enter your password: \n");
    int i = 0;
    char ch;
    while ((ch = getch()) != '\r' && i < CREDENTIAL_LENGHT - 1) { // '\r' is Enter key
        if (ch == '\b' && i > 0) { // handle backspace
            printf("\b \b");
            i--;
        } else if (ch != '\b') {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
    printf("\n");
}

void fix_fgetsprob(char* str)
{
    int index = strcspn(str, "\n");
    str[index] = '\0'; // Use single quotes for char
}