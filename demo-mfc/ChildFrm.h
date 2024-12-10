
// ChildFrm.h: interfaz de la clase CChildFrame
//

#pragma once

class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame() noexcept;

// Atributos
protected:
	CSplitterWndEx m_wndSplitter;
public:

// Operaciones
public:

// Reemplazos
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementación
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Funciones de asignación de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()
};
