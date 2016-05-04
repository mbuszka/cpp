
#include "matching.h"


std::list< matching > match( tree from, tree into )
{
  // std::cout << "matching " << from << " into " << into << "\n";

  matching m;
  std::vector<std::pair<tree, tree>> pairs({std::pair<tree, tree>(from, into)});
  do {
    std::pair<tree, tree> last = pairs.back();
    pairs.pop_back();
    if (m.isvariable(last.first.functor()) && last.first.nrsubtrees() == 0) {
      if (!m.isdefined(last.first.functor())) {
        m.assign(last.first.functor(), last.second);
      } else if (!(m(last.first) == last.second)) {
        return std::list<matching>();
      }
      continue;
    }
    if ( last.first.functor() != last.second.functor())
       return std::list<matching>();
    if (last.first.nrsubtrees() != last.second.nrsubtrees())
      return std::list<matching>();
    for (size_t i = 0; i < last.first.nrsubtrees(); i++) {
       pairs.push_back(std::pair<tree, tree> (last.first[i], last.second[i]));
    }
  } while (!pairs.empty());

  // Success: return { m };
  // Failure: return { };
  return std::list<matching> ({m});
}

tree matching::operator() (const tree& t) const {
  if (isvariable(t.functor())) {
    //subst.find(t.functor());
    if (isdefined(t.functor()))
      return subst.at(t.functor());
    else
      throw std::runtime_error("unnknown variable");
  } else {
    tree ret = t;
    for (size_t i = 0; i < t.nrsubtrees(); i++) {
      ret.replacesubtree(i, (*this)(ret[i]));
    }
    return ret;
  }
}

std::ostream& operator << ( std::ostream& out, const matching& m )
{
   out << "matching: ";
   for( const auto& p : m. subst )
   {
      out << p. first << " := " << p. second << "\n";
   }
   return out;
}
