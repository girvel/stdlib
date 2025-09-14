#include <assert.h>
#include <string.h>
#define NOB_IMPLEMENTATION
#include "nob.h"

#define MUST(X) do { if (!X) return false; } while (0)

#define BUILD_FOLDER ".build/"
#define SRC_FOLDER "src/"

#define OUTFILE BUILD_FOLDER"stdlib.so"
#define SOURCES_N 3
#define SOURCES SRC_FOLDER"test.c", SRC_FOLDER"string.c", SRC_FOLDER"list.c"
const char *sources[SOURCES_N] = {SOURCES};

#define TEST_OUTFILE BUILD_FOLDER"test.out"
#define TEST_SOURCES_N SOURCES_N + 1
#define TEST_ENTRYPOINT "test.c"
const char *test_sources[TEST_SOURCES_N] = {SOURCES, TEST_ENTRYPOINT};

// NEXT CLI:
// NEXT /include for headers

bool help(int argc, char **argv) {
    printf("%s build <src...> <outfile>  builds the given source files\n", argv[0]);
    printf("%s build                     builds sources & links them into a library\n", argv[0]);
    printf("%s test                      builds sources & tests, runs the tests\n", argv[0]);
    printf("--safe                       enables runtime bounds checking\n");
    return false;
}

bool prep();
bool build(size_t, const char **, bool);
bool link_(size_t, const char **, const char *, bool);
bool run_tests();

bool run(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF_PLUS(argc, argv, "nob.h");

    bool safe = strcmp(argv[argc - 1], "--safe") == 0;
    if (safe) {
        argc--;
    }

    if (argc > 3 && strcmp(argv[1], "build") == 0) {
        MUST(prep());
        MUST(build(argc - 3, (const char **)argv + 2, safe));
        MUST(link_(argc - 3, (const char **)argv + 2, argv[argc - 1], false));
        return true;
    }

    if (argc == 2 && strcmp(argv[1], "build") == 0) {
        return prep()
            && build(SOURCES_N, sources, safe)
            && link_(SOURCES_N, sources, OUTFILE, false);
    }

    if (argc == 2 && strcmp(argv[1], "test") == 0) {
        MUST(prep());
        MUST(build(TEST_SOURCES_N, test_sources, safe));
        MUST(link_(TEST_SOURCES_N, test_sources, TEST_OUTFILE, true));
        MUST(run_tests());
        return true;
    }

    return help(argc, argv);
}

Nob_String_Builder src_to_obj(const char *src_path) {
    Nob_String_Builder str = {0};
    nob_sb_append_cstr(&str, BUILD_FOLDER);
    nob_sb_append_cstr(&str, src_path);
    assert(str.items[str.count - 2] == '.');
    assert(str.items[str.count - 1] == 'c');
    str.items[str.count - 1] = 'o';
    nob_sb_append_null(&str);
    return str;
}

bool prep() {
    return nob_mkdir_if_not_exists(BUILD_FOLDER)
        && nob_mkdir_if_not_exists(BUILD_FOLDER SRC_FOLDER)
        && nob_write_entire_file(BUILD_FOLDER".gitignore", "*", 1);
}

bool build(size_t sources_n, const char **source_paths, bool safe) {
    Nob_Cmd cmd = {0};
    for (size_t i = 0; i < sources_n; ++i) {
        nob_cc(&cmd);
        nob_cc_flags(&cmd);
        nob_cmd_append(&cmd, "-c");
        nob_cmd_append(&cmd, "-fPIC");
        nob_cc_inputs(&cmd, source_paths[i]);

        Nob_String_Builder output_path = src_to_obj(source_paths[i]);
        nob_cc_output(&cmd, output_path.items);

        bool result = nob_cmd_run(&cmd);
        nob_sb_free(output_path);
        if (!result) return false;
    }
    return true;
}

bool link_(size_t sources_n, const char **sources, const char *outfile, bool is_exe) {
    Nob_Cmd cmd = {0};
    nob_cc(&cmd);
    Nob_String_Builder *object_files = calloc(sources_n, sizeof(Nob_String_Builder));
    for (size_t i = 0; i < sources_n; ++i) {
        object_files[i] = src_to_obj(sources[i]);
        nob_cmd_append(&cmd, object_files[i].items);
    }
    if (!is_exe) nob_cmd_append(&cmd, "-shared");
    nob_cc_output(&cmd, outfile);

    bool result = nob_cmd_run(&cmd);

    for (size_t i = 0; i < sources_n; ++i) {
        nob_sb_free(object_files[i]);
    }
    free(object_files);

    return result;
}

bool run_tests() {
    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, "./"TEST_OUTFILE);
    return nob_cmd_run(&cmd);
}

int main(int argc, char **argv) {
    return !run(argc, argv);
}
