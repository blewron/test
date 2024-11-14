#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
struct Event {
    char name[50];
    char date[20];
    char time[20];
    int totalSeats;
    int bookedSeats;
    char seats[10][5];
};

struct User {
    char username[30];
    char password[30];
};

// Function prototypes
void displayMenu();
void showEvents(struct Event events[], int numEvents);
void showEventDetails(struct Event event);
void reserveTicket(struct Event *event, char username[]);
void cancelReservation(struct Event *event, char username[]);
void displaySeats(struct Event *event);
void purchaseTicket(struct Event *event, char username[]);
int login(struct User users[], int numUsers, char username[], char password[]);

// Main function
int main() {
    // Dummy data
    struct Event events[2] = {
        {"Concert", "2023-11-20", "18:00", 10, 0},
        {"Movie", "2023-11-25", "15:30", 10, 0}
    };

    struct User users[2] = {
        {"user1", "pass1"},
        {"user2", "pass2"}
    };

    int numEvents = sizeof(events) / sizeof(events[0]);
    int numUsers = sizeof(users) / sizeof(users[0]);

    char username[30];
    char password[30];
    int loggedInUser = -1;

    // User authentication
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    loggedInUser = login(users, numUsers, username, password);

    if (loggedInUser == -1) {
        printf("Invalid credentials. Exiting...\n");
        return 1;
    }

    int choice;
    int eventNum;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showEvents(events, numEvents);
                break;
            case 2:
                printf("Enter event number: ");
                scanf("%d", &eventNum);
                displaySeats(&events[eventNum - 1]);
                break;
            case 3:
                printf("Enter event number: ");
                scanf("%d", &eventNum);
                reserveTicket(&events[eventNum - 1], users[loggedInUser].username);
                break;
            case 4:
                printf("Enter event number: ");
                scanf("%d", &eventNum);
                purchaseTicket(&events[eventNum - 1], users[loggedInUser].username);
                break;
            case 5:
                printf("Enter event number: ");
                scanf("%d", &eventNum);
                cancelReservation(&events[eventNum - 1], users[loggedInUser].username);
                break;
            case 6:
                // Additional features can be added here
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

// Function definitions

void displayMenu() {
    printf("\n----- Menu -----\n");
    printf("1. Show Events\n");
    printf("2. Display Seats\n");
    printf("3. Reserve Ticket\n");
    printf("4. Purchase Ticket\n");
    printf("5. Cancel Reservation\n");
    printf("6. Additional Features\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void showEvents(struct Event events[], int numEvents) {
    printf("\n----- Events -----\n");
    for (int i = 0; i < numEvents; i++) {
        printf("%d. %s\n", i + 1, events[i].name);
    }
}

void showEventDetails(struct Event event) {
    printf("\n----- Event Details -----\n");
    printf("Name: %s\n", event.name);
    printf("Date: %s\n", event.date);
    printf("Time: %s\n", event.time);
    printf("Total Seats: %d\n", event.totalSeats);
    printf("Booked Seats: %d\n", event.bookedSeats);
}

void displaySeats(struct Event *event) {
    showEventDetails(*event);
    printf("\n----- Seat Availability -----\n");
    for (int i = 0; i < event->totalSeats; i++) {
        printf("Seat %d: %s\n", i + 1, event->seats[i]);
    }
}

void reserveTicket(struct Event *event, char username[]) {
    displaySeats(event);
    int seatNum;
    printf("\nEnter seat number to reserve: ");
    scanf("%d", &seatNum);

    // Check if the seat number is valid
    if (seatNum < 1 || seatNum > event->totalSeats) {
        printf("Invalid seat number.\n");
        return;
    }

    // Check if the seat is available
    if (strcmp(event->seats[seatNum - 1], "Available") == 0) {
        strcpy(event->seats[seatNum - 1], "Reserved");
        event->bookedSeats++;
        printf("Seat reserved successfully for %s.\n", username);
    } else {
        printf("Seat is already reserved.\n");
    }
}

// Rest of the functions...
