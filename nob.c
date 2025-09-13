#include <string.h>
#define NOB_IMPLEMENTATION
#include "nob.h"

#define BUILD_FOLDER ".build/"
#define SRC_FOLDER "src/"
#define MUST(X) do { if (!X) return false; } while (0)

bool step_build();
bool step_run();
bool help(int argc, char **argv);

bool run(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF_PLUS(argc, argv, "nob.h");

    if (argc < 2) {
        return step_build() && step_run();
    }

    if (strcmp(argv[1], "build") == 0) {
        return step_build();
    }

    return help(argc, argv);
}

bool step_build() {
    nob_log(NOB_INFO, "  BUILD STAGE");

    MUST(nob_mkdir_if_not_exists(BUILD_FOLDER));
    MUST(nob_write_entire_file(BUILD_FOLDER".gitignore", "*", 1));

    Nob_Cmd cmd = {0};
    nob_cc(&cmd);
    nob_cc_flags(&cmd);
    nob_cc_inputs(&cmd, "main.c", SRC_FOLDER"list.c");
    nob_cc_output(&cmd, "main.o");

    MUST(nob_cmd_run(&cmd));

    return true;
}

bool step_run() {
    nob_log(NOB_INFO, "  RUN STAGE");

    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, "./main.o");
    MUST(nob_cmd_run(&cmd));

    return true;
}

bool help(int argc, char **argv) {
    printf("Usage: %s [COMMAND]\n", argv[0]);
    printf("Commands:\n");
    printf("  build: build\n");
    printf("  <none>: build and run\n");
    return false;
}

int main(int argc, char **argv) {
    return !run(argc, argv);
}
