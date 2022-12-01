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
		property static MogreSocksManager^ Instance
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
		
		MogreSocksTCPClient^ CreateSocket()
		{
			OgreSocksTCPClient* pSock = NULL;
			OgreSocksManager::GetSingleton()->CreateSocket(pSock);
			MogreSocksTCPClient^ msock = gcnew MogreSocksTCPClient(pSock);
			return msock;
		}

		MogreSocksTCPServer^ CreateSocket(unsigned long port)
		{
			OgreSocksTCPServer* pSock = NULL;
			OgreSocksManager::GetSingleton()->CreateSocket(pSock, port);
			MogreSocksTCPServer^ msocks = gcnew MogreSocksTCPServer(pSock);
			return msocks;
		}

		MogreSocksTCPServer^ CreateSocket(String^ addr, unsigned long port)
		{
			Ogre::String saddr;
			Util::ConvertManagedStrToOgreStr(saddr, addr);

			OgreSocksTCPServer* pSocks = NULL;
			OgreSocksManager::GetSingleton()->CreateSocket(pSocks, saddr, port);

			MogreSocksTCPServer^ msocks = gcnew MogreSocksTCPServer(pSocks);
			return msocks;
		}

		MogreSocksUDPPeer^ CreateUDPSocket()
		{
			OgreSocksUDPPeer* pSock = NULL;
			OgreSocksManager::GetSingleton()->CreateSocket(pSock);

			MogreSocksUDPPeer^ peerSocks = gcnew MogreSocksUDPPeer(pSock);
			return peerSocks;
		}

		MogreSocksUDPPeer^ CreateUDPSocket(unsigned long port)
		{
			OgreSocksUDPPeer* pSock = NULL;
			OgreSocksManager::GetSingleton()->CreateSocket(pSock, port);

			MogreSocksUDPPeer^ peerSocks = gcnew MogreSocksUDPPeer(pSock);
			return peerSocks;
		}
		MogreSocksUDPPeer^ CreateUDPSocket(String^ addr, unsigned long port)
		{
			Ogre::String saddr;
			Util::ConvertManagedStrToOgreStr(saddr, addr);

			OgreSocksUDPPeer* pSock = NULL;
			OgreSocksManager::GetSingleton()->CreateSocket(pSock, saddr, port);

			MogreSocksUDPPeer^ peerSocks = gcnew MogreSocksUDPPeer(pSock);
			return peerSocks;
		}
		void DeleteSocket(MogreSocksTCPClient^ sock)
		{
			OgreSocksTCPClient* pSock = sock->GetNativePtr();
			OgreSocksManager::GetSingleton()->DeleteSocket(pSock);
		}

		void DeleteSocket(MogreSocksTCPServer^ sock)
		{
			OgreSocksTCPServer* pSock = sock->GetNativePtr();
			OgreSocksManager::GetSingleton()->DeleteSocket(pSock);
		}

		void DeleteSocket(MogreSocksUDPPeer^ sock)
		{
			OgreSocksUDPPeer* pSock = sock->GetNativePtr();
			OgreSocksManager::GetSingleton()->DeleteSocket(pSock);
		}

		unsigned long GetNumSockets() { return OgreSocksManager::GetSingleton()->GetNumSockets(); }
		void SetCreateTimeout(unsigned long& timeout){OgreSocksManager::GetSingleton()->SetCreateTimeout(timeout);}
		void SetDeleteTimeout(unsigned long& timeout){OgreSocksManager::GetSingleton()->SetDeleteTimeout(timeout);}
	};
}