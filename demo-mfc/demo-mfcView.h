
// demo-mfcView.h: interfaz de la clase CdemomfcView
//

#pragma once


class CdemomfcView : public CView
{
protected: // Crear sólo a partir de serialización
	CdemomfcView() noexcept;
	DECLARE_DYNCREATE(CdemomfcView)

// Atributos
public:
	CdemomfcDoc* GetDocument() const;

// Operaciones
public:

// Reemplazos
public:
	virtual void OnDraw(CDC* pDC);  // Reemplazado para dibujar esta vista
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementación
public:
	virtual ~CdemomfcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Versión de depuración en demo-mfcView.cpp
inline CdemomfcDoc* CdemomfcView::GetDocument() const
   { return reinterpret_cast<CdemomfcDoc*>(m_pDocument); }
#endif

