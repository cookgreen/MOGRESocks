#include "OgreSocksManager.h"

#include "MogreSocksTCPClient.h"
#include "MogreSocksTCPServer.h"
#include "MogreSocksUDPPeer.h"

using namespace OgreSocks;
using namespace System;

namespace MogreSocks
{
	public ref class MogreSocksManager
	{
	private:
		OgreSocksManager* pOgreSocksManager;
		static MogreSocksManager^ instance;

		MogreSocksManager()
		{
		}
		~MogreSocksManager()
		{
		}
		!MogreSocksManager()
		{
		}

	public:
		property MogreSocksManager^ Instance
		{
			MogreSocksManager^ get()
			{
				if(instance == nullptr)
					instance = gcnew MogreSocksManager();

				return instance;
			}
		}

		void Initialise(){ OgreSocksManager::GetSingleton()->Initialise(); }
		
		void CleanUp(){ OgreSocksManager::GetSingleton()->CleanUp(); }
		
		void CreateSocket(MogreSocksTCPClient^& sock)
		{
			OgreSocksTCPClient* pSock = sock->GetNativePtr();
			OgreSocksManager::GetSingleton()->CreateSocket(pSock);
		}

		void CreateSocket(MogreSocksTCPServer^& sock, unsigned long port)
		{
			OgreSocksTCPServer* pSock = sock->GetNativePtr();
			OgreSocksManager::GetSingleton()->CreateSocket(pSock, port);
		}

		void CreateSocket(MogreSocksTCPServer^& socks, String^ addr, unsigned long port)
		{
			Ogre::String saddr;
			Util::ConvertManagedStrToOgreStr(saddr, addr);

			OgreSocksTCPServer* pSocks = socks->GetNativePtr();

			OgreSocksManager::GetSingleton()->CreateSocket(pSocks, saddr, port);
		}

		void CreateSocket(MogreSocksUDPPeer^& sock)
		{
			OgreSocksUDPPeer* pSock = sock->GetNativePtr();
			OgreSocksManager::GetSingleton()->CreateSocket(pSock);
		}

		void CreateSocket(MogreSocksUDPPeer^& sock, unsigned long port)
		{
			OgreSocksUDPPeer* pSock = sock->GetNativePtr();
			OgreSocksManager::GetSingleton()->CreateSocket(pSock, port);
		}
		void CreateSocket(MogreSocksUDPPeer^& sock, String^ addr, unsigned long port)
		{
			Ogre::String saddr;
			Util::ConvertManagedStrToOgreStr(saddr, addr);

			OgreSocksUDPPeer* pSock = sock->GetNativePtr();
			OgreSocksManager::GetSingleton()->CreateSocket(pSock, saddr, port);
		}
		void DeleteSocket(MogreSocksTCPClient^& sock)
		{
			OgreSocksTCPClient* pSock = sock->GetNativePtr();
			OgreSocksManager::GetSingleton()->DeleteSocket(pSock);
		}

		void DeleteSocket(MogreSocksTCPServer^& sock)
		{
			OgreSocksTCPServer* pSock = sock->GetNativePtr();
			OgreSocksManager::GetSingleton()->DeleteSocket(pSock);
		}

		void DeleteSocket(MogreSocksUDPPeer^& sock)
		{
			OgreSocksUDPPeer* pSock = sock->GetNativePtr();
			OgreSocksManager::GetSingleton()->DeleteSocket(pSock);
		}

		unsigned long GetNumSockets() { return OgreSocksManager::GetSingleton()->GetNumSockets(); }
		void SetCreateTimeout(unsigned long& timeout){OgreSocksManager::GetSingleton()->SetCreateTimeout(timeout);}
		void SetDeleteTimeout(unsigned long& timeout){OgreSocksManager::GetSingleton()->SetDeleteTimeout(timeout);}
	};
}