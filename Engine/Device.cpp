#include "pch.h"
#include "Device.h"

void Device::Init()
{
	// 디버그 추가 기능 활성화
#ifdef _DEBUG
	::D3D12GetDebugInterface(IID_PPV_ARGS(&_debugController));
	_debugController->EnableDebugLayer();
#endif
	// DXGI
	::CreateDXGIFactory(IID_PPV_ARGS(&_dxgi));

	// CreateDevice
	::D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&_device));
}
