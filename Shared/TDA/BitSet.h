// BitSet.h: interface for the CBitSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITSET_H__544659DE_F4DC_47E7_8F3E_78406F8D5FCC__INCLUDED_)
#define AFX_BITSET_H__544659DE_F4DC_47E7_8F3E_78406F8D5FCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBitSet  
{

private:

	unsigned int	*m_Bits;
	int				m_Size;

public:

	void Reset();
	void Clear(int I);
	int On(int I);
	void Set(int I);
	void Resize(int Count);
	CBitSet();
	virtual ~CBitSet();

};

#endif // !defined(AFX_BITSET_H__544659DE_F4DC_47E7_8F3E_78406F8D5FCC__INCLUDED_)
