#include "Orchestra.h"
Musician::Musician(string name_, string surname_, string patron_) {
	name = name_;
	surname = surname_;
	patron = patron_;
}
void Musician::print_name() {
	cout << name << " " << surname << " " << patron<<" ";
}
void Musician::take_place() {
	cout << "on the base\n";
}
void Musician::rehearsal() {
	cout << "Is up to play\n";
}
void Musician::play() {
	cout << "is starting to play on ";
}
Musician::~Musician() {
	cout<<get_spec(*this);
	cout << " get out\n";
}

Conductor::Conductor(string name_, string surname_, string patron_) :Musician(name_, surname_, patron_){
	;
}
void Conductor::rehearsal() {
	cout << "Attention please!\n";
}
void Conductor::play() {
	cout << "is starting to conduct\n";
}
Strings::Strings(string name_, string surname_, string patron_):Musician(name_, surname_, patron_) {
	;
}
void Strings::rehearsal() {
	cout << "is taking a tool in left hand\n";
}
Wind::Wind(string name_, string surname_, string patron_) :Musician(name_, surname_, patron_){
	;
}
void Wind::rehearsal() {
	cout << "is soothing suffocation\n";
}
Bowed::Bowed(string name_, string surname_, string patron_) :Strings(name_, surname_, patron_){
	;
}
void Bowed::rehearsal() {
	Strings::rehearsal();
	cout << "taking bow in right hand\n";
}
Drum::Drum(string name_, string surname_, string patron_):Musician(name_, surname_, patron_) {
	;
}
Triangle::Triangle(string name_, string surname_, string patron_): Drum(name_, surname_, patron_){
	;
}
void Triangle::take_place() {
	cout << "Triangle player ";
	Drum::take_place();
}
void Triangle::rehearsal() {
	cout << "Triangle player ";
	Drum::rehearsal();
}
void Triangle::play() {
	cout << "Triangle player ";
	Drum::play();
	cout << "triangle ";
}
Violinist::Violinist(string name_, string surname_, string patron_): Bowed(name_, surname_, patron_) {
	//Bowed(name_, surname_, patron_);
}
void Violinist::rehearsal() {
	cout << "Violinsit ";
	Bowed::rehearsal();

}
void Violinist::take_place() {
	cout << "Violinsit ";
	Musician::take_place();

}
void Violinist::play() {
	cout << "Violinsit ";
	Musician::play();
	cout << "violin ";

}
Harphist::Harphist(string name_, string surname_, string patron_): Strings(name_, surname_, patron_) {
	//Strings(name_, surname_, patron_);
}
void Harphist::rehearsal() {
	cout << "Harphist ";
	Strings::rehearsal();

}
void Harphist::take_place() {
	cout << "Harphist ";
	Musician::take_place();

}
void Harphist::play() {
	cout << "Harphist ";
	Musician::play();
	cout << "harph ";

}
Cellist::Cellist(string name_, string surname_, string patron_): Bowed(name_, surname_, patron_) {
	//Bowed(name_, surname_, patron_);
}
void Cellist::rehearsal() {
	cout << "Cellist ";
	Bowed::rehearsal();

}
void Cellist::take_place() {
	cout << "Cellist ";
	Musician::take_place();

}
void Cellist::play() {
	cout << "Cellist ";
	Musician::play();
	cout << "cell ";

}
Flutist::Flutist(string name_, string surname_, string patron_):Wind(name_, surname_, patron_) {
	;
}
void Flutist::rehearsal() {
	cout << "Flutist ";
	Wind::rehearsal();

}
void Flutist::take_place() {
	cout << "Flutist ";
	Musician::take_place();

}
void Flutist::play() {
	cout << "Flutist ";
	Musician::play();
	cout << "Fluit ";

}
Flutist::~Flutist() {
	cout << get_spec(*this) << " ";
	cout << "get out\n";
}
Clarnetist::Clarnetist(string name_, string surname_, string patron_) :Wind(name_, surname_, patron_){
	;
}
void Clarnetist::rehearsal() {
	cout << "Clarnetist ";
	Wind::rehearsal();

}
void Clarnetist::take_place() {
	cout << "Clarnetist ";
	Musician::take_place();

}
void Clarnetist::play() {
	cout << "Clarnetist ";
	Musician::play();
	cout << "clarnet ";

}
Orchestra::Orchestra(std::vector<Musician*>arr_) {
	arr.resize(arr_.size());
	for (int i = 0; i < arr.size(); ++i) {
		arr[i] = arr_[i];
	}
}
Orchestra::Orchestra() {
	;
}
void Orchestra::rehearsal() {
	for (auto v : arr) {
		v->print_name(); 
		v->rehearsal();
	}

}
void Orchestra::play() {
	for (auto v : arr) {
		v->print_name();
		v->play();
	}

}
void Orchestra::take_place() {
	for (auto v : arr) {
		v->print_name();
		v->take_place();
	}

}
/*void Orchestra::add_mus(string name_, string surname_, string patron_) {
	arr.push_back(&(Musician(name_, surname_, patron_)));
}*/
void Orchestra::add_mus(Musician& t) {
	arr.push_back(&t);
}
void Orhcestra::count_flutist() {

}
