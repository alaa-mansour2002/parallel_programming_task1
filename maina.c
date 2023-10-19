#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20

struct User {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    int isActive;
};

struct User users[MAX_USERS];
int userCount = 0;

void register_Users() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }

    struct User newUser;
    printf("Enter a username: ");
    scanf("%s", newUser.username);

    printf("Enter a password: ");
    scanf("%s", newUser.password);

    printf("Set account status (1 for active, 0 for inactive): ");
    scanf("%d", &newUser.isActive);

    users[userCount] = newUser;
    userCount++;

    printf("Registration successful!\n");
}

void login_Users() {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);
    int i=0;
    for ( i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            if (users[i].isActive) {
                printf("Login successful!\n");
            } else {
                printf("Login failed. This account is inactive.\n");
            }
            return;
        }
    }

    printf("Login failed. Invalid username or password.\n");
}

int main() {
    int choice;

    do {
        printf("\nchoose just one:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_Users();
                break;
            case 2:
                login_Users();
                break;
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
