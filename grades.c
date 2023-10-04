

#include <stdio.h>
#include <math.h>

struct Trainee {
    int id;
    float grade;
};

// Function to record grades values 
void recordGrades(struct Trainee trainees[], int numTrainees) {
    for (int i = 0; i < numTrainees; i++) {
        printf("Enter the grade for trainee %d (between 0 and 20): ", i + 1);
        scanf("%f", &trainees[i].grade);

        // Ensure the grade is within the valid range
        while (trainees[i].grade < 0 || trainees[i].grade > 20) {
            printf("Invalid grade. Enter a grade between 0 and 20: ");
            scanf("%f", &trainees[i].grade);
        }
    }
}

// Function to check the recorded grades values 
void checkGrades(struct Trainee trainees[], int numTrainees) {
    printf("Recorded grades:\n");
    for (int i = 0; i < numTrainees; i++) {
        printf("Trainee %d (ID %d): %.2f\n", i + 1, trainees[i].id, trainees[i].grade);
    }
}

// Function to set all grades to zero
void resetGrades(struct Trainee trainees[], int numTrainees) {
    for (int i = 0; i < numTrainees; i++) {
        trainees[i].grade = 0.0;
    }
    printf("All grades have been set to zero.\n");
}

// Function to calculate the average of the UFCD grades
float calculateAverage(struct Trainee trainees[], int numTrainees) {
    float sum = 0.0;
    for (int i = 0; i < numTrainees; i++) {
        sum += trainees[i].grade;
    }
    return (numTrainees > 0) ? (sum / numTrainees) : 0.0;
}

// Function to check negative grades and their owners
void checkNegativeGrades(struct Trainee trainees[], int numTrainees) {
    printf("Negative grades and their owners:\n");
    for (int i = 0; i < numTrainees; i++) {
        if (trainees[i].grade < 10) {
            printf("Trainee %d (ID %d): %.2f\n", i + 1, trainees[i].id, trainees[i].grade);
        }
    }
}

// Function to check positive grades and their owners
void checkPositiveGrades(struct Trainee trainees[], int numTrainees) {
    printf("Positive grades and their owners:\n");
    for (int i = 0; i < numTrainees; i++) {
        if (trainees[i].grade >= 10) {
            printf("Trainee %d (ID %d): %.2f\n", i + 1, trainees[i].id, trainees[i].grade);
        }
    }
}

int main() {
    int numTrainees;

    printf("How many trainees do you want to register? (maximum 20): ");
    scanf("%d", &numTrainees);

    if (numTrainees <= 0 || numTrainees > 20) {
        printf("Invalid number of trainees.\n");
        return 1;
    }

    struct Trainee trainees[numTrainees];

    // Initialize trainee IDs
    for (int i = 0; i < numTrainees; i++) {
        trainees[i].id = i + 1;
    }

    //menu options
    int option;
    do {
        printf("\nOptions:\n");
        printf("1. Record values (grades)\n");
        printf("2. Check the recorded values (grades)\n");
        printf("3. Set all grades to zero\n");
        printf("4. Calculate the average of UFCD grades\n");
        printf("5. Check negative grades and their owners\n");
        printf("6. Check positive grades and their owners\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        //switch options
        switch (option) {
            case 1:
                recordGrades(trainees, numTrainees);
                break;
            case 2:
                checkGrades(trainees, numTrainees);
                break;
            case 3:
                resetGrades(trainees, numTrainees);
                break;
            case 4:
                printf("Average of UFCD grades: %.2f\n", calculateAverage(trainees, numTrainees));
                break;
            case 5:
                checkNegativeGrades(trainees, numTrainees);
                break;
            case 6:
                checkPositiveGrades(trainees, numTrainees);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 0);

    return 0;
}
