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

#include "OgreSocksTCP.h"
#include "OgreSocksLogger.h"
#include "OgreSocksException.h"
#include "OgreSocksThunkThreadFireCallback.h"


namespace OgreSocks
{
	const static int CONNERR_OK			= 1;
	const static int CONNERR_WAIT		= 2;
	const static int CONNERR_NOTCONN	= 3;
	const static int CONNERR_REFUSED	= 4;
	const static int CONNERR_TIMEOUT	= 5;
	const static int CONNERR_ADDREXISTS	= 6;
	const static int CONNERR_WINSOCK	= 7;

	//!  OgreSocksTCPClient class. 
	/*!
		The OgreSocksTCPClient class represents a client socket. You will create a OgreSocksTCPClient object when you want to 
		connect to a TCP server. However, you will never directly create a OgreSocksTCPClient socket using 'new'. You will use the 
		OgreSockManager to do this. The OgreSocksTCPClient class extends the OgreSocksTCP class and implements the Send and Receive
		functions that were declared pure virtual in the OgreSocksBase class. It also adds the Connect function, which enables you 
		to connect, and receive notification of this connection, to TCP server sockets.
	*/
	class OGRESOCKS_DECL OgreSocksTCPClient : public OgreSocksTCP
	{
	public:
	//functions
		int Connect(Ogre::String addr, unsigned long port);
		virtual void Send(std::list<char>  data, Ogre::String addr="", unsigned long port=0);

	protected:
	//functions
		//protected constructor because we dont want our users to create sockets directly, they must use the OgreSocksManager class
		OgreSocksTCPClient(Ogre::String addr, unsigned long port, unsigned long msg, unsigned long msgFlags);
		virtual ~OgreSocksTCPClient();
		virtual void _Shutdown(SOCKET sock, bool bInitThisShutdown, bool bInitPreviousShutdown = true);
		virtual void _Close(SOCKET sock);
		virtual void _Init(unsigned long timeout);
		virtual void _Reset(unsigned long timeout);
		virtual void _Receive(SOCKET theSock, std::list<char> &data, Ogre::String &addr, unsigned long &port);
		virtual void _Send(SOCKET sock = NULL);
		virtual LONG _WndProc(HWND hwnd, UINT msg, WPARAM wParam, LONG lParam);	

	//variables
		int m_iConnectErr;

	private:
		//only the OgreSocksManager can create the sockets
		friend class OgreSocksManager;

	//=================================================
	private:
		friend class OgreSocksTestManager;
	};
}