/*will search through the file to replace the word entered by the user
* Author : Pruthviraj 165490
* created : 3 October 2024
*/

/**REQUIRED HEADER FILES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**FUNCTION PROTOTYPES*/
void replaceWordInFile(const char *filePath, const char *oldWord, const char *newWord);
int main() {
    char *oldWord, *newWord;
    int oldWordLen, newWordLen;
    const char *filePath = "demofile.txt";

    // Prompt user for the old word and dynamically allocate memory
    oldWord = (char *)malloc(100 * sizeof(char));  // Allocating initial memory
    printf("Which word do you want to replace: ");
    scanf("%s", oldWord);                          // Taking input
    oldWordLen = strlen(oldWord);                  // Calculate length
    oldWord = (char *)realloc(oldWord, (oldWordLen + 1) * sizeof(char)); // Adjust memory to fit the input

    // Prompt user for the new word and dynamically allocate memory
    newWord = (char *)malloc(100 * sizeof(char));  // Allocating initial memory
    printf("What word do you want to replace it with: ");
    scanf("%s", newWord);                          // Taking input
    newWordLen = strlen(newWord);                  // Calculate length
    newWord = (char *)realloc(newWord, (newWordLen + 1) * sizeof(char)); // Adjust memory to fit the input

    // Call the function to replace words in the file
    replaceWordInFile(filePath, oldWord, newWord);

    // Free the dynamically allocated memory
    free(oldWord);
    free(newWord);

    return 0;
}/*End main()*/

void replaceWordInFile(const char *filePath, const char *oldWord, const char *newWord) {
    FILE *file, *tempFile;
    char *buffer;
    long fileSize;
    int i, j, k;
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);

    // Open the original file in read mode
    file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Seek to the end of the file to get the file size
    fseek(file, 0, SEEK_END);  // Move file pointer to the end of the file
    fileSize = ftell(file);    // Get the file size in bytes
    rewind(file);              // Move file pointer back to the beginning

    // Dynamically allocate memory for the buffer based on file size
    buffer = (char *)malloc((fileSize + 1) * sizeof(char));  // +1 for null terminator
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return;
    }

    // Read the entire file into the buffer
    fread(buffer, sizeof(char), fileSize, file);
    buffer[fileSize] = '\0';  // Null terminate the buffer

    // Close the file as we now have the content in the buffer
    fclose(file);

    // Open a temporary file for writing the modified content
    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening temp file.\n");
        free(buffer);
        return;
    }

    // Process the buffer to replace occurrences of oldWord with newWord
    char temp[1024] = "";  // Temporary buffer to hold the modified line
    i = 0;                 // Index for reading the buffer
    k = 0;                 // Index for writing to the temp buffer

    // Iterate through each character in the buffer
    while (buffer[i] != '\0') {
        // Check if the current sequence matches oldWord
        int match = 1;
        for (j = 0; j < oldWordLen; j++) {
            if (buffer[i + j] != oldWord[j]) {
                match = 0;
                break;
            }
        }

        // If the word matches, append newWord to temp buffer
        if (match) {
            for (j = 0; j < newWordLen; j++) {
                temp[k++] = newWord[j];
            }
            i += oldWordLen;  // Move index past the old word
        } else {
            // If no match, copy the current character
            temp[k++] = buffer[i++];
        }
    }

    // Add null terminator to the temp buffer
    temp[k] = '\0';

    // Write the modified content to the temporary file
    fputs(temp, tempFile);

    // Close the temporary file
    fclose(tempFile);

    // Replace the original file with the modified temporary file
    remove(filePath);
    rename("temp.txt", filePath);

    printf("Replacement successful!\n");

    // Free the dynamically allocated buffer
    free(buffer);
}/*End replaceWordInFile()*/


