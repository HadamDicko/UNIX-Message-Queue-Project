/* *************************************************** *
 * odd_middle_man.c:                                   *
 *                                                     *
 * September 3, 2024                                   *
 *                                                     *
 * *************************************************** */

// even_middle_man.c
#include <stdio.h>          // for printf
#include <stdlib.h>         // for exit
#include <sys/types.h>      // for message queue
#include <sys/ipc.h>        // for message queue
#include <sys/msg.h>        // for message queue
#include <unistd.h>         // for sleep

#define MSG_key_02 8911     // Message queue key for even-indexed messages
#define BUFFER_SIZE 256      // Max message size

struct message {
    long mtype;              // Message type
    char mtext[BUFFER_SIZE]; // Message text
};

int main(void) {
    int msqid;               // Message queue ID
    struct message buf;      // Message buffer

    // Get the message queue
    msqid = msgget(MSG_key_02, 0666 | IPC_CREAT);
    if (msqid < 0) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Even Middle Man started. Waiting for messages...\n");

    // Receive messages
    for (int i = 0; i < 50; i++) {  // Expecting 50 messages
        if (msgrcv(msqid, (struct msgbuf *)&buf, sizeof(buf.mtext), 1, 0) < 0) {
            perror("msgrcv");
            break;
        }
        unsigned char received_number = buf.mtext[0];
        printf("Received from even index %d: %d\n", i * 2, received_number);
    }

    // Cleanup
    msgctl(msqid, IPC_RMID, NULL);
    printf("Even Middle Man finished.\n");
    return 0;
}
