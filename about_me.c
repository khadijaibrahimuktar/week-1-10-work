// ============================================================
// ABOUT ME - C VERSION
// This program asks seven questions and displays a summary.
// ============================================================
#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

int main(void) {
    char name[MAX_LEN];
    char course[MAX_LEN];
    char hobby[MAX_LEN];
    char reason[MAX_LEN];
    char expectation[MAX_LEN];
    char definition[MAX_LEN];
    char favorite_food[MAX_LEN];

    printf("========================================\n");
    printf("   WELCOME TO YOUR FIRST C PROGRAM!\n");
    printf("========================================\n\n");

    printf("1. What is your name? ");
    fgets(name, MAX_LEN, stdin);
    name[strcspn(name, "\r\n")] = '\0';

    printf("2. What course are you doing? (BBIT/BCS): ");
    fgets(course, MAX_LEN, stdin);
    course[strcspn(course, "\r\n")] = '\0';

    printf("3. What is your hobby? ");
    fgets(hobby, MAX_LEN, stdin);
    hobby[strcspn(hobby, "\r\n")] = '\0';

    printf("4. Why did you choose this course? ");
    fgets(reason, MAX_LEN, stdin);
    reason[strcspn(reason, "\r\n")] = '\0';

    printf("5. What do you expect to learn in programming? ");
    fgets(expectation, MAX_LEN, stdin);
    expectation[strcspn(expectation, "\r\n")] = '\0';

    printf("6. In your own words, what is programming? ");
    fgets(definition, MAX_LEN, stdin);
    definition[strcspn(definition, "\r\n")] = '\0';

    printf("7. What is your favorite food? ");
    fgets(favorite_food, MAX_LEN, stdin);
    favorite_food[strcspn(favorite_food, "\r\n")] = '\0';

    printf("\n========================================\n");
    printf("   YOUR PROFILE SUMMARY\n");
    printf("========================================\n\n");

    printf("Name:           %s\n", name);
    printf("Course:         %s\n", course);
    printf("Hobby:          %s\n", hobby);
    printf("Reason:         %s\n", reason);
    printf("Expectation:    %s\n", expectation);
    printf("Programming is: %s\n", definition);
    printf("Favorite food:  %s\n", favorite_food);

    printf("\n========================================\n");
    printf("   Thank you for completing this!\n");
    printf("========================================\n");
    printf("Great job, %s!\n", name);

    return 0;
}
