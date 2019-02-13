#ifndef _DUILIB_DROP_DROPTARGETEX_H_
#define _DUILIB_DROP_DROPTARGETEX_H_ 
#pragma once

#include <comdef.h> 
#include <Shlwapi.h>
#include <ShObjIdl.h>
#include <ShlGuid.h>


class IDuiDropTarget
{
public:
	virtual   HRESULT OnDragEnter(IDataObject *pDataObj, DWORD grfKeyState, POINTL ptl, DWORD *pdwEffect) = 0;
	virtual HRESULT  OnDragOver(DWORD grfKeyState, POINTL pt, DWORD *pdwEffect) = 0;
	virtual HRESULT  OnDragLeave() = 0;
	virtual HRESULT  OnDrop(IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, DWORD *pdwEffect) = 0;
};

class CDropTargetEx : public IDropTarget
{
public:
	CDropTargetEx();
	~CDropTargetEx();
public:
	bool DragDropRegister(IDuiDropTarget* pDuiDropTarget, HWND hWnd, DWORD AcceptKeyState = MK_LBUTTON);
	bool DragDropRevoke(HWND hWnd);
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, __RPC__deref_out void **ppvObject);
	ULONG STDMETHODCALLTYPE AddRef();
	ULONG STDMETHODCALLTYPE Release();
	//进入  
	HRESULT STDMETHODCALLTYPE DragEnter(__RPC__in_opt IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, __RPC__inout DWORD *pdwEffect);
	//移动  
	HRESULT STDMETHODCALLTYPE DragOver(DWORD grfKeyState, POINTL pt, __RPC__inout DWORD *pdwEffect);
	//离开  
	HRESULT STDMETHODCALLTYPE DragLeave();
	//释放  
	HRESULT STDMETHODCALLTYPE Drop(__RPC__in_opt IDataObject *pDataObj, DWORD grfKeyState, POINTL pt, __RPC__inout DWORD *pdwEffect);
private:
	HWND m_hWnd;
	IDropTargetHelper* m_piDropHelper;
	bool    m_bUseDnDHelper;
	DWORD m_dAcceptKeyState;
	ULONG  m_lRefCount;
	IDuiDropTarget* m_pDuiDropTarget;
};

#endif//_DUILIB_DROP_DROPTARGETEX_H_