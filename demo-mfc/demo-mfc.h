
// demo-mfc.h: archivo de encabezado principal para la aplicación demo-mfc
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'pch.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // Símbolos principales


// CdemomfcApp:
// Consulte demo-mfc.cpp para obtener información sobre la implementación de esta clase
//

class CdemomfcApp : public CWinAppEx
{
public:
	CdemomfcApp() noexcept;


// Reemplazos
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementación
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CdemomfcApp theApp;
