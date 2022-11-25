#ifndef _MOGRESOCKSCONNDATA_H
#define _MOGRESOCKSCONNDATA_H

#include "OgreSocksConnData.h"

using namespace System;

namespace MogreSocks
{
	public ref struct MogreSocksConnData
	{
	private:
		OgreSocksConnData* _nativePtr;

	public:
		MogreSocksConnData()
		{

		}
		MogreSocksConnData(OgreSocksConnData* _nativePtr)
		{
			this->_nativePtr = _nativePtr;
		}

		~MogreSocksConnData()
		{
			delete _nativePtr;
		}

		OgreSocksConnData* GetNativePtr(){
			return _nativePtr;
		}
	};
}

#endif