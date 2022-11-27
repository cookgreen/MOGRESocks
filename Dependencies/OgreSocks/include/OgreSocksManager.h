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

#include "OgreSocksTCPClient.h"
#include "OgreSocksTCPServer.h"
#include "OgreSocksUDPPeer.h"


namespace OgreSocks
{
	#define TCP_SERVER 1
	#define TCP_CLIENT 2
	#define UDP_PEER   3

	/* WinSock Version (2.2) */
	#define WS_VERSION_REQD	0x0202

	//!  OgreSocksManager class. 
	/*!
		The OgreSocksManager is responsible for creating and deleting OgreSockets. You will never create and delete OgreSockets directly
		using 'new' and 'delete'. The OgreSocksManager class follows the singleton pattern.
	*/
	class OGRESOCKS_DECL OgreSocksManager
	{
	public:
		static OgreSocksManager* GetSingleton();
		void Initialise();
		void CleanUp();
		void CreateSocket(OgreSocksTCPClient*& sock);
		void CreateSocket(OgreSocksTCPServer*& sock, unsigned long port);
		void CreateSocket(OgreSocksTCPServer*& sock, Ogre::String addr, unsigned long port);
		void CreateSocket(OgreSocksUDPPeer*& sock);
		void CreateSocket(OgreSocksUDPPeer*& sock, unsigned long port);
		void CreateSocket(OgreSocksUDPPeer*& sock, Ogre::String addr, unsigned long port);
		void DeleteSocket(OgreSocksTCPClient*& sock);
		void DeleteSocket(OgreSocksTCPServer*& sock);
		void DeleteSocket(OgreSocksUDPPeer*& sock);

		unsigned long GetNumSockets() { return m_SocketList.size(); }
		void SetCreateTimeout(unsigned long& timeout);
		void SetDeleteTimeout(unsigned long& timeout);

	protected:
		//nothing

	private:
	//functions
		void _CreateSocket(int type, Ogre::String addr, int port, OgreSocksBase*& mySock);
		void _DeleteSocket(OgreSocksBase*& mySock);

	//variables
		typedef std::list<OgreSocksBase*> SOCKET_LIST;
		bool			 m_bCleanup;
		bool			 m_bInitialised;
		unsigned int	 m_iAsyncMsgCntr;
		SOCKET_LIST		 m_SocketList;
		OgreSocksLogger* m_Logger;
		unsigned long	 m_lCreateTimeout;
		unsigned long	 m_lDeleteTimeout;

	private:
		//private constructor because this is a singleton class
		OgreSocksManager();
		//~OgreSocksManager();
		static OgreSocksManager* _instance;

	public:
		//functions
		~OgreSocksManager();


	//========= FOR TESTING  ============
	private:
		friend class OgreSocksTestManager;
	};
}