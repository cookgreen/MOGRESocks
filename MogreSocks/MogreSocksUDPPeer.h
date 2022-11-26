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
			std::list<char> cdata = Util::ConvertByteArrayToListChar(data);

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