#version 330 core


in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D pass1;

void main()
{
	vec3 result = texture(pass1, vec2(TexCoord.x, 1.0 - TexCoord.y)).rgb;

	FragColor = vec4(result, 1.0);
}
