#vertex
#version 320 es
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 _color;

uniform mat4 u_View;
uniform mat4 u_Projection;

out vec4 v_color;

void main()
{
	gl_Position = u_Projection * u_View * position;
	v_color = _color;
}

#fragment
#version 320 es

precision mediump float;

in vec4 v_color;

out vec4 color;
void main()
{
	color = v_color;// vec4(1, 1, 1, 1);
}
