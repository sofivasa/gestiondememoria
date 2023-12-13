#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define SIZE 4096

int main() {
    // Creamos funcion para memoria compartida con mmap
    char *shared_memory = (char *)mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    //
    if (shared_memory == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);

    }
    pid_t pid = fork();
    if (pid == 0) {
        // Proceso hijo
        printf("Proceso hijo escribiendo en memoria compartida\n");
        strcpy(shared_memory, "Hola, soy el proceso hijo");
        exit(EXIT_SUCCESS);

    }
