// * This file is part of the COLOBOT source code
// * Copyright (C) 2001-2008, Daniel ROUX & EPSITEC SA, www.epsitec.ch
// *
// * This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or
// * (at your option) any later version.
// *
// * This program is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// * GNU General Public License for more details.
// *
// * You should have received a copy of the GNU General Public License
// * along with this program. If not, see  http://www.gnu.org/licenses/.

// autoenergy.h

#ifndef _AUTOENERGY_H_
#define	_AUTOENERGY_H_


#include "auto.h"
#include "misc.h"


class CInstanceManager;
class CD3DEngine;
class CParticule;
class CTerrain;
class CCamera;
class CObject;



enum AutoEnergyPhase
{
	AENP_STOP		= 1,
	AENP_WAIT		= 2,
	AENP_BLITZ		= 3,
	AENP_CREATE		= 4,
	AENP_SMOKE		= 5,
};



class CAutoEnergy : public CAuto
{
public:
	CAutoEnergy(CInstanceManager* iMan, CObject* object);
	~CAutoEnergy();

	void		DeleteObject(BOOL bAll=FALSE);

	void		Init();
	BOOL		EventProcess(const Event &event);
	Error		RetError();

	BOOL		CreateInterface(BOOL bSelect);

	BOOL		Write(char *line);
	BOOL		Read(char *line);

protected:
	void		UpdateInterface(float rTime);

	CObject*	SearchMetal();
	BOOL		SearchVehicle();
	void		CreatePower();
	CObject*	SearchPower();

protected:
	AutoEnergyPhase		m_phase;
	float				m_progress;
	float				m_speed;
	float				m_timeVirus;
	float				m_lastUpdateTime;
	float				m_lastParticule;
	int					m_partiSphere;
};


#endif //_AUTOENERGY_H_
