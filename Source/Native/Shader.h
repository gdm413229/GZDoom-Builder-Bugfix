#pragma once

#include <string>
#include "RenderDevice.h"

enum class DeclarationUsage : int32_t { Position, Color, TextureCoordinate, Normal };

class Shader
{
public:
	void ReleaseResources();

	void Setup(const std::string& vertexShader, const std::string& fragmentShader, bool alphatest);
	void Bind(const std::vector<UniformDecl> &uniforms);

	std::vector<GLuint> UniformLocations;

private:
	void CreateProgram(const std::vector<UniformDecl>& uniforms);
	GLuint CompileShader(const std::string& code, GLenum type);

	std::string mVertexText;
	std::string mFragmentText;
	bool mAlphatest = false;
	bool mProgramBuilt = false;

	GLuint mProgram = 0;
	GLuint mVertexShader = 0;
	GLuint mFragmentShader = 0;
	std::string mErrors;
};
