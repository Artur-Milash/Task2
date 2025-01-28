#pragma once
#include <typeinfo>

class Any_type {
private:
	const enum Union_types {
		BOOL,
		CHAR,
		SIGNED_CHAR,
		UNSIGNED_CHAR,
		SHORT,
		UNSIGNED_SHORT,
		INT,
		UNSIGNED_INT,
		LONG,
		LONG_LONG,
		UNSIGNED_LONG,
		UNSIGNED_LONG_LONG,
		FLOAT,
		DOUBLE,
		NONE
	};

	unsigned short type;

	union {
		bool* b;

		char* ch;
		signed char* sch;
		unsigned char* uch;

		short* sh;
		unsigned short* ush;

		int* i;
		unsigned int* ui;

		long* l;
		long long* ll;
		unsigned long* ul;
		unsigned long long* ull;

		float* f;
		double* d;
	} inner_union;
public:
	Any_type(const Any_type&);
	Any_type(Any_type&&) noexcept;

	Any_type();

	Any_type(const bool&);

	Any_type(const char&);
	Any_type(const signed char&);
	Any_type(const unsigned char&);

	Any_type(const short&);
	Any_type(const unsigned short&);

	Any_type(const int&);
	Any_type(const unsigned int&);

	Any_type(const long&);
	Any_type(const long long&);
	Any_type(const unsigned long&);
	Any_type(const unsigned long long&);

	Any_type(const float&);
	Any_type(const double&);

	~Any_type();

	void destroy();

	unsigned short get_type() const;

	void swap(Any_type&);

	bool to_bool() const;

	char to_char() const;
	signed char to_schar() const;
	unsigned char to_uchar() const;

	short to_short() const;
	unsigned short to_ushort() const;

	int to_int() const;
	unsigned int to_uint() const;

	long to_long() const;
	long long to_llong() const;
	unsigned long to_ulong() const;
	unsigned long long to_ullong() const;

	float to_float() const;
	double to_double() const;
	
	void operator=(const bool&);

	void operator=(const char&);
	void operator=(const signed char&);
	void operator=(const unsigned char&);

	void operator=(const int&);
	void operator=(const unsigned int&);

	void operator=(const long&);
	void operator=(const long long&);
	void operator=(const unsigned long&);
	void operator=(const unsigned long long&);

	void operator=(const float&);
	void operator=(const double&);
};