#include "pch.h"
#include "GameObject.h"
#include "Transform.h"
#include "MeshRenderer.h"
#include "MonoBehaviour.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Init()
{
	AddComponent(make_shared<Transform>());
}

void GameObject::Awake()
{
	for (shared_ptr<Component>& component : _compoents)
	{
		if (component)
			component->Awake();
	}

	for (shared_ptr<MonoBehaviour>& script : _script)
	{
		script->Awake();
	}
}

void GameObject::Start()
{
	for (shared_ptr<Component>& compoent : _compoents)
	{
		if (compoent)
			compoent->Start();
	}

	for (shared_ptr<MonoBehaviour>& script : _script)
	{
		script->Start();
	}
}

void GameObject::Update()
{
	for (shared_ptr<Component>& compoent : _compoents)
	{
		if (compoent)
			compoent->Update();
	}

	for (shared_ptr<MonoBehaviour>& script : _script)
	{
		script->Update();
	}
}

void GameObject::LateUpdate()
{
	for (shared_ptr<Component>& compoent : _compoents)
	{
		if (compoent)
			compoent->LateUpdate();
	}

	for (shared_ptr<MonoBehaviour>& script : _script)
	{
		script->LateUpdate();
	}
}

shared_ptr<Transform> GameObject::GetTransform()
{
	uint8 index = static_cast<uint8>(COMPONENT_TYPE::TRANSFORM);
	return static_pointer_cast<Transform>(_compoents[index]);
}

void GameObject::AddComponent(shared_ptr<Component> component)
{
	component->SetGameObjct(shared_from_this());

	uint8 index = static_cast<uint8>(component->GetType());
	if (index < FIXED_COMPOENT_COUNT)
	{
		_compoents[index] = component;
	}
	else
	{
		_script.push_back(dynamic_pointer_cast<MonoBehaviour>(component));
	}
}
