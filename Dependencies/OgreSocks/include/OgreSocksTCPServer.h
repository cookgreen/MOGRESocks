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
#include "OgreSocksCallbacks.h"


namespace OgreSocks
{
	//!  OgreSocksTCPServer class. 
	/*!
		The OgreSocksTCPServer class represents a server socket. You will create a OgreSocksTCPServer object when you want to 
		create a socket that listens on a specific port for client connections. However, you will never directly create a 
		OgreSocksTCPServer socket using 'new'. You will use the OgreSockManager to do this. The OgreSocksTCPServer class extends
		the OgreSocksTCP class and implements the Send and Receive functions that were declared pure virtual in the OgreSocksBase class. 
		The OgreSocksTCPServer class maintains an internal list of client connections, and enables you to send data to all of them,
		or just one.
	*/
	class OGRESOCKS_DECL OgreSocksTCPServer : public OgreSocksTCP
	{
	public:
	//functions
		virtual void Send(std::list<char>  data, Ogre::String addr="", unsigned long port=0);	
		void CloseConnectionTo(Ogre::String addr, unsigned long port);
		inline unsigned long GetNumConnections() { return m_lNumConnections; }
		inline bool IsListening() { return m_bListening; }
		SOCKETDATALIST GetListConnectionData() { return m_listSockData; }

	protected:
	//functions
		//protected constructor because we dont want our users to create sockets directly, they must use the OgreSocksManager class
		OgreSocksTCPServer(Ogre::String addr, unsigned long port, unsigned long msg, unsigned long msgFlags);
		virtual ~OgreSocksTCPServer();
		virtual void _Init(unsigned long timeout);
		virtual void _Reset(unsigned long timeout);
		virtual void _Close(SOCKET sock);
		virtual void _Shutdown(SOCKET sock, bool bInitThisShutdown, bool bInitPreviousShutdown = true);		
		void _Listen();
		void _Accept(Ogre::String& addr, unsigned long& port);
		virtual void _Receive(SOCKET theSock, std::list<char> &data, Ogre::String &addr, unsigned long &port);
		virtual void _Send(SOCKET sock);
		void _SendToAll(std::list<char> data);
		void _SendToOne(std::list<char> data, Ogre::String addr, unsigned long port);
		virtual LONG _WndProc(HWND hwnd, UINT msg, WPARAM wParam, LONG lParam);	

	//variables
		SOCKETDATALIST	m_listSockData;
		bool			m_bListening;
		unsigned long	m_lNumConnections;
		HANDLE			m_ListAccessMutex;

	private:
		//only the OgreSocksManager can create the sockets
		friend class OgreSocksManager;

	//=================================================
	private:
		friend class OgreSocksTestManager;
	};
}