#ifndef RENDERER_RENDERERCOMMAND_H_
#define RENDERER_RENDERERCOMMAND_H_

#include <memory>
#include <stdint.h>

#include "Engine/Core/Math/Vector/Vector3D.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IShaderProgram.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/ITexture.h"
#include "Engine/PlatformIndependenceLayer/GraphicsWrapper/Interfaces/IVertexArray.h"

namespace Turbo
{
	class RenderCommand
	{
	public:

		RenderCommand(std::shared_ptr<IShaderProgram> sp,
			std::shared_ptr<IVertexArray>   va,
			const Vector3D& pos,
			const Vector3D& scl,
			const Vector3D& rot,
			const Vector3D& local_pos,
			const Vector3D& local_rot,
			const int& parent_ind,
			const uint32_t& vc,
			const bool& i,
			const bool& w,
			const int& m) :
		shader_program(std::move(sp)), vertex_array(std::move(va)), texture(nullptr),
		position(pos), scale(scl), rotation(rot), local_position(local_pos), local_rotation(local_rot),
			parent_index(parent_ind),vertex_count(vc), indexed(i), wireframe(w), mode(m) {
	}

		RenderCommand(std::shared_ptr<IShaderProgram> sp,
			std::shared_ptr<IVertexArray>   va,
			const Vector3D& pos,
			const Vector3D& scl,
			const Vector3D& rot,
			const Vector3D& local_pos,
			const Vector3D& local_rot,
			const uint32_t& vc,
			const bool& i,
			const bool& w,
			const int& m) :
			shader_program(std::move(sp)), vertex_array(std::move(va)), texture(nullptr),
			position(pos), scale(scl), rotation(rot), local_position(local_pos), local_rotation(local_rot), vertex_count(vc),
			indexed(i), wireframe(w), mode(m) {
			parent_index = -1.0f;
		}


		RenderCommand(std::shared_ptr<IShaderProgram> sp,
			std::shared_ptr<IVertexArray>   va,
			std::shared_ptr<ITexture>		  tex,
			const Vector3D& pos,
			const Vector3D& scl,
			const Vector3D& rot,
			const Vector3D& local_pos,
			const Vector3D& local_rot,
			const uint32_t& vc,
			const bool& i,
			const bool& w,
			const int& m) :
			shader_program(std::move(sp)), vertex_array(std::move(va)), texture(std::move(tex)),
			position(pos), scale(scl), rotation(rot), local_position(local_pos), local_rotation(local_rot),  vertex_count(vc),
			indexed(i), wireframe(w), mode(m) {
			parent_index = -1.0f;
		}

		RenderCommand(std::shared_ptr<IShaderProgram> sp, 
					  std::shared_ptr<IVertexArray>   va, 
					  std::shared_ptr<ITexture>		  tex, 
					  const Vector3D&				  pos,
					  const Vector3D&				  scl,
					  const Vector3D&				  rot,
					  const uint32_t&				  vc, 
					  const bool&					  i,
					  const bool&					  w,
					  const int&					  m) :
						shader_program(std::move(sp)), vertex_array(std::move(va)), texture(std::move(tex)),
						position(pos), scale(scl), rotation(rot), vertex_count(vc), indexed(i), wireframe(w), mode(m) {
			parent_index = -1.0f;
		}

		RenderCommand(std::shared_ptr<IShaderProgram> sp, 
					  std::shared_ptr<IVertexArray>   va, 
					  const Vector3D&				  pos,
					  const Vector3D&				  scl,
					  const Vector3D&				  rot,
					  const uint32_t&				  vc, 
					  const bool&					  i,
					  const bool&					  w,
					  const int&					  m) :
					    shader_program(std::move(sp)), vertex_array(std::move(va)), texture(nullptr),
						position(pos), scale(scl), rotation(rot), vertex_count(vc), indexed(i), wireframe(w), mode(m) {
			parent_index = -1.0f;
		}


		std::shared_ptr<IShaderProgram> shader_program;
		std::shared_ptr<IVertexArray> vertex_array;
		std::shared_ptr<ITexture> texture;
		Vector3D position;
		Vector3D scale;
		Vector3D rotation;
		Vector3D local_position;
		Vector3D local_rotation;
		int parent_index;
		uint32_t vertex_count;
		bool indexed;
		bool wireframe;
		int mode;
	};
}

#endif // RENDERER_RENDERERCOMMAND_H_