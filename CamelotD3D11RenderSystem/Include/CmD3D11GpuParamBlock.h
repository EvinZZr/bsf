#pragma once

#include "CmD3D11Prerequisites.h"
#include "CmGpuParamBlock.h"

namespace CamelotEngine
{
	class CM_D3D11_EXPORT D3D11GpuParamBlock : public GpuParamBlock
	{
	private:
		struct D3D11GpuParamBlockSharedData
		{
			D3D11HardwareBuffer* mBuffer;
		};

	public:
		D3D11GpuParamBlock(const GpuParamBlockDesc& desc, GpuParamBlockUsage usage);
		~D3D11GpuParamBlock();

		virtual void updateIfDirty();
		virtual GpuParamBlockPtr clone() const;

		ID3D11Buffer* getD3D11Buffer() const;

	private:
		D3D11GpuParamBlockSharedData* mD3D11SharedData;
	};
}