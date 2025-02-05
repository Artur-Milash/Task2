#include "Any_type.h"

Any_type::Any_type(const Any_type& obj) : inner_union{ }, type{ NONE } {
	switch (obj.type) {
	case BOOL:
		*this = *obj.inner_union.b;
		break;
	case CHAR:
		*this = *obj.inner_union.ch;
		break;
	case SIGNED_CHAR:
		*this = *obj.inner_union.sch;
		break;
	case UNSIGNED_CHAR:
		*this = *obj.inner_union.uch;
		break;
	case SHORT:
		*this = *obj.inner_union.sh;
		break;
	case UNSIGNED_SHORT:
		*this = *obj.inner_union.ush;
		break;
	case INT:
		*this = *obj.inner_union.i;
		break;
	case UNSIGNED_INT:
		*this = *obj.inner_union.ui;
		break;
	case LONG:
		*this = *obj.inner_union.l;
		break;
	case LONG_LONG:
		*this = *obj.inner_union.ll;
		break;
	case UNSIGNED_LONG:
		*this = *obj.inner_union.ul;
		break;
	case UNSIGNED_LONG_LONG:
		*this = *obj.inner_union.ull;
		break;
	case FLOAT:
		*this = *obj.inner_union.f;
		break;
	case DOUBLE:
		*this = *obj.inner_union.d;
		break;
	}
}
Any_type::Any_type(Any_type&& obj) noexcept : inner_union{}, type{ NONE } {
	switch (obj.type) {
	case BOOL:
		this->inner_union.b = obj.inner_union.b;
		obj.inner_union.b = nullptr;
		obj.type = NONE;
		break;
	case CHAR:
		this->inner_union.ch = obj.inner_union.ch;
		obj.inner_union.ch = nullptr;
		obj.type = NONE;
		break;
	case SIGNED_CHAR:
		this->inner_union.sch = obj.inner_union.sch;
		obj.inner_union.sch = nullptr;
		obj.type = NONE;
		break;
	case UNSIGNED_CHAR:
		this->inner_union.uch = obj.inner_union.uch;
		obj.inner_union.uch = nullptr;
		obj.type = NONE;
		break;
	case SHORT:
		this->inner_union.sh = obj.inner_union.sh;
		obj.inner_union.sh = nullptr;
		obj.type = NONE;
		break;
	case UNSIGNED_SHORT:
		this->inner_union.ush = obj.inner_union.ush;
		obj.inner_union.ush = nullptr;
		obj.type = NONE;
		break;
	case INT:
		this->inner_union.i = obj.inner_union.i;
		obj.inner_union.i = nullptr;
		obj.type = NONE;
		break;
	case UNSIGNED_INT:
		this->inner_union.ui = obj.inner_union.ui;
		obj.inner_union.ui = nullptr;
		obj.type = NONE;
		break;
	case LONG:
		this->inner_union.l = obj.inner_union.l;
		obj.inner_union.l = nullptr;
		obj.type = NONE;
		break;
	case LONG_LONG:
		this->inner_union.ll = obj.inner_union.ll;
		obj.inner_union.ll = nullptr;
		obj.type = NONE;
		break;
	case UNSIGNED_LONG:
		this->inner_union.ul = obj.inner_union.ul;
		obj.inner_union.ul = nullptr;
		obj.type = NONE;
		break;
	case UNSIGNED_LONG_LONG:
		this->inner_union.ull = obj.inner_union.ull;
		obj.inner_union.ull = nullptr;
		obj.type = NONE;
		break;
	case FLOAT:
		this->inner_union.f = obj.inner_union.f;
		obj.inner_union.f = nullptr;
		obj.type = NONE;
		break;
	case DOUBLE:
		this->inner_union.d = obj.inner_union.d;
		obj.inner_union.d = nullptr;
		obj.type = NONE;
		break;
	}
}

Any_type::Any_type() : inner_union{}, type{ NONE } {}

Any_type::Any_type(const bool& value) : inner_union{}, type{ BOOL } { inner_union.b = new bool{ value }; }

Any_type::Any_type(const char& value) : inner_union{}, type{ CHAR } { inner_union.ch = new char{ value }; }
Any_type::Any_type(const signed char& value) : inner_union{}, type{ SIGNED_CHAR } { inner_union.sch = new signed char{ value }; }
Any_type::Any_type(const unsigned char& value) : inner_union{}, type{ UNSIGNED_CHAR } { inner_union.uch = new unsigned char{ value }; }

Any_type::Any_type(const short& value) : inner_union{}, type{ SHORT } { inner_union.sh = new short{ value }; }
Any_type::Any_type(const unsigned short& value) : inner_union{}, type{ UNSIGNED_SHORT } { inner_union.ush = new unsigned short{ value }; }

Any_type::Any_type(const int& value) : inner_union{}, type{ INT } { inner_union.i = new int{ value }; }
Any_type::Any_type(const unsigned int& value) : inner_union{}, type{ UNSIGNED_INT } { inner_union.ui = new unsigned int{ value }; }

Any_type::Any_type(const long& value) : inner_union{}, type{ LONG } { inner_union.l = new long{ value }; }
Any_type::Any_type(const long long& value) : inner_union{}, type{ LONG_LONG } { inner_union.ll = new long long{ value }; }
Any_type::Any_type(const unsigned long& value) : inner_union{}, type{ UNSIGNED_LONG } { inner_union.ul = new unsigned long{ value }; }
Any_type::Any_type(const unsigned long long& value) : inner_union{}, type{ UNSIGNED_LONG_LONG } { inner_union.ull = new unsigned long long{ value }; }

Any_type::Any_type(const float& value) : inner_union{}, type{ FLOAT } { inner_union.f = new float{ value }; }
Any_type::Any_type(const double& value) : inner_union{}, type{ DOUBLE } { inner_union.d = new double{ value }; }

Any_type::~Any_type() {
	destroy();
}

void Any_type::destroy() {
	switch (type) {
	case BOOL:
		if (inner_union.b != nullptr)
			delete inner_union.b;
		break;
	case CHAR:
		if (inner_union.ch != nullptr)
			delete inner_union.ch;
		break;
	case SIGNED_CHAR:
		if (inner_union.sch != nullptr)
			delete inner_union.sch;
		break;
	case UNSIGNED_CHAR:
		if (inner_union.uch != nullptr)
			delete inner_union.uch;
		break;
	case SHORT:
		if (inner_union.sh != nullptr)
			delete inner_union.sh;
		break;
	case UNSIGNED_SHORT:
		if (inner_union.ush != nullptr)
			delete inner_union.ush;
		break;
	case INT:
		if (inner_union.i != nullptr)
			delete inner_union.i;
		break;
	case UNSIGNED_INT:
		if (inner_union.ui != nullptr)
			delete inner_union.ui;
		break;
	case LONG:
		if (inner_union.l != nullptr)
			delete inner_union.l;
		break;
	case LONG_LONG:
		if (inner_union.ll != nullptr)
			delete inner_union.ll;
		break;
	case UNSIGNED_LONG:
		if (inner_union.ul != nullptr)
			delete inner_union.ul;
		break;
	case UNSIGNED_LONG_LONG:
		if (inner_union.ull != nullptr)
			delete inner_union.ull;
		break;
	case FLOAT:
		if (inner_union.f != nullptr)
			delete inner_union.f;
		break;
	case DOUBLE:
		if (inner_union.d != nullptr)
			delete inner_union.d;
		break;
	}
	type = NONE;
}

unsigned short Any_type::get_type() const {
	return type;
}

void Any_type::swap(Any_type& obj) {
	Any_type temp{ obj };

	switch (this->type) {
	case BOOL:
		obj = *inner_union.b;
		break;
	case CHAR:
		obj = *inner_union.ch;
		break;
	case SIGNED_CHAR:
		obj = *inner_union.sch;
		break;
	case UNSIGNED_CHAR:
		obj = *inner_union.uch;
		break;
	case SHORT:
		obj = *inner_union.sh;
		break;
	case UNSIGNED_SHORT:
		obj = *inner_union.ush;
		break;
	case INT:
		obj = *inner_union.i;
		break;
	case UNSIGNED_INT:
		obj = *inner_union.ui;
		break;
	case LONG:
		obj = *inner_union.l;
		break;
	case LONG_LONG:
		obj = *inner_union.ll;
		break;
	case UNSIGNED_LONG:
		obj = *inner_union.ul;
		break;
	case UNSIGNED_LONG_LONG:
		obj = *inner_union.ull;
		break;
	case FLOAT:
		obj = *inner_union.f;
		break;
	case DOUBLE:
		obj = *inner_union.d;
		break;
	}

	switch (temp.get_type()) {
	case BOOL:
		*this = *temp.inner_union.b;
		break;
	case CHAR:
		*this = *temp.inner_union.ch;
		break;
	case SIGNED_CHAR:
		*this = *temp.inner_union.sch;
		break;
	case UNSIGNED_CHAR:
		*this = *temp.inner_union.uch;
		break;
	case SHORT:
		*this = *temp.inner_union.sh;
		break;
	case UNSIGNED_SHORT:
		*this = *temp.inner_union.ush;
		break;
	case INT:
		*this = *temp.inner_union.i;
		break;
	case UNSIGNED_INT:
		*this = *temp.inner_union.ui;
		break;
	case LONG:
		*this = *temp.inner_union.l;
		break;
	case LONG_LONG:
		*this = *temp.inner_union.ll;
		break;
	case UNSIGNED_LONG:
		*this = *temp.inner_union.ul;
		break;
	case UNSIGNED_LONG_LONG:
		*this = *temp.inner_union.ull;
		break;
	case FLOAT:
		*this = *temp.inner_union.f;
		break;
	case DOUBLE:
		*this = *temp.inner_union.d;
		break;
	}
}

bool Any_type::to_bool() const {
	if (type == BOOL) {
		return *inner_union.b;
	}
	throw std::bad_cast();
}

char Any_type::to_char() const {
	if (type == CHAR) {
		return *inner_union.ch;
	}
	throw std::bad_cast();
}
signed char Any_type::to_schar() const {
	if (type == SIGNED_CHAR) {
		return *inner_union.sch;
	}
	throw std::bad_cast();
}
unsigned char Any_type::to_uchar() const {
	if (type == UNSIGNED_CHAR) {
		return *inner_union.ch;
	}
	throw std::bad_cast();
}

short Any_type::to_short() const {
	if (type == SHORT) {
		return *inner_union.sh;
	}
	throw std::bad_cast();
}
unsigned short Any_type::to_ushort() const {
	if (type == UNSIGNED_SHORT) {
		return *inner_union.ush;
	}
	throw std::bad_cast();
}

int Any_type::to_int() const {
	if (type == INT) {
		return *inner_union.i;
	}
	throw std::bad_cast();
}
unsigned int Any_type::to_uint() const {
	if (type == UNSIGNED_INT) {
		return *inner_union.ui;
	}
	throw std::bad_cast();
}

long Any_type::to_long() const {
	if (type == LONG) {
		return *inner_union.l;
	}
	throw std::bad_cast();
}
long long Any_type::to_llong() const {
	if (type == LONG_LONG) {
		return *inner_union.ll;
	}
	throw std::bad_cast();
}
unsigned long Any_type::to_ulong() const {
	if (type == UNSIGNED_LONG) {
		return *inner_union.ul;
	}
	throw std::bad_cast();
}
unsigned long long Any_type::to_ullong() const {
	if (type == UNSIGNED_LONG_LONG) {
		return *inner_union.ull;
	}
	throw std::bad_cast();
}

float Any_type::to_float() const {
	if (type == FLOAT) {
		return *inner_union.f;
	}
	throw std::bad_cast();
}
double Any_type::to_double() const {
	if (type == DOUBLE) {
		return *inner_union.d;
	}
	throw std::bad_cast();
}

void Any_type::operator=(const bool& value) {
	destroy();
	type = BOOL;
	inner_union.b = new bool{ value };
}

void Any_type::operator=(const char& value) {
	destroy();
	type = CHAR;
	inner_union.ch = new char{ value };
}
void Any_type::operator=(const signed char& value) {
	destroy();
	type = SIGNED_CHAR;
	inner_union.sch = new signed char{ value };
}
void Any_type::operator=(const unsigned char& value) {
	destroy();
	type = UNSIGNED_CHAR;
	inner_union.uch = new unsigned char{ value };
}

void Any_type::operator=(const int& value) {
	destroy();
	type = INT;
	inner_union.i = new int{ value };
}
void Any_type::operator=(const unsigned int& value) {
	destroy();
	type = UNSIGNED_INT;
	inner_union.ui = new unsigned int{ value };
}

void Any_type::operator=(const long& value) {
	destroy();
	type = LONG;
	inner_union.l = new long{ value };
}
void Any_type::operator=(const long long& value) {
	destroy();
	type = LONG_LONG;
	inner_union.ll = new long long{ value };
}
void Any_type::operator=(const unsigned long& value) {
	destroy();
	type = UNSIGNED_LONG;
	inner_union.ul = new unsigned long{ value };
}
void Any_type::operator=(const unsigned long long& value) {
	destroy();
	type = UNSIGNED_LONG_LONG;
	inner_union.ull = new unsigned long long{ value };
}

void Any_type::operator=(const float& value) {
	destroy();
	type = FLOAT;
	inner_union.f = new float{ value };
}
void Any_type::operator=(const double& value) {
	destroy();
	type = DOUBLE;
	inner_union.d = new double{ value };
}