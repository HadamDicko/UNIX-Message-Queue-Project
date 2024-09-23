/* *************************************************** *
 * odd_middle_man.c:                                   *
 * hdicko@siue.edu Hadam Dicko                         *
 * September 3, 2024                                   *
 *                                                     *
 * *************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MSG_key_02   8765  // message queue key from sender
#define MSG_key_04   9565  // message queue key for odd receiver

#define BUFFER_SIZE   256  // max. message size

struct message {
    long mtype;
    char mtext[BUFFER_SIZE];
};

int main(void) {
    int msqid_02, msqid_04;
    key_t msgkey_02 = MSG_key_02;
    key_t msgkey_04 = MSG_key_04;

    struct message buf;

    // Create the message queue for the receiver
    msqid_04 = msgget(msgkey_04, 0666 | IPC_CREAT);
    if (msqid_04 < 0) {
        perror("Error creating message queue for receiver");
        return 1;
    }

    // Get the message queue ID from the sender
    msqid_02 = msgget(msgkey_02, 0666);
    if (msqid_02 < 0) {
        perror("Error accessing sender's message queue");
        return 1;
    }

    // Receive messages from the sender
    for (int i = 0; i < 100; i++) {
        if (msgrcv(msqid_02, &buf, sizeof(buf.mtext), 0, 0) < 0) {
            perror("Error receiving message");
            break;
        }

        unsigned char num = (unsigned char)buf.mtext[0];
        if (i % 2 == 0) {  // Process only odd-indexed messages (1st, 3rd, ...)
            // Send the odd number to the receiver
            buf.mtype = 1; // Set message type
            buf.mtext[0] = num; // Send the odd number
            msgsnd(msqid_04, &buf, sizeof(buf.mtext), 0);
        }
    }

    // Clean up: delete the message queue
    msgctl(msqid_04, IPC_RMID, NULL);
    return 0;
}
