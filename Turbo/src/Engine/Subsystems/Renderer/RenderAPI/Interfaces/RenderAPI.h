#pragma once
#include <string>

class RenderAPI
{
public:
	virtual void createVertexBuffer() = 0;

	virtual void createShader(std::string shaderPath) = 0;
};