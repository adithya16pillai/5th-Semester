#include <stdio.h>

unsigned short calculateChecksum(const int *data, int length) {
    unsigned int sum = 0;
    int i;
    for (i = 0; i < length; i++) {
        sum += data[i];
    }
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }
    return (unsigned short)(~sum);
}

int main() {
    int data[10];
    printf("Enter data: ");
    scanf("%d", &data);
    int length = sizeof(data) - 1;
    unsigned short checksum = calculateChecksum(data, length);
    printf("Checksum: 0x%04X\n", checksum);
    return 0;
}
