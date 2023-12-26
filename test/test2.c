#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t child_pid;

    // Pipe oluştur
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Çocuk işlemi oluştur
    if ((child_pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {  // Çocuk işlem
        // Pipe'ın çıkışını stdout'a yönlendir
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);

        // ls -l komutunu çağır
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {  // Ebeveyn işlem
        close(pipefd[1]);  // Çocuk işlemin yazma tarafını kapat

        // Pipe'ın girişini stdin'a yönlendir
        dup2(pipefd[0], STDIN_FILENO);

        // grep 48 komutunu çağır
        execlp("grep", "grep", "48", (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}
