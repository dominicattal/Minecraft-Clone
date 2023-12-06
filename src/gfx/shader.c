#include "shader.h"

static const char* _read_file(char* path)
{
    FILE* ptr;
    char* content = malloc(sizeof(char) * 100);
    ptr = fopen(path, "r");
    fgets(content, 100, ptr);
    printf(content);
    return content;
}

static unsigned int _compile(char* s_path, GLenum type)
{
    unsigned int shader;
    const char* shader_code;
    shader = glCreateShader(type);
    shader_code = _read_file(s_path);
    glShaderSource(shader, 1, &shader_code, NULL);
    glCompileShader(shader);
    return shader;
}

Shader shader_init(char* vs_path, char* fs_path)
{
    Shader self;
    unsigned int vertex, fragment;
    vertex   = _compile(vs_path, GL_VERTEX_SHADER);
    fragment = _compile(fs_path, GL_FRAGMENT_SHADER);
    self.ID = glCreateProgram();
    glAttachShader(self.ID, vertex);
    glAttachShader(self.ID, fragment);
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    return self;
}