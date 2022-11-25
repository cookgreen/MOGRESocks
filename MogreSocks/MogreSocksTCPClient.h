#include "OgreSocksTCPClient.h"
#include "MogreSocksTCP.h"
#include "Util.h"

using namespace OgreSocks;
using namespace System;

namespace MogreSocks
{
	public ref class MogreSocksTCPClient : MogreSocksTCP
	{
	private:
		OgreSocksTCPClient* _nativePtr;

	public:
		int Connect(String^ addr, unsigned long port)
		{
			Ogre::String saddr;
			Util::ConvertManagedStrToOgreStr(saddr, addr);
			return _nativePtr->Connect(saddr, port);
		}

		virtual void Send(array<System::Byte>^ data, String^ addr, unsigned long port)
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

		OgreSocksTCPClient* GetNativePtr()
		{
			return _nativePtr;
		}
	};
}