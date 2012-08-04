// BitSet.cpp: implementation of the CBitSet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BitSet.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBitSet::CBitSet()
{
	m_Bits = NULL;
	m_Size = 16;
	m_Bits = new unsigned int[m_Size];

}

CBitSet::~CBitSet()
{
if(m_Bits) 
		{
			delete m_Bits;
			m_Bits = NULL;
		}
}

void CBitSet::Resize(int Count)
{
		// Get the size of integers we need
		m_Size = Count/32 + 1;

		// Make sure we haven't already allocated memory for the bits
        if(m_Bits) 
		{
			delete m_Bits;
			m_Bits = 0;
		}

		// Allocate the bits and initialize them
		m_Bits = new unsigned int[m_Size];
		Reset();
}

void CBitSet::Set(int I)
{
	m_Bits[I >> 5] |= (1 << (I & 31));
}

int CBitSet::On(int I)
{
	return m_Bits[I >> 5] & (1 << (I & 31 ));
}

void CBitSet::Clear(int I)
{
	m_Bits[I >> 5] &= ~(1 << (I & 31));
}

void CBitSet::Reset()
{
	memset(m_Bits, 0, sizeof(unsigned int) * m_Size);

	
}
