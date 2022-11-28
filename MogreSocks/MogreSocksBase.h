#ifndef _MOGRESOCKSBASE_H_
#define _MOGRESOCKSBASE_H_

#include "OgreSocksBase.h"
#include "MogreSocksEvents.h"
#include "MogreSocksConnData.h"

using namespace OgreSocks;
using namespace System;

namespace MogreSocks
{
	public ref class MogreSocksBase
	{
	public:
		virtual void Send(array<Byte>^ marr, String^ addr, unsigned long port)
		{
			std::list<char> cdata = Util::ConvertByteArrayToListChar(marr);

			Ogre::String o_str;
			Util::ConvertManagedStrToOgreStr(o_str, addr);

			_nativePtr->Send(cdata, o_str, port);
		}
		
		MogreSocksConnData^ GetConnectionData() 
		{ 
			OgreSocksConnData ogreSocksConn = _nativePtr->GetConnectionData();
			MogreSocksConnData^ mogreSocksConn  = gcnew MogreSocksConnData(&ogreSocksConn);
			return mogreSocksConn; 
		}

		void SetReceiveListener(ReceiveListener^ listener)
		{
			_nativePtr->SetReceiveListener(listener->GetNativePtr());
		}

		OgreSocksBase* GetNativePtr()
		{
			return _nativePtr;
		}

	private:
		OgreSocksBase* _nativePtr;
	protected:

		~MogreSocksBase()
		{
		}

		!MogreSocksBase()
		{
		}
	};
}
#endif