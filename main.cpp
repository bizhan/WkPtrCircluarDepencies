#include <iostream>
#include <memory>
using namespace std;
struct Son;
struct Daughter;

struct Mother{
  ~Mother() {
    cout<< "Mother gone"<<endl;
  }
// Here we define weak_ptr although we pass share_ptr
  void setSon(const weak_ptr<Son> s){
    mySon=s;
  }
// Here we define shared_ptr, same result as above.
  void setDaughter(const shared_ptr<Daughter> d){
    myDaughter=d;
  }
  weak_ptr<Son> mySon;
  weak_ptr<Daughter> myDaughter;
};

struct Son{
Son(shared_ptr<Mother> m): myMother(m){}
~Son() {
  cout<<"Son gone"<<endl;
}
shared_ptr<Mother> myMother;
};

struct Daughter{
Daughter(shared_ptr<Mother> m): myMother(m){}
~Daughter() {
  cout<<"Daughter gone"<<endl;
}
shared_ptr<Mother> myMother;
};


int main() {
  auto mother = make_shared<Mother>();
  auto son = make_shared<Son>(mother);
  auto daughter = make_shared<Daughter>(mother);
  mother->setSon(son);
  cout<<"Test"<<endl;
  mother->setDaughter(daughter);
}