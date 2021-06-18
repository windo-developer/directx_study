#pragma once
#include "Component.h"
#include "Object.h"

class Transform;
class MeshRenderer;
class Camera;
class MonoBehaviour;
class Light;

class GameObject : public Object, public enable_shared_from_this<GameObject>
{
public:
	GameObject();
	virtual ~GameObject();

	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	void FinallUpdate();

	shared_ptr<Component> GetFixedComponent(COMPONENT_TYPE type);
	shared_ptr<Transform> GetTransform();
	shared_ptr<MeshRenderer> GetMeshRenderer();
	shared_ptr<Camera> GetCamera();
	shared_ptr<Light> GetLight();

	void AddComponent(shared_ptr<Component> component);

private:
	array<shared_ptr<Component>, FIXED_COMPOENT_COUNT> _compoents;
	vector<shared_ptr<MonoBehaviour>> _script;
};
