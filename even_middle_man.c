/* *************************************************** *
 * even_middle_man.c:                                   *
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

#define MSG_key_01   8265  // message queue key from sender
#define MSG_key_03   9265  // message queue key for even receiver

#define BUFFER_SIZE   256  // max. message size

struct message {
    long mtype;
    char mtext[BUFFER_SIZE];
};

int main(void) {
    int msqid_01, msqid_03;
    key_t msgkey_01 = MSG_key_01;
    key_t msgkey_03 = MSG_key_03;

    struct message buf;

    // Create the message queue for the receiver
    msqid_03 = msgget(msgkey_03, 0666 | IPC_CREAT);
    if (msqid_03 < 0) {
        perror("Error creating message queue for receiver");
        return 1;
    }

    // Get the message queue ID from the sender
    msqid_01 = msgget(msgkey_01, 0666);
    if (msqid_01 < 0) {
        perror("Error accessing sender's message queue");
        return 1;
    }

    // Receive messages from the sender
    for (int i = 0; i < 100; i++) {
        if (msgrcv(msqid_01, &buf, sizeof(buf.mtext), 0, 0) < 0) {
            perror("Error receiving message");
            break;
        }

        unsigned char num = (unsigned char)buf.mtext[0];
        if (i % 2 == 1) {  // Process only even-indexed messages (2nd, 4th, ...)
            // Send the even number to the receiver
            buf.mtype = 1; // Set message type
            buf.mtext[0] = num; // Send the even number
            msgsnd(msqid_03, &buf, sizeof(buf.mtext), 0);
        }
    }

    // Clean up: delete the message queue
    msgctl(msqid_03, IPC_RMID, NULL);
    return 0;
}
