#include <stdio.h>

void main() {
    int seconds, minutes, hours;

    printf("Enter time in seconds:\n ");
    scanf("%d", &seconds);

    hours = seconds / 3600;
    seconds = seconds%3600;
    minutes = seconds / 60;
    seconds = seconds % 60;

    printf("%d::%d::%d\n", hours, minutes, seconds);


}
