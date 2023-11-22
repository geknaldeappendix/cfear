#ifndef __REPOS_CFEAR_CENGINE_GRAPHICS_OBJ_OBJ_PARSER_H_
#define __REPOS_CFEAR_CENGINE_GRAPHICS_OBJ_OBJ_PARSER_H_

#include <stdio.h>
#include <string.h> 
#include "clib/list.h"
#include "clib/logger.h"

#define FILENAME_MAX_LENGTH 500
#define MATERIAL_NAME_MAX_SIZE 255
#define OBJ_LINE_MAX_SIZE 500
#define MAX_VERTEX_COUNT 4

struct ObjVector {
	double e[3];
};

struct ObjGrowableSceneData {
    char scene_filename[FILENAME_MAX_LENGTH];
    char material[FILENAME_MAX_LENGTH];

    struct List vertex_list, vertex_normal_list, vertex_texture_list;
    struct List material_list;
};

struct ObjSceneData {

};

int obj_parser_parse_scene(struct ObjSceneData* out, char* path);

#endif // __REPOS_CFEAR_CENGINE_GRAPHICS_OBJ_OBJ_PARSER_H_