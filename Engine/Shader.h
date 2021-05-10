#pragma once

class Shader
{
public:
	void Init(const wstring& path);
	void Update();

	// TODO: create Shader
private:
	void CreateShader(const wstring& path, const string& name, const string);

private:
	ComPtr<ID3DBlob>	_vsBlob;
	ComPtr<ID3DBlob>	_psBlob;
	ComPtr<ID3DBlob>	_errBlob;

	ComPtr<ID3D12PipelineState>			_pipelineState;
	D3D12_GRAPHICS_PIPELINE_STATE_DESC	_pipelineDesc = {};
};
