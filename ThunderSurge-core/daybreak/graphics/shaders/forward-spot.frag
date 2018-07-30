#version 450

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float specPow;
}; 

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;
  
    float constant;
    float linear;
    float quadratic;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;       
};

in vec2 texture0;
in vec3 normal0;
in vec3 position0;

out vec4 fragColor;

uniform vec3 viewPos;
uniform Material material;
uniform SpotLight light;

void main() {

	vec3 normal = normalize(normal0);
    vec3 viewDir = normalize(viewPos - position0);
	vec3 lightDir = normalize(light.position - position0);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.specPow);
    float distance = length(light.position - position0);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texture0));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, texture0));
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    fragColor = vec4(diffuse + specular, 1);
}