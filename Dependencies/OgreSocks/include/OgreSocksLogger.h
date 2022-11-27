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


namespace OgreSocks
{
	//this class will removed soon as we will use Ogre's logger
	class OgreSocksLogger
	{
	public:
		//public constructor so the sockets can create a private logger
		OgreSocksLogger();
		OgreSocksLogger(Ogre::String name, bool wantComms = true, bool wantLog = true);
		~OgreSocksLogger();

		void Init(Ogre::String name, bool wantComms = true, bool wantLog = true);
		void WantLog(bool wantLog);
		void WantComms(bool wantComms);
		bool WantLog();
		bool WantComms();
		void Log(Ogre::String data);
		Ogre::String LogWinSockErr(Ogre::String text, int errcode);

	protected:
	private:
		fstream mTheSocketLogFile;
		bool m_bWantComms;
		bool m_bWantLog;
		HANDLE m_Mutex;

	//========= FOR TESTING  ============
	private:
		friend class OgreSocksTestManager;
	};
}