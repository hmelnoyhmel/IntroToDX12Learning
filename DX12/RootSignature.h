#pragma once

#include "d3dUtil.h"

using namespace Microsoft::WRL;

class RootSignature
{
	ComPtr<ID3D12RootSignature> signature;

	static std::array<const CD3DX12_STATIC_SAMPLER_DESC, 7> GetStaticSamplers();;

	std::vector<CD3DX12_ROOT_PARAMETER> slotRootParameters;

	void AddParameter(CD3DX12_ROOT_PARAMETER parameter);

	std::vector<D3D12_STATIC_SAMPLER_DESC> staticSampler;
	
public:

	void AddDescriptorParameter(CD3DX12_DESCRIPTOR_RANGE* rangeParameters, UINT size,
	                            D3D12_SHADER_VISIBILITY visibility = D3D12_SHADER_VISIBILITY_ALL);

	void AddConstantBufferParameter(UINT shaderRegister, UINT registerSpace = 0,
	                                D3D12_SHADER_VISIBILITY visibility = D3D12_SHADER_VISIBILITY_ALL);

	void AddConstantParameter(UINT value, UINT shaderRegister, UINT registerSpace = 0,
	                          D3D12_SHADER_VISIBILITY visibility = D3D12_SHADER_VISIBILITY_ALL);
	
	void AddShaderResourceView(UINT shaderRegister, UINT registerSpace = 0,
	                           D3D12_SHADER_VISIBILITY visibility = D3D12_SHADER_VISIBILITY_ALL);

	void AddUnorderedAccessView(UINT shaderRegister, UINT registerSpace = 0,
	                            D3D12_SHADER_VISIBILITY visibility = D3D12_SHADER_VISIBILITY_ALL);

	void AddStaticSampler(const CD3DX12_STATIC_SAMPLER_DESC sampler);
	void AddStaticSampler(D3D12_STATIC_SAMPLER_DESC sampler);;
	
	void Initialize(ID3D12Device* device);

	ComPtr<ID3D12RootSignature> GetRootSignature() const;
};
