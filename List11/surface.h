#include "surf.h"


struct surface {
  surf* ref;
  surface( const surface& s ) : ref{s.ref->clone()} {}
  surface( surface&& s ) : ref{std::move(*s.ref).clone()} {}
  surface( const surf& s ) : ref{s.clone()} {}
  surface( surf&& s ) : ref{std::move(s).clone()} {}
  void operator = ( const surface& s ) {delete ref; ref = s.ref->clone();}
  void operator = ( surface&& s ) {delete ref; ref = s.ref;}
  void operator = ( const surf& s ) {delete ref; ref = s.clone();}
  void operator = ( surf&& s ) {delete ref; ref = &s;}
  ~surface( ) {
    delete ref;
  }
  const surf& getsurf( ) const { return *ref; }
  // There is no non-const access, because
  // changing would be dangerous
};

std::ostream& operator << ( std::ostream& stream, const surface& s ) {
  s.ref->print(stream);
  return stream;
}
