#version 330

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float specPow;
}; 

struct DirectionalLight {
    vec3 direction;
    vec3 diffuse;
    vec3 specular;
};

in vec2 texture0;
in vec3 normal0;
in vec3 position0;

out vec4 fragColor;

uniform vec3 viewPos;
uniform Material material;
uniform DirectionalLight light;

void main() {

	vec3 normal = normalize(normal0);
	vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(normal, lightDir), 0.0);
	vec3 reflectDir = reflect(-lightDir, normal);

    float spec = pow(max(dot(normalize(viewPos - position0), reflectDir), 0.0), material.specPow);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texture0));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, texture0));
    
	fragColor = vec4(diffuse + specular, 1);
}