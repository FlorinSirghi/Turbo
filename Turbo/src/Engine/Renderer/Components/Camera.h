#ifndef SCENEGRAPH_CAMERA_H_
#define SCENEGRAPH_CAMERA_H_

namespace Turbo
{
	class Camera : public Component
	{
	public:

		Camera() : Component()
		{
			name = CAMERA;
		}

		void update() override
		{
			//Vector3D cameraPos = std::dynamic_pointer_cast<Position>(game_object->getPropertyByName(POSITION))->pos;
			//Renderer2D::camera_position = cameraPos;
			//Renderer3D::camera_position = cameraPos;
		}

	};
}

#endif // SCENEGRAPH_CAMERA_H_