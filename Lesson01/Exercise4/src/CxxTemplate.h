
// Use https://en.cppreference.com/w/cpp for anything you do not understand

/* C and C++ are unique among many languages as they have 4 stages to the
 * compilation process - preprocessor, compilation to assembly, compilation
 * to machine binary, and linking. Note we often think of compilation to
 * binary as including the compilation to assembly as that happens in a
 * single command. The preprocessor directives, beginning the line with a #,
 * are used to weave the different bits of code that will actually be
 * compiled into a single file, apply litteral values that are better
 * expressed as words (e.g. PI), and transform bits of code in-place for
 * efficiency or convenience (a.k.a. macros).
 */

// This is a directive that asks the preprocessor to prevent the same file
// being read more than once in the same translation unit. It is newer syntax.
#pragma once

 /* This is the older method, called an include guard. Like the directive
  * above, it prevents its contents from being read more than once. It works
  * in the same way the following code would:
  * static bool is_not_first = false;
  * if ( ! is_not_first ) {
  *   is_not_first = true;
  *   do_stuff();
  * }
  */
#ifndef CXXTEMPLATE_H_INCLUDED
#define CXXTEMPLATE_H_INCLUDED

#include <string>

// This is a namespace statement. It causes everything inside to have cxxt::
// prepended to their name
namespace cxxt {

  /* Lets create an aggregate type. The following code is called a class
   * declaration. Unless code is placed inline, it is only a statement of the
   * existance of code. When the software is "linked" the code that references
   * (uses) the declarations will be matched with the actual definitions of the
   * code.
   */
  class CxxApplication {
    /* "public" is an access specifier, which are followed by a colon.
     * Everything after an access specifier and before the next access specifier
     * can be used in the specified context. It is like your house. Public is
     * the common area outside of your house for all to see and touch. Protected
     * is inside your house where family and friends can see and use. Private is
     * only you.
     */
  public:

    /* Classes in c++ have constructors. A default one will be made if you do
     * not make it yourself. Here we have the first example of a pointer
     * represented by an asterisk. Pointers hold the address in memory of
     * something of value with the preceding type. In this case argv is an
     * array of unknown length of addresses/pointers to characters, char.
     */
    CxxApplication( int argc, char *argv[] );

    ~CxxApplication();
  }; // note the semicolon following the class declaration

  // The following unnecessary structured code but would be more useful in a
  // complex program.

  class VirtualWorker {
  public:
    virtual void prepare();
    virtual bool doWork( const std::string &task ) = 0;
  };

  class WorkerA : public VirtualWorker {
    bool doWork( const std::string &task ) override;
  };

  class WorkerB : public VirtualWorker {
    void prepare() override;
    bool doWork( const std::string &task ) override;
  };

} // namespace vic

#endif // VICTORIA_H_INCLUDED