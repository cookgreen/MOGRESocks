#ifndef _MOGRESOCKSCONNDATA_H
#define _MOGRESOCKSCONNDATA_H

#include "OgreSocksConnData.h"
#include "Util.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

namespace MogreSocks
{
	public ref struct MogreSocksConnData
	{
	private:
		OgreSocksConnData* _nativePtr;

	public:
		property Socket^ Sock
		{
			Socket^ get()
			{
				SOCKET s = _nativePtr->sock;
				return Util::ConvertSocketHandleToManagedSocket(s);
			}
			void set(Socket^ sockt)
			{
				_nativePtr->sock = Util::ConvertMangedSocketToSocketHandle(sockt);
			}
		}

		property IPEndPoint^ SockAddr
		{
			IPEndPoint^ get()
			{
				SOCKADDR_IN sAddr = _nativePtr->sockAddr;
				return Util::ConvertSockAddrInToManagedIPEndPoint(sAddr);
			}
			void set(IPEndPoint^ addr)
			{
				_nativePtr->sockAddr = Util::ConvertManagedIPEndPointToSockAddrIn(addr);
			}
		}

		property IPEndPoint^ SockAddrRemote
		{
			IPEndPoint^ get()
			{
				SOCKADDR_IN sAddr = _nativePtr->sockAddrRemote;
				return Util::ConvertSockAddrInToManagedIPEndPoint(sAddr);
			}
			void set(IPEndPoint^ addr)
			{
				_nativePtr->sockAddrRemote = Util::ConvertManagedIPEndPointToSockAddrIn(addr);
			}
		}


		property String^ Addr
		{
			String^ get()
			{
				Ogre::String o_str = _nativePtr->strAddr;
				return Util::ConvertOgreStrToManagedStr(o_str);
			}
			void set(String^ addr)
			{
				Ogre::String o_str;
				Util::ConvertManagedStrToOgreStr(o_str, addr);
				_nativePtr->strAddr = o_str;
			}
		}
		property unsigned long Port
		{
			unsigned long get()
			{
				return _nativePtr->ulPort;
			}
			void set(unsigned long port)
			{
				_nativePtr->ulPort = port;
			}
		}
		property bool IsConnected
		{
			bool get()
			{
				return _nativePtr->bConnected;
			}
			void set(bool isConnected)
			{
				_nativePtr->bConnected = isConnected;
			}
		}

		property array<Byte>^ SendDataList
		{
			array<Byte>^ get()
			{
				std::list<char> cdata = _nativePtr->listSend;
				return Util::ConvertListCharToByteArray(cdata);
			}
			void set(array<Byte>^ newArr)
			{
				std::list<char> cdata = Util::ConvertByteArrayToListChar(newArr);
				_nativePtr->listSend = cdata;
			}
		}

		property unsigned long BytesToSend
		{
			unsigned long get()
			{
				return _nativePtr->lBytesToSend;
			}
			void set(unsigned long val)
			{
				_nativePtr->lBytesToSend = val;
			}
		}

		property unsigned long LastNumBytesSent
		{
			unsigned long get()
			{
				return _nativePtr->lLastNumBytesSent;
			}
			void set(unsigned long val)
			{
				_nativePtr->lLastNumBytesSent = val;
			}
		}

		property unsigned long LastNumTriesToSend
		{
			unsigned long get()
			{
				return _nativePtr->lLastNumTriesToSend;
			}
			void set(unsigned long val)
			{
				_nativePtr->lLastNumTriesToSend = val;
			}
		}

		property bool IsRetryingSend
		{
			bool get()
			{
				return _nativePtr->bRetryingSend;
			}
			void set(bool val)
			{
				_nativePtr->bRetryingSend = val;
			}
		}

		property unsigned long TotalBytesSent
		{
			unsigned long get()
			{
				return _nativePtr->lTotalBytesSent;
			}
			void set(unsigned long val)
			{
				_nativePtr->lTotalBytesSent = val;
			}
		}

		property array<Byte>^ ListReceive
		{
			array<Byte>^ get()
			{
				return Util::ConvertListCharToByteArray(_nativePtr->listReceive);
			}
			void set(array<Byte>^ bArr)
			{
				_nativePtr->listReceive = Util::ConvertByteArrayToListChar(bArr);
			}
		}

		property unsigned long LastNumBytesReceived
		{
			unsigned long get()
			{
				return _nativePtr->lLastNumBytesReceived;
			}
			void set(unsigned long val)
			{
				_nativePtr->lLastNumBytesReceived = val;
			}
		}

		property unsigned long TotalBytesReceived
		{
			unsigned long get()
			{
				return _nativePtr->lTotalBytesReceived;
			}
			void set(unsigned long val)
			{
				_nativePtr->lTotalBytesReceived = val;
			}
		}

		property bool IsInitShutdown
		{
			bool get()
			{
				return _nativePtr->bInitShutdown;
			}
			void set(bool val)
			{
				_nativePtr->bInitShutdown = val;
			}
		}

		property array<Byte>^ ListLastSent
		{
			array<Byte>^ get()
			{
				return Util::ConvertListCharToByteArray(_nativePtr->listLastSent);
			}
			void set(array<Byte>^ bArr)
			{
				_nativePtr->listLastSent = Util::ConvertByteArrayToListChar(bArr);
			}
		}
		
		MogreSocksConnData()
		{
			_nativePtr = new OgreSocksConnData();
		}
		MogreSocksConnData(OgreSocksConnData* _nativePtr)
		{
			this->_nativePtr = _nativePtr;
		}

		~MogreSocksConnData()
		{
			delete _nativePtr;
		}

		void Empty()
		{
			_nativePtr->empty();
		}

		void ResetSendData()
		{
			_nativePtr->ResetReceiveData();
		}

		void ResetReceiveData()
		{
			_nativePtr->ResetReceiveData();
		}

		OgreSocksConnData* GetNativePtr(){
			return _nativePtr;
		}
	};
}

#endif