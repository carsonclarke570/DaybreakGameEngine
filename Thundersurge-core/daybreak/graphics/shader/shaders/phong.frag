#version 330

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

struct DirLight {
    vec3 direction;
	BaseLight light;
};

in vec2 texCoord0;
in vec3 normal0;
in vec3 worldPos0;

out vec4 fragColor;

uniform vec3 viewPos;
uniform Material material;
uniform DirLight dirLight;

vec3 calcDirLight(DirLight light, vec3 normal, vec3 viewDir);

void main() {
	vec3 norm = normalize(normal0);
	vec3 view = normalize(viewPos - worldPos0);

	vec3 light = calcDirLight(dirLight, norm, view);

	fragColor = vec4(light, 1.0);
}

vec3 calcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.specPow);
    vec3 ambient = light.light.ambient * vec3(texture(material.diffuse, texCoord0));
    vec3 diffuse = light.light.diffuse * diff * vec3(texture(material.diffuse, texCoord0));
    vec3 specular = light.light.specular * spec * vec3(texture(material.specular, texCoord0));
    return (ambient + diffuse + specular);
}