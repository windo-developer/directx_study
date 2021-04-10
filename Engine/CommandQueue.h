#pragma once

class SwapChain;
class DescriptorHeap;

class CommandQueue
{
public:

	~CommandQueue();
	void Init(ComPtr<ID3D12Device> device, shared_ptr<SwapChain> swapChain, shared_ptr<DescriptorHeap> descHeap);
	void WaitSync();

	void RenderBegin(const D3D12_VIEWPORT* vp, const D3D12_RECT* rect);
	void RenderEnd();

	ComPtr<ID3D12CommandQueue> GetcmdQueue() { return _cmdQueue; }

private:
	// 작업 목록 (commandQueue)
	ComPtr<ID3D12CommandQueue>			_cmdQueue;
	ComPtr<ID3D12CommandAllocator>		_cmdAlloc;
	ComPtr<ID3D12GraphicsCommandList>	_cmdList;

	//CPU, GPU 동기화
	ComPtr<ID3D12Fence>	_fence;
	uint32				_fenceValue = 0;
	HANDLE				_fenceEvent = INVALID_HANDLE_VALUE;

	shared_ptr<SwapChain>		_swapChain;
	shared_ptr<DescriptorHeap>	_descHeap;
};
