// [!output WTL_FRAME_FILE].h : interface of the [!output WTL_FRAME_CLASS] class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "LayoutMgr.h"
#include <atlscrl.h>

//{{WTLBUILDER_INCLUDE_DECLARATION
//}}WTLBUILDER_INCLUDE_DECLARATION

//{{WTLBUILDER_CONTROL_ID_DECLARATION
//}}WTLBUILDER_CONTROL_ID_DECLARATION

//{{WTLBUILDER_WINDOW_STYLE
typedef ATL::CFrameWinTraits [!output WTL_FRAME_CLASS]WinTraits;
//}}WTLBUILDER_WINDOW_STYLE

[!if WTL_APPTYPE_TABVIEW]
#define WINDOW_MENU_POSITION	3

[!endif]
class [!output WTL_FRAME_CLASS] : 
[!if WTL_APPTYPE_MDI]
	public [!output WTL_FRAME_BASE_CLASS]<[!output WTL_FRAME_CLASS], CMDIWindow, [!output WTL_FRAME_CLASS]WinTraits>, 
[!else]
	public [!output WTL_FRAME_BASE_CLASS]<[!output WTL_FRAME_CLASS], CWindow, [!output WTL_FRAME_CLASS]WinTraits>, 
[!endif]
[!if !WTL_USE_RIBBON]
	public CUpdateUI<[!output WTL_FRAME_CLASS]>,
[!endif]
	public CScrollImpl<[!output WTL_FRAME_CLASS]>,public LayoutMgr<[!output WTL_FRAME_CLASS]>,
	public CMessageFilter, public CIdleHandler
//{{WTLBUILDER_BASE_CLASS
//}}WTLBUILDER_BASE_CLASS
{
	CToolTipCtrl	m_toolTip;
//{{WTLBUILDER_MEMBER_DECLARATION
//}}WTLBUILDER_MEMBER_DECLARATION

	void InitLayout(void);
	virtual void DefineLayout();
	virtual void DoPaint(CDCHandle /*dc*/);
public:
	virtual void GetOffset(LPPOINT offset);
	virtual void GetDialogRect(LPRECT r);
	static const UINT _controlsToClip[];

//{{WTLBUILDER_WINCLASS_DECLARATION
	DECLARE_FRAME_WND_CLASS(NULL, IDR_MAINFRAME)
//}}WTLBUILDER_WINCLASS_DECLARATION

[!if WTL_APPTYPE_TABVIEW]
	CTabView m_view;
[!endif]
[!if WTL_APPTYPE_EXPLORER]
	CSplitterWindow m_splitter;
	CPaneContainer m_pane;
	CTreeViewCtrl m_treeview;
	[!output WTL_VIEW_CLASS] m_view;
[!endif]
[!if WTL_APPTYPE_SDI || WTL_APPTYPE_MTSDI]
[!if WTL_USE_VIEW]
	[!output WTL_VIEW_CLASS] m_view;
[!endif]
[!endif]
[!if WTL_USE_CMDBAR || WTL_USE_RIBBON]
[!if WTL_APPTYPE_MDI]
	CMDICommandBarCtrl m_CmdBar;
[!else]
	CCommandBarCtrl m_CmdBar;
[!endif]
[!endif]
[!if WTL_VIEWTYPE_LISTBOX || WTL_VIEWTYPE_EDIT || WTL_VIEWTYPE_RICHEDIT]
[!if !WTL_APPTYPE_MDI]
	CFont m_font;
[!endif]
[!endif]
[!if WTL_USE_RIBBON]

	//TODO: Declare ribbon controls

	// Ribbon control map
	BEGIN_RIBBON_CONTROL_MAP(CMainFrame)
	END_RIBBON_CONTROL_MAP()
[!endif]

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnIdle();

[!if !WTL_RIBBON_SINGLE_UI]
	BEGIN_UPDATE_UI_MAP([!output WTL_FRAME_CLASS])
[!if WTL_USE_TOOLBAR]
		UPDATE_ELEMENT(ID_VIEW_TOOLBAR, UPDUI_MENUPOPUP)
[!endif]
[!if WTL_USE_STATUSBAR]
		UPDATE_ELEMENT(ID_VIEW_STATUS_BAR, UPDUI_MENUPOPUP)
[!endif]
[!if WTL_APPTYPE_EXPLORER]
		UPDATE_ELEMENT(ID_VIEW_TREEPANE, UPDUI_MENUPOPUP)
[!endif]
	END_UPDATE_UI_MAP()
[!endif]

[!if WTL_APPTYPE_MDI]
	typedef [!output WTL_FRAME_BASE_CLASS]<[!output WTL_FRAME_CLASS], CMDIWindow, [!output WTL_FRAME_CLASS]WinTraits> _baseClass; 
[!else]
	typedef [!output WTL_FRAME_BASE_CLASS]<[!output WTL_FRAME_CLASS], CWindow, [!output WTL_FRAME_CLASS]WinTraits> _baseClass; 
[!endif]

	BEGIN_MSG_MAP([!output WTL_FRAME_CLASS])
		MESSAGE_HANDLER(WM_SIZE, LayoutMgr<[!output WTL_FRAME_CLASS]>::OnSize)
		MESSAGE_HANDLER(WM_ERASEBKGND, LayoutMgr<[!output WTL_FRAME_CLASS]>::OnEraseBackground)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		COMMAND_ID_HANDLER(ID_APP_EXIT, OnFileExit)
		COMMAND_ID_HANDLER(ID_FILE_NEW, OnFileNew)
[!if WTL_APPTYPE_MTSDI]
		COMMAND_ID_HANDLER(ID_FILE_NEW_WINDOW, OnFileNewWindow)
[!endif]
[!if WTL_USE_TOOLBAR]
		COMMAND_ID_HANDLER(ID_VIEW_TOOLBAR, OnViewToolBar)
[!endif]
[!if WTL_USE_STATUSBAR]
		COMMAND_ID_HANDLER(ID_VIEW_STATUS_BAR, OnViewStatusBar)
[!endif]
[!if WTL_RIBBON_DUAL_UI]
		COMMAND_ID_HANDLER(ID_VIEW_RIBBON, OnViewRibbon)
[!endif]
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
[!if WTL_APPTYPE_MDI]
		COMMAND_ID_HANDLER(ID_WINDOW_CASCADE, OnWindowCascade)
		COMMAND_ID_HANDLER(ID_WINDOW_TILE_HORZ, OnWindowTile)
		COMMAND_ID_HANDLER(ID_WINDOW_ARRANGE, OnWindowArrangeIcons)
[!endif]
[!if WTL_APPTYPE_TABVIEW]
		COMMAND_ID_HANDLER(ID_WINDOW_CLOSE, OnWindowClose)
		COMMAND_ID_HANDLER(ID_WINDOW_CLOSE_ALL, OnWindowCloseAll)
		COMMAND_RANGE_HANDLER(ID_WINDOW_TABFIRST, ID_WINDOW_TABLAST, OnWindowActivate)
[!endif]
[!if WTL_APPTYPE_EXPLORER]
		COMMAND_ID_HANDLER(ID_VIEW_TREEPANE, OnViewTreePane)
		COMMAND_ID_HANDLER(ID_PANE_CLOSE, OnTreePaneClose)
[!endif]
[!if !WTL_USE_RIBBON]
		CHAIN_MSG_MAP(CUpdateUI<[!output WTL_FRAME_CLASS]>)
[!endif]
		CHAIN_MSG_MAP(_baseClass)
	END_MSG_MAP()

  [!output WTL_FRAME_CLASS](void);

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnFileNew(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
[!if WTL_APPTYPE_MTSDI]
	LRESULT OnFileNewWindow(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
[!endif]
[!if WTL_USE_TOOLBAR]
	LRESULT OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
[!endif]
[!if WTL_USE_STATUSBAR]
	LRESULT OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
[!endif]
	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
[!if WTL_APPTYPE_MDI]
	LRESULT OnWindowCascade(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnWindowTile(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnWindowArrangeIcons(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
[!endif]
[!if WTL_APPTYPE_TABVIEW]
	LRESULT OnWindowClose(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnWindowCloseAll(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnWindowActivate(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
[!endif]
};
