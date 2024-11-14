#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char date[20];
    char time[20];
    int totalSeats;
    int bookedSeats;
    char seats[10][8];
} Event;

typedef struct {
    char username[30];
    char password[30];
} User;

typedef struct {
    char username[50];
    char password[50];
} Admin;

// Function prototypes
void displayMenu();
void showEvents(Event events[], int numEvents);
void showEventDetails(Event event);
void reserveTicket(Event *event, char username[]);
void cancelReservation(Event *event, char username[]);
void displaySeats(Event *event);
void purchaseTicket(Event *event, char username[]);
int userLogin(User users[], int numUsers, char username[], char password[]);
int adminLogin(Admin admin[], int numAdmins);

void signup(Admin admin[], int *adminCount);
void menu(Event events[], int *eventCount);
void manageEvents(Event events[], int *eventCount);
void showEvents(Event events[], int numEvents);
void addEvent(Event events[], int *eventCount);
void removeEvent(Event events[], int *eventCount);
void salesData(Event events[], int numEvents);

int main() {
    // Dummy data
    Event events[2] = {
        {"Concert", "2023-11-20", "18:00", 100, 0},
        {"Movie", "2023-11-25", "15:30", 80, 0}
    };

    User users[2] = {
        {"user1", "pass1"},
        {"user2", "pass2"}
    };

    Admin admin[50];
    int adminCount = 0;

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

loggedInUser = userLogin(users, numUsers, username, password);

if (loggedInUser == -1) {
    // Check admin login
    if (!adminLogin(admin, adminCount)) {
        printf("Invalid credentials. Exiting...\n");
        return 1;
    }
}


    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showEvents(events, numEvents);
                break;
            case 2:
                displaySeats(&events[0]);
                break;
            case 3:
                reserveTicket(&events[0], users[loggedInUser].username);
                break;
            case 4:
                purchaseTicket(&events[0], users[loggedInUser].username);
                break;
            case 5:
                cancelReservation(&events[0], users[loggedInUser].username);
                break;
            case 6:
                // Additional features can be added here
                break;
            case 7:
                menu(events, &numEvents);
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
    printf("7. Admin Menu\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void showEvents(Event events[], int numEvents) {
    printf("\n----- Events -----\n");
    for (int i = 0; i < numEvents; i++) {
        printf("%d. %s\n", i + 1, events[i].name);
    }
}

void showEventDetails(Event event) {
    printf("\n----- Event Details -----\n");
    printf("Name: %s\n", event.name);
    printf("Date: %s\n", event.date);
    printf("Time: %s\n", event.time);
    printf("Total Seats: %d\n", event.totalSeats);
    printf("Booked Seats: %d\n", event.bookedSeats);
}

void displaySeats(Event *event) {
    showEventDetails(*event);
    printf("\n----- Seat Availability -----\n");
    for (int i = 0; i < event->totalSeats; i++) {
        printf("Seat %d: %s\n", i + 1, event->seats[i]);
    }
}

void reserveTicket(Event *event, char username[]) {
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

void purchaseTicket(Event *event, char username[]) {
    displaySeats(event);
    int seatNum;
    printf("\nEnter seat number to purchase: ");
    scanf("%d", &seatNum);

    if (strcmp(event->seats[seatNum - 1], "Reserved") == 0) {
        strcpy(event->seats[seatNum - 1], "Booked");
        printf("Ticket purchased successfully for %s.\n", username);
    } else {
        printf("Seat not reserved for purchase.\n");
    }
}

void cancelReservation(Event *event, char username[]) {
    displaySeats(event);
    int seatNum;
    printf("\nEnter seat number to cancel reservation: ");
    scanf("%d", &seatNum);

    if (strcmp(event->seats[seatNum - 1], "Reserved") == 0) {
        strcpy(event->seats[seatNum - 1], "Available");
        event->bookedSeats--;
        printf("Reservation canceled successfully for %s.\n", username);
    } else {
        printf("Seat not reserved for cancellation.\n");
    }
}

int userLogin(User users[], int numUsers, char username[], char password[]) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful. Welcome, %s!\n", username);
            return i;
        }
    }
    return -1;
}

int adminLogin(Admin admin[], int numAdmins) {
    char username[50];
    char password[50];
    printf("Enter admin username: ");
    scanf("%s", username);
    printf("Enter admin password: ");
    scanf("%s", password);

    for (int i = 0; i < numAdmins; i++) {
        if (strcmp(admin[i].username, username) == 0 && strcmp(admin[i].password, password) == 0) {
            printf("Admin login successful. Welcome, %s!\n", username);
            return 1;
        }
    }
    return 0;
}

void signup(Admin admin[], int *adminCount) {
    Admin newAdmin;

    // Manually set the username and password
    strcpy(newAdmin.username, "admin1");
    strcpy(newAdmin.password, "pass1");

    admin[(*adminCount)++] = newAdmin;
}

void menu(Event events[], int *eventCount) {
    int choice;
    do {
        printf("\nAdmin Menu\n");
        printf("1. Manage Events\n");
        printf("2. View Sales Data\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manageEvents(events, eventCount);
                break;
            case 2:
                salesData(events, *eventCount);
                break;
            case 3:
                printf("Going back to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

void manageEvents(Event events[], int *eventCount) {
    int choice;
    do {
        printf("\nManage Events\n");
        printf("1. Show Events\n");
        printf("2. Add Event\n");
        printf("3. Remove Event\n");
        printf("4. Back to Admin Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showEvents(events, *eventCount);
                break;
            case 2:
                addEvent(events, eventCount);
                break;
            case 3:
                removeEvent(events, eventCount);
                break;
            case 4:
                printf("Going back to admin menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}



void addEvent(Event events[], int *eventCount) {
    Event newEvent;
    printf("Enter event name: ");
    scanf("%s", newEvent.name);
    printf("Enter date: ");
    scanf("%s", newEvent.date);
    printf("Enter time: ");
    scanf("%s", newEvent.time);
    printf("Enter total seats: ");
    scanf("%d", &newEvent.totalSeats);
    newEvent.bookedSeats = 0;

    for (int i = 0; i < newEvent.totalSeats; i++) {
        strcpy(newEvent.seats[i], "Available");
    }

    events[(*eventCount)++] = newEvent;
}

void removeEvent(Event events[], int *eventCount) {
    char eventName[50];
    printf("Enter event name to remove: ");
    scanf("%s", eventName);

    for (int i = 0; i < *eventCount; i++) {
        if (strcmp(events[i].name, eventName) == 0) {
            // Shift events to remove the specified event
            for (int j = i; j < *eventCount - 1; j++) {
                events[j] = events[j + 1];
            }
            (*eventCount)--;
            printf("Event removed successfully.\n");
            return;
        }
    }

    printf("Event not found.\n");
}

void salesData(Event events[], int numEvents) {
    for (int i = 0; i < numEvents; i++) {
        printf("%s\n", events[i].name);
        printf("Total Seats: %d\n", events[i].totalSeats);
        printf("Booked Seats: %d\n", events[i].bookedSeats);
        printf("Available Seats: %d\n", events[i].totalSeats - events[i].bookedSeats);
    }
}
