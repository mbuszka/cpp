
#include "tree.h"

tree::tree(const tree& t) :
  pntr{t.pntr}
{
  pntr->refcnt++;
}

void tree::operator = (tree&& t) {
  this->pntr = std::move(t.pntr);
}

void tree::operator = (const tree& t) {
  tree tmp = tree(t);
  *this = std::move(tmp);
}

tree::~tree() {
  if(--(this->pntr->refcnt) <= 0) delete this->pntr;
}

// const std::string& functor
