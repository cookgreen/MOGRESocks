/*
	Copyright 2008 Paul Turnbull

	This file is part of OgreSocks.

    OgreSocks is free software; you can redistribute it and/or modify it under
	the terms of the GNU Lesser General Public License as published by the Free Software
	Foundation; either version 2 of the License, or (at your option) any later
	version.

	This program is distributed in the hope that it will be useful, but WITHOUT
	ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
	FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License along with
	this program; if not, write to the Free Software Foundation, Inc., 59 Temple
	Place - Suite 330, Boston, MA 02111-1307, USA, or go to
	http://www.gnu.org/copyleft/lesser.txt.
*/

#pragma once

#include "stdafx.h"
#include "Ogre.h"
#include <list>


namespace OgreSocks
{
	//this struct will be revised soon. too many public members and udp doesnt even 
	//require half of them
	struct OgreSocksConnData
	{
		SOCKET			sock;
		SOCKADDR_IN		sockAddr;
		SOCKADDR_IN		sockAddrRemote;
		Ogre::String	strAddr;
		unsigned long	ulPort;
		bool			bConnected;//udp ?
		std::list<char>	listSend;
		unsigned long	lBytesToSend;
		unsigned long	lLastNumBytesSent;
		unsigned long	lLastNumTriesToSend;//udp ?
		bool			bRetryingSend;
		unsigned long	lTotalBytesSent;
		std::list<char> listReceive;
		unsigned long	lLastNumBytesReceived;
		unsigned long	lTotalBytesReceived;
		bool			bInitShutdown;
		std::list<char> listLastSent;

		// define overloaded == operator
		bool operator==(const OgreSocksConnData &other) const
		{
			if(sock == other.sock)
			{
				return true;
			}
			return false;
		}

		OgreSocksConnData()
		{
			sock					= INVALID_SOCKET;
			memset(&sockAddr, 0, sizeof(sockAddr));
			memset(&sockAddrRemote, 0, sizeof(sockAddrRemote));
			strAddr					= "";
			ulPort					= 0;
			bConnected				= false;
			listSend.clear();
			listReceive.clear();
			lLastNumBytesSent		= 0;
			lBytesToSend			= 0;	
			lLastNumTriesToSend		= 0;
			bRetryingSend			= false;
			lLastNumBytesReceived	= 0;
			lTotalBytesSent			= 0;
			lTotalBytesReceived		= 0;
			bInitShutdown			= false;
			listLastSent.clear();
		}

		void empty()
		{
			sock					= INVALID_SOCKET;
			memset(&sockAddr, 0, sizeof(sockAddr));
			memset(&sockAddrRemote, 0, sizeof(sockAddrRemote));
			strAddr					= "";
			ulPort					= 0;
			bConnected				= false;
			listSend.clear();
			listReceive.clear();
			lLastNumBytesSent		= 0;
			lBytesToSend			= 0;	
			lLastNumTriesToSend		= 0;
			bRetryingSend			= false;
			lLastNumBytesReceived	= 0;
			lTotalBytesSent			= 0;
			lTotalBytesReceived		= 0;
			bInitShutdown			= false;
			listLastSent.clear();
		}

		void ResetSendData()
		{
			listSend.clear();
			lLastNumBytesSent	= 0;
			lBytesToSend		= 0;
			lLastNumTriesToSend	= 0;
			bRetryingSend		= false;
			listLastSent.clear();
		}

		void ResetReceiveData()
		{
			listReceive.clear();
			lLastNumBytesReceived	= 0;
		}
	};

	#define SOCKETDATALIST list<OgreSocksConnData>
	#define SOCKDATALIST_ITER SOCKETDATALIST::iterator
}
