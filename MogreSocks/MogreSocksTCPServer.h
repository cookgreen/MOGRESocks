#include "OgreSocksTCPServer.h"
#include "MogreSocksTCP.h"
#include "MogreSocksConnData.h"

using namespace OgreSocks;
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

namespace MogreSocks
{
	public ref class MogreSocksTCPServer : MogreSocksTCP
	{
	private:
		OgreSocksTCPServer* _nativePtr;

	public:
		MogreSocksTCPServer()
		{

		}
		~MogreSocksTCPServer()
		{

		}

		property unsigned long NumConnections
		{
			unsigned long get()
			{
				return _nativePtr->GetNumConnections();
			}
		}

		property bool IsListening
		{ 
			bool get()
			{
				return _nativePtr->IsListening();
			} 
		}

		property List<MogreSocksConnData^>^ Connections
		{
			List<MogreSocksConnData^>^ get()
			{
				std::list<OgreSocksConnData> socketList = _nativePtr->GetListConnectionData();
				List<MogreSocksConnData^>^ msocketList = gcnew List<MogreSocksConnData^>();
				
				for (std::list<OgreSocksConnData>::iterator it = socketList.begin(); it != socketList.end(); ++it) 
				{
					OgreSocksConnData socketData = *it;
					MogreSocksConnData^ msockData = gcnew MogreSocksConnData(&socketData);
					msocketList->Add(msockData);
				}

				return msocketList;
			}
		}

		virtual void Send(array<Byte>^  data, String^ addr, unsigned long port) override
		{
			std::list<char> cdata = Util::ConvertByteArrayToListChar(data);

			Ogre::String saddr;
			Util::ConvertManagedStrToOgreStr(saddr, addr);

			_nativePtr->Send(cdata, saddr, port);
		}

		void CloseConnectionTo(String^ addr, unsigned long port)
		{
			Ogre::String saddr;
			Util::ConvertManagedStrToOgreStr(saddr, addr);

			_nativePtr->CloseConnectionTo(saddr, port);
		}

		OgreSocksTCPServer* GetNativePtr()
		{
			return _nativePtr;
		}
	protected:

		!MogreSocksTCPServer()
		{
		}
	};
}