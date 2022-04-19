#include "Orchestra.h"
Musician::Musician(string name_, string surname_, string patron_) {
	name = name_;
	surname = surname_;
	patron = patron_;
}
void Musician::take_place() {
	cout << "on the base\n";
}
void Musician::rehearsal() {
	cout << "Is up to play\n";
}
void Musician::play() {
	cout << "is starting to play on\n";
}
Conductor::Conductor(string name_, string surname_, string patron_) {
	Musician(name_, surname_, patron_);
}
void Conductor::rehearsal() {
	cout << "Attention please!\n";
}
void Conductor::play() {
	cout << "is starting to conduct\n";
}
Strings::Strings(string name_, string surname_, string patron_) {
	Musician(name_, surname_, patron_);
}
void Strings::rehearsal(){
	cout << "is taking a tool in left hand\n";
}
Wind::Wind(string name_, string surname_, string patron_) {
	Musician(name_, surname_, patron_);
}
void Wind::rehearsal() {
	cout << "is soothing suffocation\n";
}
Bowed::Bowed(string name_, string surname_, string patron_) {
	Strings(name_, surname_, patron_);
}
void Bowed::rehearsal() {
	Strings::rehearsal();
	cout << "taking bow in right hand\n";
}
Drum::Drum(string name_, string surname_, string patron_) {
	Musician(name_, surname_, patron_);
}
Triangle::Triangle(string name_, string surname_, string patron_) {
	Drum(name_, surname_, patron_);
}
void Triangle::take_place(){
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
}
Violinist::Violinist(string name_, string surname_, string patron_) {
	Bowed(name_, surname_, patron_);
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

}
Harphist::Harphist(string name_, string surname_, string patron_) {
	Strings(name_, surname_, patron_);
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
	cout << "Violinsit ";
	Musician::play();

}
Cellist::Cellist(string name_, string surname_, string patron_) {
	Bowed(name_, surname_, patron_);
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

}
Flutist::Flutist(string name_, string surname_, string patron_) {
	Wind(name_, surname_, patron_);
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

}
Clarnetist::Clarnetist(string name_, string surname_, string patron_) {
	Wind(name_, surname_, patron_);
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

}


