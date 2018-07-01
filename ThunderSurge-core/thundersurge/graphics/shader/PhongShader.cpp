#pragma once

#include "PhongShader.h"

namespace thundersurge {

	namespace graphics {

		vec3 PhongShader::m_ambience(0.03f, 0.03f, 0.03f);
		DirectionalLight PhongShader::m_directionalLight;
	
		PhongShader::PhongShader() 
			: Shader("thundersurge/graphics/shader/shaders/phong.vert", "thundersurge/graphics/shader/shaders/phong.frag") {
		}

		void PhongShader::setUniformLight(const GLchar* name, const BaseLight& light) {
			std::string str(name);
			setUniform3f((str + ".color").c_str(), light.color);
			setUniform1f((str + ".intensity").c_str(), light.intensity);
		}

		void PhongShader::setUniformLight(const GLchar* name, const DirectionalLight& light) {
			std::string str(name);
			setUniformLight((str + ".base").c_str(), light.base);
			setUniform3f((str + ".direction").c_str(), light.direction);
		}

		void PhongShader::update(const mat4& world, const mat4& projection, const Material& material) {
			material.getTexture().bind();

			setUniformMat4("transformProjected", projection);
			setUniformMat4("transform", world);
			setUniform3f("color", material.getColor());

			setUniform3f("ambient", m_ambience);
			setUniformLight("directionalLight", m_directionalLight);

			setUniform1f("specularIntensity", material.getSpecularIntensity());
			setUniform1f("specularPower", material.getSpecularPower());

			setUniform3f("eyePos", Transform::getCamera()->getPosition());
		}
	}
}