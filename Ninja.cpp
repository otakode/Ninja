#include "stdafx.h"
#include "Ninja.h"

#include "sources/Game.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	Game game;
	if ( game.Init() )
	{
		game.Run();
		return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}


/*
bool SDx::Update_Time()
{
	// Refresh
	////////////

	// Time
	FLOAT time = STimer::GetSystemTimeEx();
	if ( m_isPause )
	{
		m_elapsedTime = 0.0f;
		m_windowsTime = time;
	}
	else
	{
		// Synchro to 60 fps
		if ( m_settings.synchro )
		{
			m_elapsedTime = time - m_windowsTime;
			if ( m_elapsedTime<0.0167f )
				return false;
			m_windowsTime = time;
		}
		else
		{
			m_elapsedTime = time - m_windowsTime;
			m_windowsTime = time;
		}

		if ( m_elapsedTime>m_maxElapsedTime )
		{
			m_elapsedTime = m_maxElapsedTime;
			if ( m_fpsProof )
			{
				m_fpsProofWinTime = m_windowsTime;
				m_fpsProof = false;
			}
		}
		else
			m_fpsProof = true;

		m_elapsedTime *= m_timeRatio;
		m_engineTime += m_elapsedTime;
	}

	// ID
	m_idFrame++;
	return true;
}
*/