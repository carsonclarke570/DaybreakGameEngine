#version 450

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float specPow;
}; 

struct BaseLight {
	vec3 ambient;
	vec3 diffuse;
    vec3 specular;
};

struct DirectionalLight {
    vec3 direction;
    BaseLight light;
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
	vec3 diffuse = light.light.diffuse * diff * vec3(texture(material.diffuse, texture0));
	vec3 specular = light.light.specular * spec * vec3(texture(material.specular, texture0));
    vec3 ambient  = light.light.ambient  * vec3(texture(material.diffuse, texture0));

	fragColor = vec4(ambient + diffuse + specular, 1);
}
