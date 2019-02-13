#include "stdafx.h"
#include "UICheckBox.h"

namespace DuiLib
{
	LPCTSTR CCheckBoxUI::GetClass() const
	{
		return _T("CheckBoxUI");
	}

	void CCheckBoxUI::SetCheck(bool bCheck)
	{
		Selected(bCheck);
	}

	bool  CCheckBoxUI::GetCheck() const
	{
		return IsSelected();
	}

	void CCheckBoxUI::DoEvent(TEventUI& event)
	{
		__super::DoEvent(event);
		if (event.Type == UIEVENT_DBLCLICK)
		{
			m_pManager->SendNotify(this, _T("checkboxdbclick"));
			Invalidate();
		}
	}
}
