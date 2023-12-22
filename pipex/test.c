#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char command[1000];

    // Kullanıcıdan metin girişi al
    printf("Bir Bash komutu girin: ");
    fgets(command, sizeof(command), stdin);

    // Satır sonu karakterini kaldır
    size_t length = strlen(command);
    if (length > 0 && command[length - 1] == '\n') {
        command[length - 1] = '\0';
    }

    // Kullanıcının girdiği metni Bash olarak çalıştır
    int result = system(command);

    if (result == -1) {
        perror("system");
        return 1;
    }

    return 0;
}
