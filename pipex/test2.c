#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    // Yeni bir süreç oluştur
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Çocuk süreç içindeyiz
        char *ls = "/path/to/your/executable";  // Başlatılacak programın dosya yolu

        char *const args[] = {ls, NULL};  // Program argümanları

        // Yeni programı başlat
        if (execve(ls, args, NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        // Ebeveyn süreç içindeyiz
        int status;
        waitpid(child_pid, &status, 0);  // Çocuk sürecin bitmesini bekleyelim

        if (WIFEXITED(status)) {
            printf("Çocuk süreç normal olarak sonlandı, çıkış kodu: %d\n", WEXITSTATUS(status));
        } else {
            printf("Çocuk süreç beklenmeyen bir şekilde sonlandı.\n");
        }
    }

    return 0;
}
