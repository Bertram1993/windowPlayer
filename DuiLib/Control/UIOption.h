#ifndef __UIOPTION_H__
#define __UIOPTION_H__

#pragma once

namespace DuiLib
{
	class UILIB_API COptionUI : public CButtonUI
	{
	public:
		COptionUI();
		~COptionUI();

		virtual void DoPaint(HDC hdc, const RECT&, RECT& rcPaint);
		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		void SetManager(CPaintManagerUI* pManager, CControlUI* pParent, bool bInit = true);

		bool Activate();
		void SetEnabled(bool bEnable = true);

		LPCTSTR GetSelectedImage();
		void SetSelectedImage(LPCTSTR pStrImage);

		LPCTSTR GetSelectedHotImage();
		void SetSelectedHotImage(LPCTSTR pStrImage);

		LPCTSTR GetSelectedPushedImage();
		void SetSelectedPushedImage(LPCTSTR pStrImage);

		void SetSelectedTextColor(DWORD dwTextColor);
		DWORD GetSelectedTextColor();

		void SetSelectedBkColor(DWORD dwBkColor);
		DWORD GetSelectBkColor();

		LPCTSTR GetSelectedForedImage();
		void SetSelectedForedImage(LPCTSTR pStrImage);

		LPCTSTR GetGroup() const;
		void SetGroup(LPCTSTR pStrGroupName = NULL);
		bool IsSelected() const;
		virtual void Selected(bool bSelected);

		SIZE EstimateSize(SIZE szAvailable);
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

		void PaintStatusImage(HDC hDC);
		void PaintText(HDC hDC);

	protected:
		bool			m_bSelected;
		CDuiString		m_sGroupName;

		DWORD			m_dwSelectedBkColor;
		DWORD			m_dwSelectedTextColor;

		CImageAttribute		m_selectedImage;
		CImageAttribute		m_selectedHotImage;
		CImageAttribute		m_selectedPushedImage;
		CImageAttribute		m_selectedForeImage;
	};

} // namespace DuiLib

#endif // __UIOPTION_H__