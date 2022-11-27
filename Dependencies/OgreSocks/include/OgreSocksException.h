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

namespace OgreSocks
{
	enum EOGRESOCK_EXCEPTION_CODE 
	{
		OGRESOCK_ERR_WINSOCK = 1000,
		OGRESOCK_ERR_BAD_ADDRESS,
		OGRESOCK_ERR_WAIT,
		OGRESOCK_ERR_FAIL,
        OGRESOCK_ERR_INVALID_HANDLE,
		OGRESOCK_ERR_SHUTDOWN,
	    OGRESOCK_ERR_TIMEOUT,
		OGRESOCK_ERR_SOCK_NOT_FOUND,
		OGRESOCK_ERR_ALREADY_INIT,
		OGRESOCK_ERR_ALREADY_CONN,
		OGRESOCK_ERR_CLEANUP,
		OGRESOCK_ERR_NO_REMOTE_CONN,
		OGRESOCK_ERR_NOT_CONN,
		OGRESOCK_ERR_NOT_INIT,
		OGRESOCK_ERR_ADDRESS_EXISTS,
		OGRESOCK_ERR_BAD_SOCK_TYPE
    };

	//!  OgreSocksException class. 
	/*!
		The OgreSocksException class inherits from Ogre's Exception class. The numbers are as follows:

		OGRESOCK_ERR_WINSOCK			= 1000
		OGRESOCK_ERR_BAD_ADDRESS		= 1001
		OGRESOCK_ERR_WAIT				= 1002
		OGRESOCK_ERR_FAIL				= 1003
        OGRESOCK_ERR_INVALID_HANDLE		= 1004
		OGRESOCK_ERR_SHUTDOWN			= 1005
	    OGRESOCK_ERR_TIMEOUT			= 1006
		OGRESOCK_ERR_SOCK_NOT_FOUND		= 1007
		OGRESOCK_ERR_ALREADY_INIT		= 1008
		OGRESOCK_ERR_ALREADY_CONN		= 1009
		OGRESOCK_ERR_CLEANUP			= 1010
		OGRESOCK_ERR_NO_REMOTE_CONN		= 1011
		OGRESOCK_ERR_NOT_CONN			= 1012
		OGRESOCK_ERR_NOT_INIT			= 1013
		OGRESOCK_ERR_ADDRESS_EXISTS		= 1014
		OGRESOCK_ERR_BAD_SOCK_TYPE		= 1015

		Because OgreSocksException inherits from Ogre's Exception class, you should catch OgreSocksException before Ogre::Exception. 
	*/
	class OGRESOCKS_DECL OgreSocksException : public Ogre::Exception
	{
	public:
		OgreSocksException(int number, const Ogre::String& description, const Ogre::String& source, const char* file, long line);
	protected:
	private:
		 
	};
}
