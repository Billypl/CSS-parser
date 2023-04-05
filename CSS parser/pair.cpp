#include "pair.h"
#include "algorithm.h"

template<typename T1, typename T2>
pair<T1, T2>::pair(T1 a, T2 b)
	: a(a), b(b) {}

template<typename T1, typename T2>
void pair<T1, T2>::operator=  (const pair<T1, T2>& other)
{
	a = other.a;
	b = other.b;
}

template<typename T1, typename T2>
bool pair<T1, T2>::operator==(const pair<T1, T2>& other) const
{
	return isEqual(other);
}

template<typename T1, typename T2>
bool pair<T1, T2>::operator!=(const pair<T1, T2>& other) const
{
	return !isEqual(other);
}

template<typename T1, typename T2>
bool pair<T1, T2>::isEqual(const pair<T1, T2>& other) const
{
	return (a == other.a) && (b == other.b);
}

template<typename T1, typename T2>
void pair<T1, T2>::swap(pair<T1, T2>& other)
{
	sbl::swap(a, other.a);
	sbl::swap(b, other.b);
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const pair<T1, T2>& p)
{
	std::cout << "(" << p.a << "," << p.b << ")";
	return os;
}


/*

"class basic_ostream<char,struct char_traits<char> > & __cdecl 
	operator<<<class string,class string> ( class basic_ostream<char,struct char_traits<char> > &,
											class pair<class string,class string> const &)"
	referenced in function 
		"public: void __cdecl List<class pair<class string, class string>,8>::print(void)const " CSS parser	E:\Billy\Pulpit\Uczelnia\sem 2\AiSD\Projekt1 - css\CSS parser\CSS parser\Section.obj	1




*/