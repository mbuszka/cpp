
#include "tree.h"

tree::tree(const tree& t) :
  pntr{t.pntr}
{
  pntr->refcnt++;
}

void tree::operator = (tree&& t) {
  pntr->refcnt--;
  if(pntr->refcnt <= 0) {
    // std::cout << "freeing\n";
    delete pntr;
  }
  pntr = t.pntr;
  pntr->refcnt++;
}

void tree::operator = (const tree& t) {
  *this = tree(t);
}

tree::~tree() {
  // std::cout << "destructor of " << pntr->f << "\n";
  pntr->refcnt--;
  if(pntr->refcnt <= 0) {
    // std::cout << "freeing\n";
    delete pntr;
  }
}

const std::string& tree::functor() const {
  return pntr->f;
}
/*
std::string& tree::functor() {
  ensure_not_shared();
  return pntr->f;
}
*/
const tree& tree::operator[] (size_t i) const {
  return pntr->subtrees[i];
}
/*
tree& tree::operator[] (size_t i) {
  ensure_not_shared();
  return pntr->subtrees[i];
}
*/
size_t tree::nrsubtrees() const {
  return pntr->subtrees.size();
}

std::ostream& operator<< (std::ostream& s, const tree& t) {
  size_t childnr = t.nrsubtrees();
  // s << "(" << t.functor() << ", " << t.pntr->refcnt << " )";
  s << t.functor();
  if (childnr > 0) {
    s << ":[";
    for (size_t i = 0; i < childnr; i++) {
      s << t[i] << (i == childnr - 1 ? "" : ", ");
    }
    s << ']';
  }
  return s;
}

void tree::ensure_not_shared() {
  if (pntr->refcnt == 1) return;
  trnode* tmp = pntr;
  tmp->refcnt--;
  pntr = new trnode(tmp->f, tmp->subtrees, 1);
  for (size_t i = 0; i < nrsubtrees(); i++) {
    pntr->subtrees[i].ensure_not_shared();
  }
}

void tree::ensure_not_shared(size_t i) {
  if (pntr->refcnt == 1) return;
  pntr->refcnt--;
  pntr = new trnode(pntr->f, pntr->subtrees, 1);
  pntr->subtrees[i].ensure_not_shared();
}

tree subst(const tree& t, const std::string& var, const tree& val) {
  /*
  tree ret = t;
  if (t.functor() == var && t.nrsubtrees() == 0) {
    ret = val;
  } else {
    for (size_t i = 0; i < t.nrsubtrees(); i++) {
      ret[i] = subst(t[i], var, val);
    }
  }
  return ret;
  */
  tree ret = t;
  if (t.functor() == var && t.nrsubtrees() == 0) {
    ret = val;
  } else {
    for (size_t i = 0; i < t.nrsubtrees(); i++) {
      ret.replacesubtree(i, subst(ret[i], var, val));
    }
  }
  return ret;
}

void tree::replacesubtree(size_t i, const tree& t) {
  if (pntr->subtrees[i].pntr != t.pntr) {
    ensure_not_shared(i);
    pntr->subtrees[i] = t;
  }
}

void tree::replacefunctor(const std::string& f) {
  ensure_not_shared();
  pntr->f = f;
}
