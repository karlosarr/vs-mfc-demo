
// demo-mfcView.cpp: implementación de la clase CdemomfcView
//

#include "pch.h"
#include "framework.h"
// Se pueden definir SHARED_HANDLERS en un proyecto ATL implementando controladores de vista previa, miniatura
// y filtro de búsqueda, y permiten compartir código de documentos con ese proyecto.
#ifndef SHARED_HANDLERS
#include "demo-mfc.h"
#endif

#include "demo-mfcDoc.h"
#include "demo-mfcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdemomfcView

IMPLEMENT_DYNCREATE(CdemomfcView, CView)

BEGIN_MESSAGE_MAP(CdemomfcView, CView)
	// Comandos de impresión estándar
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CdemomfcView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Construcción o destrucción de CdemomfcView

CdemomfcView::CdemomfcView() noexcept
{
	// TODO: agregar aquí el código de construcción

}

CdemomfcView::~CdemomfcView()
{
}

BOOL CdemomfcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modificar aquí la clase Window o los estilos cambiando
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Dibujo de CdemomfcView

void CdemomfcView::OnDraw(CDC* /*pDC*/)
{
	CdemomfcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: agregar aquí el código de dibujo para datos nativos
}


// Impresión de CdemomfcView


void CdemomfcView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CdemomfcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Preparación predeterminada
	return DoPreparePrinting(pInfo);
}

void CdemomfcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar inicialización adicional antes de imprimir
}

void CdemomfcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: agregar limpieza después de imprimir
}

void CdemomfcView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CdemomfcView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Diagnósticos de CdemomfcView

#ifdef _DEBUG
void CdemomfcView::AssertValid() const
{
	CView::AssertValid();
}

void CdemomfcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdemomfcDoc* CdemomfcView::GetDocument() const // La versión de no depuración está alineada
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdemomfcDoc)));
	return (CdemomfcDoc*)m_pDocument;
}
#endif //_DEBUG


// Controladores de mensajes de CdemomfcView
