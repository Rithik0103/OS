#include <stdio.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES_PER_USER 3

struct UserDirectory {
    char name[20];
    char files[MAX_FILES_PER_USER][20];
    int num_files;
};

struct UserDirectory users[MAX_USERS];

int main() {
	int i,j;
    // initialize user directories
    for (i = 0; i < MAX_USERS; i++) {
        sprintf(users[i].name, "user%d", i+1);
        users[i].num_files = 0;
    }

    // create files for user1
    strcpy(users[0].files[0], "file1.txt");
    strcpy(users[0].files[1], "file2.txt");
    strcpy(users[0].files[2], "file3.txt");
    users[0].num_files = 3;

    // create files for user2
    strcpy(users[1].files[0], "file4.txt");
    strcpy(users[1].files[1], "file5.txt");
    users[1].num_files = 2;

    // create files for user3
    strcpy(users[2].files[0], "file6.txt");
    strcpy(users[2].files[1], "file7.txt");
    strcpy(users[2].files[2], "file8.txt");
    users[2].num_files = 3;

    // print user directories
    for (i = 0; i < MAX_USERS; i++) {
        printf("User Directory: %s\n", users[i].name);
        printf("Files:\n");
        for (j = 0; j < users[i].num_files; j++) {
            printf("- %s\n", users[i].files[j]);
        }
        printf("\n");
    }

    return 0;
}

