#ifndef _UTILS_H
#define _UTILS_H

#include "Ogre.h"

using namespace System;
using namespace System::Text;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace MogreSocks
{
	public ref class Util
	{
	public:
		static void ConvertManagedStrToOgreStr(Ogre::String& o_str, String^ str)
		{
			if(str == nullptr)
				throw gcnew System::NullReferenceException("A null string cannot be converted to an Ogre string.");

			IntPtr p_str = Marshal::StringToHGlobalAnsi(str);
			o_str = static_cast<char*>(p_str.ToPointer());
			Marshal::FreeHGlobal(p_str);
		}

		static String^ ConvertOgreStrToManagedStr(Ogre::String o_str)
		{
			String^ ms = gcnew String(o_str.c_str());
			return ms;
		}

		static Socket^ ConvertSocketHandleToManagedSocket(SOCKET s)
		{
			if(s == INVALID_SOCKET)
				return nullptr;

			SOCKADDR sockaddr;
			int sockaddrlen = sizeof(SOCKADDR);
			getsockname(s, (SOCKADDR*)&sockaddr, &sockaddrlen);

			char* optVal;

			int sockType;
			int sockTypelen = sizeof(int);
			getsockopt(s, SOL_SOCKET, SO_TYPE, optVal, &sockTypelen);
			sockType = (int)*optVal;

			int sockPotoType;
			int sockPotoTypelen = sizeof(int);
			getsockopt(s, SOL_SOCKET, SO_PROTOCOL_INFO, optVal, &sockPotoTypelen);
			sockPotoType = (int)*optVal;

			AddressFamily maddrFamily = (AddressFamily)sockaddr.sa_family;
			SocketType socketType = (SocketType)sockType;
			ProtocolType protocolType = (ProtocolType)sockPotoType;
			
			Socket^ msocket =  gcnew Socket(maddrFamily, socketType, protocolType);
			return msocket;
		}

		static SOCKET ConvertMangedSocketToSocketHandle(Socket^ msocket)
		{
			if(msocket == nullptr)
				return INVALID_SOCKET;

			unsigned short addrFamily = (unsigned short)msocket->AddressFamily;
			int socketType = (int)msocket->SocketType;
			int protocolType = (int)msocket->ProtocolType;
			SOCKET s = socket(addrFamily, socketType, protocolType);
			return s;
		}

		static IPEndPoint^ ConvertSockAddrInToManagedIPEndPoint(SOCKADDR_IN sockAddrIn)
		{
			IPEndPoint^ ipEndPoint = gcnew IPEndPoint(sockAddrIn.sin_addr.s_addr, sockAddrIn.sin_port);
			return ipEndPoint;
		}

		static SOCKADDR_IN ConvertManagedIPEndPointToSockAddrIn(IPEndPoint^ addr)
		{
			if(addr == nullptr)
			{
				SOCKADDR_IN temp;
				return temp;
			}

			SOCKADDR_IN saddr;
			saddr.sin_addr.s_addr = addr->Address->Address;
			saddr.sin_family = (unsigned short)addr->AddressFamily;
			saddr.sin_port = addr->Port;
			return saddr;
		}
		static array<Byte>^ ConvertListCharToByteArray(std::list<char> cdata)
		{
			if(cdata.size()==0)
			{
				List<Byte>^ emptyArr = gcnew List<Byte>();
				return emptyArr->ToArray();
			}

			int length = static_cast<int>(cdata.size());
			char* cdptr = new char[length];
			std::copy(cdata.begin(), cdata.end(), cdptr); 

			array<Byte>^ bArr = gcnew array<Byte>(length);

			Marshal::Copy((IntPtr)cdptr, bArr, 0 ,length);
			delete cdptr;
			return bArr;
		}
		static std::list<char> ConvertByteArrayToListChar(array<Byte>^ bArr)
		{
			if (bArr == nullptr || bArr->Length == 0)
			{
				std::list<char> temp;
				return temp;
			}
			
			int size = Marshal::SizeOf(bArr[0]) * bArr->Length;
			IntPtr pnt = Marshal::AllocHGlobal(size);
			Marshal::Copy(bArr, 0, pnt, size);
			char*  cd = static_cast<char*>(pnt.ToPointer());

			std::list<char> cdata;
			while (cd)
			{
				cdata.push_back(*cd++);
			}
			
			delete cd;
			Marshal::FreeHGlobal(pnt);

			return cdata;
		}
	};
}
#endif