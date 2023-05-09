#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 20

struct file {
    char name[MAX_NAME_LENGTH];
};

struct directory {
    struct file files[MAX_FILES];
    int num_files;
};

int main() {
	int i;
    struct directory cse_directory = {0};
    char filename[MAX_NAME_LENGTH];

    // Create directory
    printf("Creating directory CSE...\n");

    // Add files to directory
    printf("Adding files to directory...\n");
    printf("Enter filename A: ");
    scanf("%s", filename);
    strcpy(cse_directory.files[0].name, filename);
    cse_directory.num_files++;
    printf("Enter filename B: ");
    scanf("%s", filename);
    strcpy(cse_directory.files[1].name, filename);
    cse_directory.num_files++;
    printf("Enter filename C: ");
    scanf("%s", filename);
    strcpy(cse_directory.files[2].name, filename);
    cse_directory.num_files++;

    // Display contents of directory
    printf("Contents of directory CSE:\n");
    for (i = 0; i < cse_directory.num_files; i++) {
        printf("%s\n", cse_directory.files[i].name);
    }

    return 0;
}
