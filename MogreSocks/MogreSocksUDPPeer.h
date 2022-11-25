#include "OgreSocksUDPPeer.h"
#include "MogreSocksBase.h"

using namespace OgreSocks;
using namespace System;

namespace MogreSocks
{
	public ref class MogreSocksUDPPeer : MogreSocksBase
	{
	private:
		OgreSocksUDPPeer* _nativePtr;
	public:
		property int MessageSize 
		{ 
			int get()
			{
				return _nativePtr->GetMessageSize();
			}
		}

		virtual void Send(array<byte>^ data, String^ addr, unsigned long port)
		{
			std::list<char> cdata;
			for (int i=0;i<data->GetUpperBound(0);i++)
			{
				char c = *(Byte^)data->GetValue(i);
				cdata.push_back(c);
			}

			Ogre::String saddr;
			Util::ConvertManagedStrToOgreStr(saddr, addr);

			_nativePtr->Send(cdata, saddr, port);
		}

		OgreSocksUDPPeer* GetNativePtr()
		{
			return _nativePtr;
		}
	};
}