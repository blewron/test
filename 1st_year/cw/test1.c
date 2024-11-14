#include <stdio.h>

struct book {
    char title[100];
    int publicationyear;
    float price;
    char author[100];
};

struct inventory {
    char publisher[100];
    struct book b[8];
};

void newbooks(struct inventory inv[8]);
void display(struct inventory inv[8]);
void search(struct inventory inv[8], char name[100]);
void searchByPublisher(struct inventory inv[8], char publisher[100]);

int main() {
    struct inventory inv[8] = {
        {"rajkamal", {{"sun and the moon", 2014, 6969.50, "rajkamal"}}},
        {"kabira", {{" halwa h re ", 2016, 669.50, "kabira"}}},
        {"rohan", {{"step daughter's love", 2006, 3456.40, "rohan"}}},
        {"munshi prem chand", {{"king kong", 2022, 2345.45, "munshi prem chand"}}},
        {"chetan luna", {{"jalwa", 1969, 1234.50, "chetan luna"}}},
        {"sasuke", {{"naruto", 2003, 768.23, "sasuke"}}}
    };

    int choice;

    do {
        printf("\nEnter your choice [1(for adding new books), 2(for display), 3(for search), 0(for exit)]: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                newbooks(inv);
                break;

            case 2:
                display(inv);
                break;

            case 3:
                char searchTerm[100];
                printf("Enter the title or publisher of the book to search for: ");
                scanf(" %[^\n]s", searchTerm);
                search(inv, searchTerm);
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}

void newbooks(struct inventory inv[8]) {
    for (int i = 6; i < 8; i++) {
        printf("Enter Book title: ");
        scanf(" %[^\n]s", inv[i].b[0].title);
        printf("Enter the publication year of the Book: ");
        scanf("%d", &inv[i].b[0].publicationyear);
        printf("Enter the price of the Book: ");
        scanf("%f", &inv[i].b[0].price);
        printf("Enter the author Name: ");
        scanf(" %[^\n]s", inv[i].b[0].author);
        printf("Enter the publisher name: ");
        scanf(" %[^\n]s", inv[i].publisher);
    }
}

void display(struct inventory inv[8]) {
    printf("\nBook Inventory:\n");

    for (int i = 0; i < 8; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("  Title: %s\n", inv[i].b[0].title);
        printf("  Publication Year: %d\n", inv[i].b[0].publicationyear);
        printf("  Price: %.2f\n", inv[i].b[0].price);
        printf("  Author: %s\n", inv[i].b[0].author);
        printf("  Publisher: %s\n", inv[i].publisher);
    }
}

void search(struct inventory inv[8], char searchTerm[100]) {
    int flag = 0;
    for (int j = 0; j < 8; ++j) {
        if (strstr(inv[j].b[0].title, searchTerm) || strstr(inv[j].publisher, searchTerm)) {
            printf("\nTitle: %s\nAuthor: %s\nPublisher: %s\nYear Published: %d\nPrice: %.2f\n",
                   inv[j].b[0].title, inv[j].b[0].author, inv[j].publisher,
                   inv[j].b[0].publicationyear, inv[j].b[0].price);
            flag = 1;
        }
    }
    if (!flag) {
        printf("No books matching the search term '%s' found!\n", searchTerm);
    }
}
