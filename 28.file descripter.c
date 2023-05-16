#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 100

int main() {
    char filename[100];
    char data[MAX_SIZE];
    int fileDescriptor, bytesRead;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for writing
    fileDescriptor = open(filename, O_CREAT | O_WRONLY, 0644);

    // Check if file was opened successfully
    if (fileDescriptor == -1) {
        perror("Error creating file");
        return 1;
    }

    // Get data from the user
    printf("Enter data: ");
    scanf(" %[^\n]s", data);

    // Write data to the file
    write(fileDescriptor, data, strlen(data));

    // Close the file
    close(fileDescriptor);

    // Open the file for reading
    fileDescriptor = open(filename, O_RDONLY);

    // Check if file was opened successfully
    if (fileDescriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read data from the file
    bytesRead = read(fileDescriptor, data, sizeof(data));

    // Check if reading was successful
    if (bytesRead == -1) {
        perror("Error reading file");
        return 1;
    }

    // Null-terminate the data read from the file
    data[bytesRead] = '\0';

    // Print the data read from the file
    printf("Data read from the file:\n%s\n", data);

    // Close the file
    close(fileDescriptor);

    return 0;
}

