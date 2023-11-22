#include "obj_parser.h"

#define WHITESPACE " \t\n\r"

struct ObjVector* obj_parser_obj_parse_vector() {
    struct ObjVector* vector = (struct ObjVector*)malloc(sizeof(struct ObjVector));
    vector->e[0] = atof(strtok(NULL, WHITESPACE));
    vector->e[1] = atof(strtok(NULL, WHITESPACE));
    vector->e[2] = atof(strtok(NULL, WHITESPACE));
    return vector;
}

int obj_parser_parse_obj_file(struct ObjGrowableSceneData* growable_data, char* path) {
    FILE* file;
    int current_material = -1;
    char* current_token = NULL;
    char current_line[OBJ_LINE_MAX_SIZE];
    int line_number = 0;

    file = fopen(path, "r");
    if (file == 0) {
        LOG_ERROR("Error tyring to parse OBJ file not found at path: %s", path);
        return 1;
    }

    while(fgets(current_line, OBJ_LINE_MAX_SIZE, file)) {
        current_token = strtok(current_line, " \t\n\r");
        line_number++;

        if (current_token == NULL || current_token[0] == "#") {
            continue;
        }

        if (strcmp(current_token, "v")) {
            list_add_item(&growable_data->vertex_list, obj_parser_obj_parse_vector());
            continue;
        }

        if (strcmp(current_token, "vn")) {
            continue;
        }

        if (strcmp(current_token, "vt")) {
            continue;
        }

        if (strcmp(current_token, "f")) {
            continue;
        }
    }
}

int obj_parser_parse_scene(struct ObjSceneData *out, char *path) {
    struct ObjGrowableSceneData growable_data;

    list_create(&growable_data.vertex_list, 10, 1);
    list_create(&growable_data.vertex_normal_list, 10, 1);
    list_create(&growable_data.vertex_texture_list, 10, 1);
    list_create(&growable_data.material_list, 10, 1);

    obj_parser_parse_obj_file(&growable_data, path);

    return 0;
} 