#ifndef _MOGRESOCKSTCP_H
#define _MOGRESOCKSTCP_H

#include "OgreSocksTCP.h"
#include "MogreSocksBase.h"

using namespace OgreSocks;
using namespace System;

namespace MogreSocks
{
	public ref class MogreSocksTCP : MogreSocksBase
	{
	private:
		OgreSocksTCP* _nativePtr;

	public:
		~MogreSocksTCP()
		{

		}

		void SetConnectListener(ConnnectListener^ theCallback)
		{
			_nativePtr->SetConnectListener(theCallback->GetNativePtr());
		}

		void SetDisconnectListener(DisconnectListener^ theCallback)
		{
			_nativePtr->SetDisconnectListener(theCallback->GetNativePtr());
		}

	protected:
		!MogreSocksTCP()
		{

		}
	};
}
#endif