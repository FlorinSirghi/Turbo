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
					  std::shared_ptr<ITexture>		  tex, 
					  const Vector3D&				  pos,
					  const Vector3D&				  scl,
					  const Vector3D&				  rot,
					  const uint32_t&				  vc, 
					  const bool&					  i, 
					  const int&					  m) :
						shader_program(std::move(sp)), vertex_array(std::move(va)), texture(std::move(tex)),
						position(pos), scale(scl), rotation(rot), vertex_count(vc), indexed(i), mode(m) {
		}

		RenderCommand(std::shared_ptr<IShaderProgram> sp, 
					  std::shared_ptr<IVertexArray>   va, 
					  const Vector3D&				  pos,
					  const Vector3D&				  scl,
					  const Vector3D&				  rot,
					  const uint32_t&				  vc, 
					  const bool&					  i, 
					  const int&					  m) :
			shader_program(std::move(sp)), vertex_array(std::move(va)), position(pos), scale(scl), rotation(rot), vertex_count(vc), indexed(i), mode(m) {

			texture = nullptr;
		}

		RenderCommand(std::shared_ptr<IShaderProgram> sp,
			std::shared_ptr<IVertexArray>			  va,
			std::shared_ptr<ITexture>				  tex,
			const Vector3D&							  pos,
			const Vector3D&						      scl,
			const uint32_t&							  vc,
			const bool&								  i,
			const int&								  m) :
			shader_program(std::move(sp)), vertex_array(std::move(va)), texture(std::move(tex)),
			position(pos), scale(scl), vertex_count(vc), indexed(i), mode(m) {
		}

		RenderCommand(std::shared_ptr<IShaderProgram> sp,
			std::shared_ptr<IVertexArray>			  va,
			const Vector3D&							  pos,
			const Vector3D&							  scl,
			const uint32_t&							  vc,
			const bool&								  i,
			const int&								  m) :
			shader_program(std::move(sp)), vertex_array(std::move(va)), position(pos), scale(scl), vertex_count(vc), indexed(i), mode(m) {

			texture = nullptr;
		}

		

		std::shared_ptr<IShaderProgram> shader_program;
		std::shared_ptr<IVertexArray> vertex_array;
		std::shared_ptr<ITexture> texture;
		Vector3D position;
		Vector3D scale;
		Vector3D rotation;
		uint32_t vertex_count;
		bool indexed;
		int mode;
	};
}

#endif // RENDERER_RENDERERCOMMAND_H_