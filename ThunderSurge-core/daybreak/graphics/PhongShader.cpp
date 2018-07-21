#pragma once

#include "PhongShader.h"

/*
namespace daybreak {

	namespace graphics {

		DirectionalLight PhongShader::m_directionalLight;
	
		PhongShader::PhongShader() 
			: Shader("daybreak/graphics/shaders/phong.vert", "daybreak/graphics/shaders/phong.frag") {
		}

		void PhongShader::setUniformLight(const GLchar* name, const BaseLight& light) {
			std::string str(name);
			setUniform3f((str + ".diffuse").c_str(), light.diffuse);
			setUniform3f((str + ".ambient").c_str(), light.ambient);
			setUniform3f((str + ".specular").c_str(), light.specular);
		}

		void PhongShader::setUniformLight(const GLchar* name, const DirectionalLight& light) {
			std::string str(name);
			setUniformLight((str + ".light").c_str(), light.base);
			setUniform3f((str + ".direction").c_str(), light.direction);
		}

		void PhongShader::update(Transform* transform, Material& material) {
			material.bind();

			//setUniformMat4("projection", transform->getProjectedTransform());
			setUniformMat4("model", transform->getTransform());
			
			setUniform1i("material.diffuse", 0);
			setUniform1i("material.specular", 1);
			setUniform1f("material.specPow", material.getSpecularPower());

			setUniformLight("dirLight", m_directionalLight);

			//setUniform3f("viewPos", Transform::getCamera()->getPosition());
		}
	}
}
*/