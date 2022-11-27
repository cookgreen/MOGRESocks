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

#include "OgreSocksBase.h"
#include "OgreSocksLogger.h"
#include "OgreSocksException.h"


namespace OgreSocks
{
	//!  OgreSocksUDPSocket class. 
	/*!
		The OgreSocksUDPPeer class represents a peer UDP socket. A peer socket is one that is both a client and a server. 
		You will create a OgreSocksUDPPeer object when you want to receive from and/or send to another UDP socket. However, 
		you will never directly create a OgreSocksUDPPeer socket using 'new'. You will use the OgreSockManager to do this. 
		The OgreSocksUDPPeer class extends the OgreSocksBase class and implements the Send and Receive functions that were 
		declared pure virtual in the OgreSocksBase class. 
	*/
	class OGRESOCKS_DECL OgreSocksUDPPeer : public OgreSocksBase
	{
	public:
	//functions
		virtual void Send(std::list<char> data, Ogre::String addr, unsigned long port);
		inline int GetMessageSize() { return m_iMsgSize; }

	protected:
	//functions
		//protected constructor because we dont want our users to create sockets directly, they must use the OgreSocksManager class
		OgreSocksUDPPeer(Ogre::String addr, unsigned long port, unsigned long msg, unsigned long msgFlags);
		virtual ~OgreSocksUDPPeer();
		virtual void _Init(unsigned long timeout);
		virtual void _Close(SOCKET sock);
		virtual void _Reset(unsigned long timeout);
		virtual void _Receive(SOCKET theSock, std::list<char> &data, Ogre::String &addr, unsigned long &port);
		void _Send();
		virtual LONG _WndProc(HWND hwnd, UINT msg, WPARAM wParam, LONG lParam);	

	//vars
		int m_iMsgSize;

	private:
		//only the OgreSocksManager can create the sockets
		friend class OgreSocksManager;

	//=================================================
	private:
		friend class OgreSocksTestManager;
	};
}