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
#version 330 core
layout(location = 0) out vec4 color;
in vec2 f_position;

void main()
{
    vec2 uv = normalize(gl_FragCoord.xy);
    float d = length(vec2(uv));
    float t = smoothstep(0.1, 0.2, d);
    color = vec4(0.0,0.0,1.0,1.0);
    if (f_position.x < 0.5){
        color.x = 1.0;
    }
};
