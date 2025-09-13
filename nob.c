#define NOB_IMPLEMENTATION

#include "nob.h"

#define BUILD_FOLDER ".build/"

#define MUST(X) if (!X) return false;

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF_PLUS(argc, argv, "nob.h");

    if (!nob_mkdir_if_not_exists(BUILD_FOLDER)) return 1;
    if (!nob_write_entire_file(BUILD_FOLDER".gitignore", "*", 1)) return 1;

    Nob_Cmd cmd = {0};
    nob_cc(&cmd);
    nob_cc_flags(&cmd);
    nob_cc_inputs(&cmd, "main.c");
    nob_cc_output(&cmd, "main.o");

    if (!nob_cmd_run(&cmd)) return 1;

    return 0;
}
