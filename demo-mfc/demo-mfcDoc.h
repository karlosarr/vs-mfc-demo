
// demo-mfcDoc.h: interfaz de la clase CdemomfcDoc
//


#pragma once


class CdemomfcDoc : public CDocument
{
protected: // Crear sólo a partir de serialización
	CdemomfcDoc() noexcept;
	DECLARE_DYNCREATE(CdemomfcDoc)

// Atributos
public:

// Operaciones
public:

// Reemplazos
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementación
public:
	virtual ~CdemomfcDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Función del asistente que establece contenido de búsqueda para un controlador de búsqueda
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
