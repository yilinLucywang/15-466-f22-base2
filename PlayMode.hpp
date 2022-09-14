#include "Mode.hpp"

#include "Scene.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//----- game state -----

	//input tracking:
	struct Button {
		uint8_t downs = 0;
		uint8_t pressed = 0;
	} left, right, down, up, w_left, w_right, w_down, w_up;


	bool pour_water = false;

	//local copy of the game scene (so code can change it during gameplay):
	Scene scene;
	// hexapod leg to wobble:
	Scene::Transform *leaves = nullptr;
	Scene::Transform *trunk = nullptr;


	Scene::Transform *leaves0 = nullptr;
	Scene::Transform *leaves1 = nullptr;
	Scene::Transform *leaves2 = nullptr;
	Scene::Transform *leaves3 = nullptr;
	Scene::Transform *leaves4 = nullptr;

	Scene::Transform *trunk0 = nullptr;
	Scene::Transform *trunk1 = nullptr;
	Scene::Transform *trunk2 = nullptr;
	Scene::Transform *trunk3 = nullptr;
	Scene::Transform *trunk4 = nullptr;

	std::vector<Scene::Transform*> leaves_vector = {};
	std::vector<Scene::Transform*> trunk_vector = {};
	// glm::quat hip_base_rotation;
	// glm::quat upper_leg_base_rotation;
	float wobble = 0.0f;
	int treeCnt = 0;
	bool should_spawn = false;
	void spawn_tree();
	//camera:
	Scene::Camera *camera = nullptr;
	//water bucket: 
	Scene::Transform *water_bucket = nullptr;
	glm::quat water_bucket_rotation;
	glm::quat water_bucket_rotation_original;

};
