/*
	QMPlay2 is a video and audio player.
	Copyright (C) 2010-2017  Błażej Szczygieł

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published
	by the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SCREENSAVER_HPP
#define SCREENSAVER_HPP

#include <QMap>

class ScreenSaverPriv;

class ScreenSaver
{
	Q_DISABLE_COPY(ScreenSaver)
public:
	ScreenSaver();
	~ScreenSaver();

	void inhibit(int context);
	void unInhibit(int context);

private:
	inline bool inhibitHelper(int context);
	inline bool unInhibitHelper(int context);

	ScreenSaverPriv *m_priv;

	typedef QMap<int, bool> Refs;
	Refs m_refs;
};

#endif // SCREENSAVER_HPP
