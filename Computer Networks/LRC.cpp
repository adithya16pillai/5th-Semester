#include <stdio.h>
#include <string.h>

#define PACKET_SIZE 8

void convertToFormat(const char *binaryInput, char *formattedOutput) {
    int len = strlen(binaryInput);
    int numPackets = len / PACKET_SIZE;
    int remainder = len % PACKET_SIZE;
    int i, j;
    for (i = 0, j = 0; i < numPackets; i++, j += PACKET_SIZE) {
        strncpy(&formattedOutput[j], &binaryInput[j], PACKET_SIZE);
        formattedOutput[j + PACKET_SIZE] = ' ';
    }
    if (remainder > 0) {
        strncpy(&formattedOutput[j], &binaryInput[j], remainder);
        for (i = remainder; i < PACKET_SIZE; i++) {
            formattedOutput[j + i] = '0';
        }
        formattedOutput[j + PACKET_SIZE] = ' ';
    }
    formattedOutput[j + PACKET_SIZE + 1] = '\0';
}

int isBurstErrorDetected(const char *formattedOutput) {
    int numPackets = strlen(formattedOutput) / (PACKET_SIZE + 1);
    int i, j;
    for (i = 0, j = 0; i < numPackets; i++, j += PACKET_SIZE + 1) {
        int k;
        for (k = 0; k < PACKET_SIZE; k++) {
            if (formattedOutput[j + k] != '1') {
                return 1; 
            }
        }
    }
    return 0; 
}

int main() {
    char binaryInput[] = "1100111101110101110010101001";
    char formattedOutput[100];
    convertToFormat(binaryInput, formattedOutput);
    printf("Formatted output: %s\n", formattedOutput);
    if (isBurstErrorDetected(formattedOutput)) {
        printf("Burst error detected!\n");
    } else {
        printf("No burst error detected.\n");
    }
    return 0;
}
