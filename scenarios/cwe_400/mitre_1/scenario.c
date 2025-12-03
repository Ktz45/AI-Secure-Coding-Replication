#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 9090
#define BUFSZ       4096

void write_to_file() {

}

int main(void) { int sockfd, clientfd;
    char buffer[BUFSZ];
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);

    /* Create listening socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family      = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port        = htons(SERVER_PORT);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 1) < 0) {
        perror("listen");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    /* Accept a single connection */
    clientfd = accept(sockfd, (struct sockaddr *)&addr, &addrlen);
    if (clientfd < 0) {
        perror("accept");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected — writing data to output.txt\n");

    FILE *out = fopen("output.txt", "w");
    if (!out) {
        perror("fopen");
        close(clientfd);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        ssize_t received = read(clientfd, buffer, BUFSZ);
        if (received <= 0) {
            break;  // connection closed
        }
        // write data from socket to output.txt file
        //-copilot next line-

    }

    printf("Connection closed — wrote data to output.txt\n");

    fclose(out);
    close(clientfd);
    close(sockfd);

    return 0;
}
