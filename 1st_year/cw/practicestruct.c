#include<stdio.h>
struct book {
    char bookname[100];
    int bookid;
    float price;
    char publisher[100];
    

};
struct library{
    int libcode;
    char librarianname[100];
    struct book b[30];
}l;

void main (){
    printf("Enter the Lib code:");
        scanf("%d",&l.libcode);
        printf("Enter the Librarian name: ");
    scanf(" %[^\n]s", l.librarianname);
    for (int i=0;i<30;i++){
        printf("Enter Book Name:");
        scanf("%[^\n]s",l.b[i].bookname);
        printf("Enter the id of the Book:");
        scanf("%d",&l.b[i].bookid);
        printf("\nEnter the price of the Book:");
        scanf("%f",&l.b[i].price);
        printf("Enter the Publisher Name:");
        scanf("%[^\n]s",l.b[i].publisher);

    }
    printf("  BOOKid\tName\tPrice\tPublisherName\tLibcode\tLibrarianName\n");
    
    for(int i=0;i<30;i++){
        
        printf("%d %d\t%s\t%f\t%s\t%d\t%s",i,l.b[i].bookid,l.b[i].bookname,l.b[i].price,l.b[i].publisher,l.libcode,l.librarianname);
    }
}