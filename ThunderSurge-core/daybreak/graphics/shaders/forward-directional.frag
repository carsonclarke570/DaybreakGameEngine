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

in vec2 texcoord;
in vec3 normal;
in vec3 position;

out vec4 fragColor;

uniform vec3 viewPos;
uniform Material material;
uniform DirectionalLight light;

void main() {

	vec3 norm = normalize(normal);
	vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 reflectDir = reflect(-lightDir, norm);

	float spec = pow(max(dot(normalize(viewPos - position), reflectDir), 0.0), material.specPow);
	vec3 diffuse = light.light.diffuse * diff * vec3(texture(material.diffuse, texcoord));
	vec3 specular = light.light.specular * spec * vec3(texture(material.specular, texcoord));
    vec3 ambient  = light.light.ambient  * vec3(texture(material.diffuse, texcoord));

	fragColor = vec4(ambient + diffuse + specular, 1);
}
