#pragma once

#include "OpenGLContext.h"

class VertexBuffer;
class IndexBuffer;
class Texture;
class ShaderManager;
class Shader;
enum class CubeMapFace;
enum class VertexFormat;

enum class Cull : int { None, Clockwise };
enum class Blend : int { InverseSourceAlpha, SourceAlpha, One };
enum class BlendOperation : int { Add, ReverseSubtract };
enum class FillMode : int { Solid, Wireframe };
enum class TextureAddress : int { Wrap, Clamp };
enum class ShaderFlags : int { None, Debug };
enum class PrimitiveType : int { LineList, TriangleList, TriangleStrip };
enum class TextureFilter : int { None, Point, Linear, Anisotropic };

typedef int ShaderName;

enum class UniformName : int
{
	rendersettings,
	projection,
	desaturation,
	highlightcolor,
	view,
	world,
	modelnormal,
	FillColor,
	vertexColor,
	stencilColor,
	lightPosAndRadius,
	lightOrientation,
	light2Radius,
	lightColor,
	ignoreNormals,
	spotLight,
	campos,
	texturefactor,
	fogsettings,
	fogcolor,
	NumUniforms
};

class RenderDevice
{
public:
	RenderDevice(void* disp, void* window);
	~RenderDevice();

	void DeclareShader(ShaderName shadername, const char* vertexshader, const char* fragmentshader);
	void SetShader(ShaderName name);
	void SetUniform(UniformName name, const void* values, int count);
	void SetVertexBuffer(VertexBuffer* buffer);
	void SetIndexBuffer(IndexBuffer* buffer);
	void SetAlphaBlendEnable(bool value);
	void SetAlphaTestEnable(bool value);
	void SetCullMode(Cull mode);
	void SetBlendOperation(BlendOperation op);
	void SetSourceBlend(Blend blend);
	void SetDestinationBlend(Blend blend);
	void SetFillMode(FillMode mode);
	void SetMultisampleAntialias(bool value);
	void SetZEnable(bool value);
	void SetZWriteEnable(bool value);
	void SetTexture(Texture* texture);
	void SetSamplerFilter(TextureFilter minfilter, TextureFilter magfilter, TextureFilter mipfilter, float maxanisotropy);
	void SetSamplerState(TextureAddress addressU, TextureAddress addressV, TextureAddress addressW);
	void Draw(PrimitiveType type, int startIndex, int primitiveCount);
	void DrawIndexed(PrimitiveType type, int startIndex, int primitiveCount);
	void DrawData(PrimitiveType type, int startIndex, int primitiveCount, const void* data);
	void StartRendering(bool clear, int backcolor, Texture* target, bool usedepthbuffer);
	void FinishRendering();
	void Present();
	void ClearTexture(int backcolor, Texture* texture);
	void CopyTexture(Texture* dst, CubeMapFace face);

	void SetVertexBufferData(VertexBuffer* buffer, void* data, int64_t size, VertexFormat format);
	void SetVertexBufferSubdata(VertexBuffer* buffer, int64_t destOffset, void* data, int64_t size);
	void SetIndexBufferData(IndexBuffer* buffer, void* data, int64_t size);

	void SetPixels(Texture* texture, const void* data);
	void SetCubePixels(Texture* texture, CubeMapFace face, const void* data);

	void InvalidateTexture(Texture* texture);

	void ApplyChanges();
	void ApplyVertexBuffer();
	void ApplyIndexBuffer();
	void ApplyShader();
	void ApplyUniforms();
	void ApplyTextures();
	void ApplyRasterizerState();
	void ApplyBlendState();
	void ApplyDepthState();

	void CheckError();

	Shader* GetActiveShader();

	GLint GetGLMinFilter(TextureFilter filter, TextureFilter mipfilter);

	std::unique_ptr<IOpenGLContext> Context;

	struct TextureUnit
	{
		Texture* Tex = nullptr;
		GLuint MinFilter = GL_NEAREST;
		GLuint MagFilter = GL_NEAREST;
		float MaxAnisotropy = 0.0f;
		TextureAddress AddressU = TextureAddress::Wrap;
		TextureAddress AddressV = TextureAddress::Wrap;
		TextureAddress AddressW = TextureAddress::Wrap;
	} mTextureUnit;

	VertexBuffer* mVertexBuffer = nullptr;
	IndexBuffer* mIndexBuffer = nullptr;

	std::unique_ptr<ShaderManager> mShaderManager;
	ShaderName mShaderName = {};

	union UniformEntry
	{
		float valuef;
		int32_t valuei;
	};

	UniformEntry mUniforms[4 * 16 + 15 * 4];

	GLuint mStreamVertexBuffer = 0;
	GLuint mStreamVAO = 0;

	Cull mCullMode = Cull::None;
	FillMode mFillMode = FillMode::Solid;
	bool mAlphaTest = false;

	bool mAlphaBlend = false;
	BlendOperation mBlendOperation = BlendOperation::Add;
	Blend mSourceBlend = Blend::SourceAlpha;
	Blend mDestinationBlend = Blend::InverseSourceAlpha;

	bool mDepthTest = false;
	bool mDepthWrite = false;

	bool mNeedApply = true;
	bool mShaderChanged = true;
	bool mUniformsChanged = true;
	bool mTexturesChanged = true;
	bool mIndexBufferChanged = true;
	bool mVertexBufferChanged = true;
	bool mDepthStateChanged = true;
	bool mBlendStateChanged = true;
	bool mRasterizerStateChanged = true;

	bool mContextIsCurrent = false;
};
