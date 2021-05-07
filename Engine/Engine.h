#pragma once

#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"

class Engine
{
public:
	void Init(const WindowInfo& info);
	void Render();

public:
	shared_ptr<class Device> GetDevice() { return _device; }
	shared_ptr<class CommandQueue> GetComdQueue() { return _cmdQueue; }
	shared_ptr<class SwapChain> GetSwapChain() { return _swapChain; }

public:
	void RenderBegin();
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height);

private:
	// window size
	WindowInfo			_window;
	D3D12_VIEWPORT		_viewport = {};
	D3D12_RECT			_scissorRect = {};

	shared_ptr<class Device> _device;
	shared_ptr<class CommandQueue> _cmdQueue;
	shared_ptr<class SwapChain> _swapChain;
};
