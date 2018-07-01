#version 330

in vec2 texCoord0;
in vec3 normal0;
in vec3 worldPos0;

out vec4 fragColor;

struct BaseLight {
    vec3 color;
    float intensity;
};

struct DirectionalLight {
    BaseLight base;
    vec3 direction;
};

uniform vec3 color;
uniform vec3 eyePos;
uniform vec3 ambient;
uniform sampler2D sampler;

uniform float specularIntensity;
uniform float specularPower;

uniform DirectionalLight directionalLight;

vec4 calcLight(BaseLight base, vec3 direction, vec3 normal) {
	float diffuseFactor = dot(normal, -direction);

	vec4 diffuseColor = vec4(0,0,0,0);
	vec4 specularColor = vec4(0,0,0,0);

	if (diffuseFactor > 0) {
		diffuseColor = vec4(base.color, 1.0) * base.intensity * diffuseFactor;

		vec3 dirToEye = normalize(eyePos - worldPos0);
		vec3 ref = normalize(reflect(direction, normal));

		float specularFactor = dot(dirToEye, ref);
		specularFactor = pow(specularFactor, specularPower);

		if (specularFactor > 0) {
			specularColor = vec4(base.color, 1.0) * specularIntensity * specularFactor;
		}
	}

	return diffuseColor + specularColor;
}

vec4 calcDirectionalLight(DirectionalLight directionalLight, vec3 normal) {
    return calcLight(directionalLight.base, -directionalLight.direction, normal);
}

void main() {
	vec4 light = vec4(ambient, 1);
	vec4 colorA = vec4(color, 1);
	vec4 textureColor = texture(sampler, texCoord0.xy);

	if(textureColor != vec4(0,0,0,0)) {
        colorA *= textureColor;
	}

	vec3 normal = normalize(normal0);
	
	light += calcDirectionalLight(directionalLight, normal);

	fragColor = colorA * light;
}