#shader vertex
#version 330 core
layout(location = 0) in vec4 position;
out vec2 f_position;

void main()
{
    f_position = position.xy;
    gl_Position = position;
};

#shader fragment
#version 410 core
layout(location = 0) out vec4 color;
in vec2 f_position;

uniform float radius;
uniform vec2 ball_center;

void main()
{
    float t = 0.0;
    if (length(f_position-ball_center) < radius) t = 1.0;
    color = vec4(1.0,1.0,1.0,t);
};
