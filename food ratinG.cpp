#include <stdio.h>
#include <string.h>

struct Hotel {
    char name[50];
    char location[50];
    float rating;
};
void addHotel(struct Hotel hotels[], int *count) {
    if (*count < 50) {
        printf("Enter hotel name: ");
        scanf("%s", &hotels[*count].name);

        printf("Enter location: \n");
        scanf("%s", &hotels[*count].location);
        getchar(); 

        printf("Enter rating out of 5: ");
        scanf("%f", hotels[*count].rating);

        if (hotels[*count].rating < 1 || hotels[*count].rating > 5) {
            printf("Invalid rating. Please enter a rating between 1 and 5.\n");

            addHotel(hotels, count);
        } else {
            printf("Hotel added successfully!\n");
            (*count)++;
        }
    } else {
        printf("Maximum number of hotels reached.\n");
    }
}
 

void searchRating(const struct Hotel hotels[], int count, float ratingToFind) {
    int found = 0;

    printf("Hotels with rating %.2f:\n", ratingToFind);
    for (int i = 0; i < count; i++) {
        if (hotels[i].rating == ratingToFind) {
            printf("-Hotelname:  %s\n,Location: %s\n, Rating: %.2f\n", hotels[i].name, hotels[i].location, hotels[i].rating);
            found = 1;
        }
    }

    if (!found) {
        printf("No hotels found with the specified rating.\n");
    }
}

void searchByName(const struct Hotel hotels[], int count, const char *hotelName) {
    int found = 0;

    printf("Search Results for '%s':\n", hotelName);
    for (int i = 0; i < count; i++) {
        if (strcmp(hotels[i].name, hotelName) == 0) {
            printf("-Hotel name: %s\n, Location: %s\n, Rating: %.2f\n", hotels[i].name, hotels[i].location, hotels[i].rating);
            found = 1;
        }
    }

    if (!found) {
        printf("No hotels found with the name '%s'.\n", hotelName);
    }
}

void searchByLocation(const struct Hotel hotels[], int count, const char *location) {
    int found = 0;

    printf("Hotels in %s:\n", location);
    for (int i = 0; i < count; i++) {
        if (strcmp(hotels[i].location, location) == 0) {
             printf("-Hotelname:  %s\n,Location: %s\n, Rating: %.2f\n", hotels[i].name, hotels[i].location, hotels[i].rating);
            found = 1;
        }
    }

    if (!found) {
        printf("No hotels found in %s.\n", location);
    }
}

int main() {
    struct Hotel hotels[50];  
    int hotelCount = 0;       
    float ratingToFind;       
    char hotelName[50];       
    char location[50];       
    int choice;

    do {
        printf("\n-  -  -  FOOD RATING APPLICATION   -  -  -\n");
        printf("1. Add Hotel\n");
        printf("2. Search by Rating\n");
        printf("3. Search by Hotel Name\n");
        printf("4. Search by Location\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addHotel(hotels, &hotelCount);
                break;

            case 2:
                printf("Enter rating to search: \n");
                scanf("%f", &ratingToFind);
                searchRating(hotels, hotelCount, ratingToFind);
                break;

            case 3:
                printf("Enter hotel name to search: \n");
                scanf("%s", hotelName);
                searchByName(hotels, hotelCount, hotelName);
                break;

            case 4:
                printf("Enter location to search: \n");
                scanf("%s", location);
                searchByLocation(hotels, hotelCount, location);
                break;

            case 5:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

