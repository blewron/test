#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int i = 0;
static int k = 0;
static int o=0;
int t;
struct users {
    char username[30];
    char password[30];
    // should also include my bookings column
} admin[10],audience[10];
void signup_audience() {
    printf("enter username: ");
    fgets(audience[o].username, sizeof(audience[o].username), stdin);
    printf("enter password: ");
    fgets(audience[o].password, sizeof(audience[o].password), stdin);
    i++;
}
int login_audience() {
    char username_given[30];
    char password_given[30];
    printf("enter username: ");
    fgets(username_given, sizeof(username_given), stdin);
    printf("enter password: ");
    fgets(password_given, sizeof(password_given), stdin);
    for (int j = 0; j < 10; j++) {
        if (strcmp(username_given, audience[j].username) == 0) {
            if (strcmp(password_given, audience[j].password) == 0) {
                printf("successfully logged in\n");
                // Assuming you have a main function where you call login/menu functions
                // menu();
                return 1;
            } else {
                printf("your password is incorrect\n");
                return 0;
            }
        }
    }
    printf("you are not registered or your username is incorrect\n");
    return 0;
}

int admin_or_audience(){
	int a;
	printf("1.Admin\n2.Audience");
	scanf("%d",&a);
	return a;
}
struct event {
    char date[15];
    char time[10];
    char name[30];
    char celebrity[30];
    char venue[20];
    float price;
    int totalSeats;  // Added totalSeats member to the event structure
    int seatsBooked; // Added seatsBooked member to the event structure to keep track of booked seats
    char seats[20];
} events[5];

void displaySeats(int p) {
    printf("\n----- Seat Availability -----\n");
    for (int i = 0; i < events[p-1].totalSeats; i++) {
        printf("Seat %d: %c\n", i + 1, events[p-1].seats[i]);
    }
}

void reserveTicket() {
	printf("enter the event number you want to reserve: ");
    	       int event_no;
    	       scanf("%d",&event_no);
    	       displaySeats(event_no);
    int seatNum;
    printf("\nEnter seat number to reserve: ");
    scanf("%d", &seatNum);

    // Check if the seat number is valid
    if (seatNum < 1 || seatNum > events[event_no].totalSeats) {
        printf("Invalid seat number.\n");
        return;
    }

    // Check if the seat is available
    if (strcmp(events[event_no-1].seats[seatNum - 1], "A") == -1) {
        strcpy(events[event_no-1].seats[seatNum - 1], "R");
        events[event_no-1].seatsBooked++;
        printf("Seat reserved successfully for %s.\n", audience[k].username);
    } else {
        printf("Seat is already reserved.\n");
    }
}
void purchaseTicket() {
	 printf("enter the event number you want to purchase ticket of: ");
	 int event_no;
	 scanf("%d",&event_no);
	  printf("enter the seat number you want to purchase ticket of: ");
	         displaySeats(event_no);
    	       int seat_no;
    	       scanf("%d",&seat_no);

    if (strcmp(events[event_no-1].seats[seat_no - 1], "R") == 0) {
        strcpy(events[event_no-1].seats[seat_no - 1], "B");
        printf("Ticket purchased successfully for %s.\n", audience[k].username);
    } else {
        printf("Seat not reserved for purchase.\n");
    }
}

void cancelReservation() {
		 printf("enter the event number you want to cancel ticket of: ");
	 int event_no;
	 scanf("%d",&event_no);
	  printf("enter the seat number you want to cancel ticket of: ");
	         displaySeats(event_no);
    	       int seat_no;
    	       scanf("%d",&seat_no);
    displaySeats(event_no);
    if (strcmp(events[event_no].seats[seat_no - 1], "R") == 0 || strcmp(events[event_no].seats[seat_no - 1], "B") == 0 ) {
        strcpy(events[event_no].seats[seat_no - 1], "A");
        events[event_no].seatsBooked--;
        printf("Reservation canceled successfully for %s.\n",audience[k].username);
    } else {
        printf("Seat not reserved for cancellation.\n");
    }
}


void Menu_audience() {
    printf("\n----- Menu -----\n");
    printf("1. Show Events\n");
    printf("2. Display Seats\n");
    printf("3. Reserve Ticket\n");
    printf("4. Purchase Ticket\n");
    printf("5. Cancel Reservation\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    int menu_chosen;
    scanf("%d",&menu_chosen);
    switch(menu_chosen){
    	case 1: show_events();
    	break;
    	case 2: printf("enter the event number you want  to see seats of: ");
    	       int event_no;
    	       scanf("%d",&event_no);
    	       displaySeats(event_no);
    		break;
    		case 3: reserveTicket();
    		break;
    		case 4:purchaseTicket();
    		break;
    		case 5:cancelReservation();
    		break;
    		case 0: exit(0);
    		default : printf("not a valid choice ");
    		break;
	}
}

void sales_data() {
    int event_choice;
    printf("Enter the event you want to see sales data of: ");
    scanf("%d", &event_choice);

    if (event_choice >= 1 && event_choice <= k) {// sales data me kuch to theek karna hai
        float ticketPrice = events[event_choice - 1].price;
        int totalSeats = events[event_choice - 1].totalSeats;
        int seatsBooked = events[event_choice - 1].seatsBooked;

        printf("Total seats available for Event %d: %d\n", event_choice, totalSeats);
        printf("Number of seats booked for Event %d: %d\n", event_choice, seatsBooked);

        float totalSales = ticketPrice * seatsBooked;
        printf("Total sales for Event %d: $%.2f\n", event_choice, totalSales);
        exit(0);
    } else {
        printf("Invalid event choice.\n");
        exit(0);
    }
}
void signup() {
    printf("enter username: ");
    fgets(admin[i].username, sizeof(admin[i].username), stdin);
    printf("enter password: ");
    fgets(admin[i].password, sizeof(admin[i].password), stdin);
    i++;
}

int login() {
    char username_given[30];
    char password_given[30];
    printf("enter username: ");
    fgets(username_given, sizeof(username_given), stdin);
    printf("enter password: ");
    fgets(password_given, sizeof(password_given), stdin);
    for (int j = 0; j < 10; j++) {
        if (strcmp(username_given, admin[j].username) == 0) {
            if (strcmp(password_given, admin[j].password) == 0) {
                printf("successfully logged in\n");
                // Assuming you have a main function where you call login/menu functions
                // menu();
                return 1;
            } else {
                printf("your password is incorrect\n");
                return 0;
            }
        }
    }
    printf("you are not registered or your username is incorrect\n");
    return 0;
}
void show_events() {
    for (int l = 0; l <= k; l++) {
        printf("%d event name: %s\n", l + 1, events[l].name);
        printf("%d event host: %s\n", l + 1, events[l].celebrity);
        printf("%d event date: %s\n", l + 1, events[l].date);
        printf("%d event time: %s\n", l + 1, events[l].time);
        printf("%d event venue: %s\n", l + 1, events[l].venue);
        printf("%d event price of 1 ticket: %f\n", l + 1, events[l].price);
    }
}
void add_event() {
    printf("Enter event name: ");
    scanf("%s", events[k].name);
    printf("Enter event host: ");
    scanf("%s", events[k].celebrity);
    printf("Enter event date: ");
    scanf("%s", events[k].date);
    printf("Enter event time: ");
    scanf("%s", events[k].time);
    printf("Enter event venue: ");
    scanf("%s", events[k].venue);
    printf("Enter total number of seats: ");
    scanf("%d", &events[k].totalSeats);
    printf("Enter per ticket price: ");
    scanf("%f", &events[k].price);
    events[k].seatsBooked = 0; // Initialize seatsBooked to 0 for the newly added event
    printf("Event added successfully\n");
    k++;
    show_events();
}

void remove_event() {
    show_events();
    printf("enter the event you want to cancel: ");
    int choice_remove;
    scanf("%d", &choice_remove);

    if (choice_remove >= 1 && choice_remove <= k) {
        for (int m = choice_remove - 1; m < k - 1; m++) {
            events[m] = events[m + 1];
        }
        k--;
        printf("Event removed successfully\n");
    } else {
        printf("Invalid choice\n");
    }
}
void menu() {
    int menu_chosen;
    while (1) {
        printf("1.Manage events\n2.view sales data\n3.exit\n");
        scanf("%d", &menu_chosen);
        switch (menu_chosen) {
            case 1:
                printf("1.view events\n2.add events\n3.remove events\n4.exit");
                int choice1;
                scanf("%d", &choice1);
                switch (choice1) {
                    case 1:
                        show_events();
                        break;
                    case 2:
                        add_event();
                        break;
                    case 3:
                        remove_event();
                        break;
                    case 4:
                        exit(0);
                    default:
                        printf("not a valid choice\n");
                        break;
                }
                break;
            case 2:
                show_events();
                int event_choice;
                printf("enter the event you want to see sales data of ");
                scanf("%d", &event_choice);
                sales_data();
                break;
            case 3:
                exit(0);
            default:
                printf("not a valid choice\n");
                break;
        }
    }
}


// ... (unchanged code)




// ... (unchanged code)

int main() {
	
for(t=0;t<10;t++){
	for(int d=0;d<20;d++){
	strcpy(events[t].seats[d],'A');
}
}
    // Sample initialization of an event for testing
    strcpy(events[0].name, "Sample Event");
    strcpy(events[0].celebrity, "Sample Celebrity");
    strcpy(events[0].date, "2023-12-01");
    strcpy(events[0].time, "18:00");
    strcpy(events[0].venue, "Sample Venue");
    events[0].totalSeats = 100;
    events[0].price = 25.0;
    events[0].seatsBooked = 50; // Assuming 50 seats are already booked for the sample event
    int ad_au=admin_or_audience();
    if(ad_au==1){
     signup();
   	  int returned=login();
    if(returned==1)
    menu();
	}
    else {
    signup_audience();
     int returned_au=login_audience();
    if(returned_au==1)
    menu_audience();
}
    // You can add further logic here based on the result of login

    return 0;
}