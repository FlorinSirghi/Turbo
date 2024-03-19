#ifndef RENDERER_RENDERERCOMMAND_H_
#define RENDERER_RENDERERCOMMAND_H_

#include <memory>
#include <stdint.h>

#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IShaderProgram.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/ITexture.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IVertexArray.h"
#include "Engine/SceneGraph/Components/Transform.h"

namespace Turbo
{
	class RenderCommand
	{
	public:

		RenderCommand(std::shared_ptr<IShaderProgram> sp,
			std::shared_ptr<IVertexArray>   va,
			std::shared_ptr<ITexture>	tex,
			Transform t,
			const int& parent_ind,
			const uint32_t& vc,
			const bool& i,
			const bool& w,
			const int& m) :
		shader_program(std::move(sp)), vertex_array(std::move(va)), texture(std::move(tex)), transform(std::move(t)),
			parent_index(parent_ind), vertex_count(vc), indexed(i), wireframe(w), mode(m) {
	}

	private:

		std::shared_ptr<IShaderProgram> shader_program{};
		std::shared_ptr<IVertexArray> vertex_array{};
		std::shared_ptr<ITexture> texture{};
		Transform transform{};
		int parent_index{};
		uint32_t vertex_count{};
		bool indexed{};
		bool wireframe{};
		int mode{};

	public:

		class Builder
		{

		public:

			Builder(std::shared_ptr<IShaderProgram> sp, std::shared_ptr<IVertexArray> va, Transform t, uint32_t vc, bool i, int m) :
			shader_program(std::move(sp)), vertex_array(std::move(va)), transform(std::move(t)), vertex_count(vc), indexed(i), mode(m)
			{}

			void SetTexture(std::shared_ptr<ITexture> tex)
			{
				texture = std::move(tex);
			}

			void SetParentIndex(int pi)
			{
				parent_index = pi;
			}

			void SetWireframe(bool wf)
			{
				wireframe = wf;
			}

			std::shared_ptr<RenderCommand> Build()
			{
				return std::shared_ptr<RenderCommand>(
					std::make_shared<RenderCommand>(
						shader_program, vertex_array, texture, transform, parent_index, vertex_count, indexed, wireframe, mode ));
			}

		private:

			std::shared_ptr<IShaderProgram> shader_program;
			std::shared_ptr<IVertexArray> vertex_array;
			std::shared_ptr<ITexture> texture;
			Transform transform;
			int parent_index{};
			uint32_t vertex_count;
			bool indexed{};
			bool wireframe{};
			int mode{};
		};
	};
}

#endif // RENDERER_RENDERERCOMMAND_H_