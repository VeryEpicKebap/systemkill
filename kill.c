#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    const char *path = "/sys/power/state";
    FILE *f;
    if (access(path, W_OK) != 0) {
        perror("cannot access /sys/power/state");
        return 1;
    }
    sync();
    f = fopen(path, "w");
    if (!f) {
        perror("fopen");
        return 1;
    }
    if (fprintf(f, "mem\n") < 0) {
        perror("fprintf");
        fclose(f);
        return 1;
    }
    fclose(f);
    return 0;
}
