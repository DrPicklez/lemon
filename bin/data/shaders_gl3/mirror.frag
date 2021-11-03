#version 460

uniform sampler2DRect mask;
uniform sampler2DRect tex0;
in vec2 texCoordVarying;
out vec4 outputColor;

in vec2 position;
vec4 color;

void main(){
    vec4 spray = texture(tex0, texCoordVarying);
    vec4 _mask = texture(mask, texCoordVarying);
    outputColor = _mask * spray;
    //outputColor = _mask;
}
