#include "shader.h"

unsigned int compile_shader_from_path(char* path, GLenum type) {
    FILE* file;
    char* source;
    long length;

    file = fopen(path, "rb");
    if (!file) {
        LOG_ERROR("Could not open shader file at path: %s", path);
        return 0;
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    source = calloc(1, length); 
    fread(source, 1, length, file);
    fclose(file);

    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, (const char* const*)&source, NULL);
    glCompileShader(shader);
    
    free(source);

    int success;
    char info_log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        LOG_ERROR("Shader compilation failed ShaderInfoLog: %s", info_log);
        return 0;
    }

    return shader;
}

struct Shader shader_create(char* vertex_shader_path, char* fragment_shader_path) {
    struct Shader shader;
    shader.linked = 0;
    
    int vertex_shader = compile_shader_from_path(vertex_shader_path, GL_VERTEX_SHADER);
    if (!vertex_shader) {
        return shader;
    }
    int fragment_shader = compile_shader_from_path(fragment_shader_path, GL_FRAGMENT_SHADER);
    if (!fragment_shader) {
        return shader;
    }

    shader.program = glCreateProgram();
    glAttachShader(shader.program, vertex_shader);
    glAttachShader(shader.program, fragment_shader);
    glLinkProgram(shader.program);

    int success;
    char info_log[512];
    glGetProgramiv(shader.program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader.program, 512, NULL, info_log);
        LOG_ERROR("Shader program link failed ProgramInfoLog: %s", info_log);
        return shader;
    }

    shader.linked = 1;

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return shader;
}

void shader_bind(struct Shader shader) {
    glUseProgram(shader.program);
}

void shader_destroy(struct Shader shader) {
    glDeleteProgram(shader.program);
}
