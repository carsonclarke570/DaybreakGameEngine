uniform vec3 viewPos;
uniform Material material;
uniform PointLight light;

void Fragment() {

	vec3 norm = normalize(fs_in.normal0);
    vec3 viewDir = normalize(viewPos - fs_in.position0);

	vec3 lightDir = normalize(light.position - fs_in.position0);

	float diff = max(dot(norm, lightDir), 0.0);

	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.specPow);
    
    float distance = length(light.position - fs_in.position0);
    float attenuation = 1.0 / (light.attenuation.constant + light.attenuation.linear * distance + light.attenuation.quadratic * (distance * distance));    
    
    vec3 ambient = light.light.ambient * vec3(texture(material.diffuse, fs_in.texture0));
    vec3 diffuse = light.light.diffuse * diff * vec3(texture(material.diffuse, fs_in.texture0));
    vec3 specular = light.light.specular * spec * vec3(texture(material.specular, fs_in.texture0));
   
	ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    fragColor = vec4(ambient + diffuse + specular, 1.0f);
}