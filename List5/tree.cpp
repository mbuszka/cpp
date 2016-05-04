
#include "tree.h"

tree::tree(const tree& t) :
  pntr{t.pntr}
{
  pntr->refcnt++;
}

void tree::operator = (tree&& t) {
  std::swap(pntr, t.pntr);
/*
  pntr->refcnt--;
  if(pntr->refcnt <= 0) {
    delete pntr;
  }
  pntr = t.pntr;
  pntr->refcnt++;*/
}

void tree::operator = (const tree& t) {
  *this = tree(t);
}

tree::~tree() {
  pntr->refcnt--;
  if(pntr->refcnt <= 0) {
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
  pntr->refcnt--;
  pntr = new trnode(pntr->f, pntr->subtrees, 1);
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
  if (t.functor() == var && t.nrsubtrees() == 0) {
    return val;
  } else {
    tree ret = t;
    for (size_t i = 0; i < t.nrsubtrees(); i++) {
      ret.replacesubtree(i, subst(ret[i], var, val));
    }
    return ret;
  }
}

void tree::replacesubtree(size_t i, const tree& t) {
  if (pntr->subtrees[i].pntr != t.pntr) {
    ensure_not_shared();
    pntr->subtrees[i] = t;
  }
}

void tree::replacefunctor(const std::string& f) {
// if
  ensure_not_shared();
  pntr->f = f;
}


bool operator == (tree t1, tree t2) {
  std::vector<std::pair<tree, tree>> pairs { std::pair<tree, tree> (t1, t2) };
  do {
    std::pair<tree, tree> last = pairs.back();
    if ( last.first.functor() != last.second.functor()) {
      return false;
    } else if (last.first.nrsubtrees() != last.second.nrsubtrees()) {
      return false;
    } else {
      pairs.pop_back();
      for (size_t i = 0; i < last.first.nrsubtrees(); i++) {
        pairs.push_back(std::pair<tree, tree> (last.first[i], last.second[i]));
      }
    }
  } while (!pairs.empty());
  return true;
}

bool operator != (tree t1, tree t2) {
  return !(t1 == t2);
}
