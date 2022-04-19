#include <string>
#include <iostream>
using namespace std;
class Musician {
public:
	Musician(string name_ = "", string surname_ = "", string patron_ = "");
	void take_place();
	void rehearsal();
	void play();
protected:
	string name;
	string surname;
	string patron;
};
class Conductor: public Musician {
public:
	Conductor(string name_ = "", string surname_ = "", string patron_ = "");
	void rehearsal();
	void play();
};
class Strings: public Musician {
public:
	Strings(string name_ = "", string surname_ = "", string patron_ = "");
	void rehearsal();
};
class Wind : public Musician {
public:
	Wind(string name_ = "", string surname_ = "", string patron_ = "");
	void rehearsal();
};
class Drum : public Musician {
public:
	Drum(string name_ = "", string surname_ = "", string patron_ = "");
};
class Bowed : public Strings {
public:
	Bowed(string name_ = "", string surname_ = "", string patron_ = "");
	void rehearsal();
};
class Triangle: public Drum {
public:
	Triangle(string name_ = "", string surname_ = "", string patron_ = "");
	void take_place();
	void rehearsal();
	void play();
};
class Violinist :public Bowed{
public:
	Violinist(string name_ = "", string surname_ = "", string patron_ = "");
	void take_place();
	void rehearsal();
	void play();
};
class Harphist : public Strings {
	Harphist(string name_ = "", string surname_ = "", string patron_ = "");
public:
	void take_place();
	void rehearsal();
	void play();
};
class Cellist : public Bowed {
public:
	Cellist (string name_ = "", string surname_ = "", string patron_ = "");
	void take_place();
	void rehearsal();
	void play();
};
class Drummer :public Drum {
	Drummer(string name_ = "", string surname_ = "", string patron_ = "");
};
class Flutist :public Wind {
public:
	Flutist(string name_ = "", string surname_ = "", string patron_ = "");
	void take_place();
	void rehearsal();
	void play();
};
class Clarnetist :public Wind {
public:
	Clarnetist(string name_ = "", string surname_ = "", string patron_ = "");
	void take_place();
	void rehearsal();
	void play();
};
template <typename T>
inline string get_spec(T elem) {
	return typeid(elem).name;
}
