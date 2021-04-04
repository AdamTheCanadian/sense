#ifndef __ATC_VIS_SHADER_H
#define __ATC_VIS_SHADER_H

#include <glad/glad.h>

#include <string>
#include <sstream>
#include <iostream>

namespace vis {
class Shader {
public:
  // constructor generates the shader on the fly
  // ------------------------------------------------------------------------
  Shader(const char* vertexSrc, const char* fragmentSrc) {
     
    unsigned int vertex, fragment;
    // vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexSrc, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");
    // fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentSrc, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");
    // shader Program
    id_ = glCreateProgram();
    glAttachShader(id_, vertex);
    glAttachShader(id_, fragment);
    glLinkProgram(id_);
    checkCompileErrors(id_, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
  }

  // activate the shader
  void use() {
    glUseProgram(id_);
  }

  // utility uniform functions
  void setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(id_, name.c_str()), (int)value);
  }
  
  void setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
  }

  void setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
  }

private:

  unsigned int id_;
  // utility function for checking shader compilation/linking errors.
  void checkCompileErrors(unsigned int shader, std::string type) {
    int success;
    char infoLog[1024];
    if (type != "PROGRAM") {
      glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
      if (!success) {
        glGetShaderInfoLog(shader, 1024, NULL, infoLog);
        std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n";
      }
    }
    else {
      glGetProgramiv(shader, GL_LINK_STATUS, &success);
      if (!success) {
        glGetProgramInfoLog(shader, 1024, NULL, infoLog);
        std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n";
      }
    }
  }
};
}
#endif