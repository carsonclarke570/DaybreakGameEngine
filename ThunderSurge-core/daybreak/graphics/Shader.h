#ifndef _SHADER_H_
#define _SHADER_H_

#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "../core/Math.h"
#include "../core/Transform.h"
#include "../utils/fileutils.h"

#include "Material.h"

namespace daybreak {

	using namespace core;

	namespace graphics {

		/**
			The Shader class handles the compiling and running of shader programs.
			
			A Shader object consists of
			- A required Vertex Shader
			- A required Fragment Shader
			- An optional Geometry Shader

			If the shader is going to be used while rendering a Mesh, it is 
			recommended to use the DaySL language, otherwise use a self-defined 
			shader.

			Global Uniforms (Need to be defined, but can always be used)
			- view (mat4) : The view matrix
			- projection (mat4) : The projection matrix

			@author  Carson Clarke-Magrab
			@version 1.0
			@since   2018-11-03
		 */
		class Shader {
		private:
			GLuint m_shader;

			bool m_enableDaySL;

			void addVertexShader(const char* ver);
			void addFragmentShader(const char* frag);
			void addGeometryShader(const char* geo);
		public:
			Shader(const char* ver, const char* frag, const char* geom = NULL, const bool enableDaySL = true);
			~Shader();

			void setUniform1f(const GLchar* name, float f);
			void setUniform1i(const GLchar* name, int i);
			void setUniform2f(const GLchar* name, const vec2& v);
			void setUniform3f(const GLchar* name, const vec3& v);
			void setUniform4f(const GLchar* name, const vec4& v);
			void setUniformMat4(const GLchar* name, const mat4& m);

			void enable() const;
			void disable() const;
		};
	}
}

#endif