#version 330 core

uniform vec4 color = vec4(1., 1., 1., 1.);
out vec4 outputF;

void main() {
    outputF = color;
}

